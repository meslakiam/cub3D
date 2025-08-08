/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bann <oel-bann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 22:50:28 by oel-bann          #+#    #+#             */
/*   Updated: 2025/08/06 11:40:21 by oel-bann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void render_floor_and_sky()
{
    int x;
    int y;

    x = 0;
    y = 0;
    while (y < v_global()->win_height)
    {
        x = 0;
        while (x < v_global()->win_width)
        {
            if (y > v_global()->win_height / 2)
                my_mlx_pixel_put(v_global()->win_img, x, y, get_map_info()->f_rgb_tab[0] << 16 | get_map_info()->f_rgb_tab[1] << 8 | get_map_info()->f_rgb_tab[2]);
            else
                my_mlx_pixel_put(v_global()->win_img, x, y, get_map_info()->c_rgb_tab[0] << 16 | get_map_info()->c_rgb_tab[1] << 8 | get_map_info()->c_rgb_tab[2]);
            x++;
        }
        y++;
    }
    
}

void    draw_pixel_depend_distance(int y, int x, int color)
{
    t_data  *data;
    char *tmp;
    char *ch;
    double dis;
    double dis_max;
    double opacity;

    dis_max = sqrt((get_map_info()->win_w * TILESIZE) * (get_map_info()->win_w * TILESIZE) +  (get_map_info()->win_h * TILESIZE) * (get_map_info()->win_w * TILESIZE)) - 80;
    dis = distance(v_player()->end_p_x, v_player()->end_p_y);
    opacity = 1 -  dis / dis_max * dis / dis_max;
    data = v_global()->win_img;
    tmp = data->addr + ((y * data->line_length) + (x * (data->bits_per_pixel / 8)));
    color = blend_colors(*(unsigned int *)tmp, color, opacity);
    *(unsigned int *)tmp = color;
}

int get_wall_texture()
{
    int tex_id;

    tex_id = 0;
    if (v_player()->was_hit_vertical)
    {
        if (v_player()->end_p_x > v_player()->p_x)
            tex_id = TEX_WEST;
        else
            tex_id = TEX_EAST;
    }
    else
    {
        if (v_player()->end_p_y > v_player()->p_y)
            tex_id = TEX_SOUTH;
        else
            tex_id = TEX_NORTH;
    }
    return (tex_id);
}

int get_wall_strip_hight(double r_angle)
{
     int wall_strip_hight;
    double correct_dis;
    double radian;

    radian = (r_angle - v_player()->rotation_angle) * (M_PI / 180.0);
    correct_dis = cos(radian) * distance(v_player()->end_p_x, v_player()->end_p_y);
    wall_strip_hight = 50000/ correct_dis;
}

t_data *get_animation_wall(int set, int wall_tex)
{
    static t_data *west_torch_wall;
    static t_data *east_torch_wall;

    if (set == 1)
    {
        west_torch_wall = &get_west_torch_lst()->content;
        east_torch_wall = &get_east_torch_lst()->content;
    }
    if (is_map_corners() == TEX_EAST)
        return (east_torch_wall);
    else if (is_map_corners() == TEX_WEST)
        return (west_torch_wall);
    return (get_textures(wall_tex));
}

void render(int ray_index, double ray_angle)
{
    int wall_strip_hight;
    double  start_y;
    double  end_y;
    double  img_start_h;
    double  img_end_h;
    int     wall_tex;
    double  step;
    int color;

    int corner = is_map_corners();
    wall_tex = get_wall_texture();
    wall_strip_hight = get_wall_strip_hight(ray_angle);
    start_y = (v_global()->win_img->img_height / 2)  - (wall_strip_hight / 2);
    end_y = start_y + wall_strip_hight;
    img_start_h = get_tex_start(start_y, end_y, wall_tex, corner);
    step = get_tex_step(wall_tex, corner,(end_y - start_y));
    if (start_y < 0)
        start_y = 0;
    if (end_y > v_global()->win_height)
        end_y = v_global()->win_height;
    while (start_y < end_y)
    {
        color = my_mlx_get_pixel_color(get_animation_wall(0, wall_tex), get_img_start_w(get_animation_wall(0, wall_tex)->img_width), img_start_h);
        draw_pixel_depend_distance(start_y, ray_index, color);
        img_start_h += step;
        start_y++;
    }
}