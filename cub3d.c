/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 13:23:56 by imeslaki          #+#    #+#             */
/*   Updated: 2025/08/12 15:35:12 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void fill_data(void)
{
	t_global *data;

	data = v_global();
    data->win_img = ft_malloc(sizeof(t_data));
    data->map_img = ft_malloc(sizeof(t_data));

	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, window_width, window_height, "CUBE3D");
    data->win_img->img_width = window_width;
    data->win_img->img_height = window_height;
    
    data->map_img->img_width = get_map_info()->win_w * TILESIZE;
    data->map_img->img_height = get_map_info()->win_h * TILESIZE;
    
	data->win_img->img = mlx_new_image(data->mlx, data->win_img->img_width, data->win_img->img_height);
	data->win_img->addr = mlx_get_data_addr(data->win_img->img, &data->win_img->bits_per_pixel, &data->win_img->line_length, &data->win_img->endian);
    
    data->map_img->img = mlx_new_image(data->mlx, data->map_img->img_width, data->map_img->img_height);
	data->map_img->addr = mlx_get_data_addr(data->map_img->img, &data->map_img->bits_per_pixel, &data->map_img->line_length, &data->map_img->endian);
}

void    cast_rays_and_render_game(void)
{
    t_ray_info  ray;
    t_global	*data;
	t_data		*shrinked_map;
    int         i; 

    i = 0;
    data = v_global();
    ray = get_ray_info();
    while (i < ray.num_of_rays)
    {
        ray_casting_update_p(ray.ray_angle);
        // ray_casting(ray.ray_angle);
        draw_line(round(v_player()->p_x), round(v_player()->p_y), round(v_player()->end_p_x) , round(v_player()->end_p_y) , 0x00FF0000);
        render(i, ray.ray_angle);
        ray.ray_angle += (double)FOV / (double)ray.num_of_rays;
        i++;
    }
    shrinked_map = mlx_shrink_img(data->map_img, v_global()->map_img->img_width / 2, v_global()->map_img->img_height / 2);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->win_img->img, 0, 0);
    // mlx_put_image_to_window(data->mlx, data->mlx_win, data->map_img->img, 0, 0);
}


long current_milliseconds(void)
{
    struct timeval tv;

    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000L) + (tv.tv_usec / 1000L);
}

void    mouse_check(void)
{
    if(current_milliseconds() - v_global()->last_update_time > 10)
        v_global()->mouse_direction = 0;
    if(v_global()->check_mouse_sides != 0)
    {
        if(current_milliseconds() -  v_global()->last_update_time > 10 && (v_global()->mouse_move == window_width - 2
        || v_global()->mouse_move == window_width - 1 || v_global()->mouse_move == window_width - 3
        || v_global()->mouse_move == window_width - 4 || v_global()->mouse_move == window_width - 5
        || v_global()->mouse_move == window_width))
            v_global()->mouse_direction = 1;
        else if(current_milliseconds() -  v_global()->last_update_time > 10 && (v_global()->mouse_move == 0
        || v_global()->mouse_move == 1|| v_global()->mouse_move == 2
        || v_global()->mouse_move == 3 || v_global()->mouse_move == 4))
            v_global()->mouse_direction = -1;
    }
}

int create_game(void)
{
    // frames();
    mouse_check();
    render_floor_and_sky();
    move_the_player();
    cast_rays_and_render_game();
    draw_mini_map();
    return 0;
}



int	mouse_move(int keycode)
{
    v_global()->save_mouse_status = v_global()->mouse_move;
    v_global()->save_mouse_event_status = keycode;
    if(v_global()->check_mouse_sides == 0)
        v_global()->check_mouse_sides = 1;
    v_global()->last_update_time = current_milliseconds();
    if(keycode < v_global()->mouse_move)
    {
	    printf("----------%d--------is left-----\n", keycode);
        v_global()->mouse_direction = -1;
        v_global()->mouse_move = keycode;
    }
    else if(keycode > v_global()->mouse_move)
    {
        printf("----------%d--------is right-----\n", keycode);
        v_global()->mouse_direction = 1;
        v_global()->mouse_move = keycode;
    }
    else if(v_global()->mouse_move = keycode)
    {
        printf("----------%d-------- stop -----\n", keycode);
        v_global()->mouse_direction = 0;
        v_global()->mouse_move = keycode;
    }
    else
    {
        printf("----------%d--------up or down ()-----\n", keycode);
        v_global()->mouse_direction = 0;
        v_global()->mouse_move = keycode;
    }
    return 0;
}

int main(int argc, char *argv[])
{

    if (argc != 2)
        write(2, "Error\n ---> The Map Args Not Valid\n", 35);
    else
    {
        check_map(argv[1]);
        v_global()->mouse_move = 0;
        v_global()->save_mouse_status = 0;
        v_global()->check_mouse_sides = 0;
        
        fill_data();
        init_player();
        mlx_mouse_hide(v_global()->mlx, v_global()->mlx_win);
        mlx_hook(v_global()->mlx_win, 6, 1L << 6, mouse_move, NULL);
        mlx_hook(v_global()->mlx_win, 2, 1L << 0, key_press, NULL);
        mlx_hook(v_global()->mlx_win, 3, 1L << 1, key_release, NULL);
        mlx_loop_hook(v_global()->mlx, create_game, NULL);
        mlx_loop(v_global()->mlx);
    }
    return 0;
}
