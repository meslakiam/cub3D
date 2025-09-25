/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 22:50:28 by oel-bann          #+#    #+#             */
/*   Updated: 2025/09/25 21:53:41 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d_bonus.h"

int	is_ver_door_tex(void)
{
	if (get_final_map(0, 0)[(int)v_player()->end_p_y
		/ TILESIZE][(int)(v_player()->end_p_x - TILESIZE / 2) / TILESIZE] == 'D'
		|| get_final_map(0, 0)[(int)v_player()->end_p_y
		/ TILESIZE][(int)(v_player()->end_p_x + TILESIZE / 2)
		/ TILESIZE] == 'D')
		return (1);
	return (0);
}

int	is_hor_door_tex(void)
{
	if (get_final_map(0, 0)[(int)(v_player()->end_p_y - TILESIZE / 2)
		/ TILESIZE][(int)v_player()->end_p_x / TILESIZE] == 'D'
		|| get_final_map(0, 0)[(int)(v_player()->end_p_y + TILESIZE / 2)
		/ TILESIZE][(int)v_player()->end_p_x / TILESIZE] == 'D')
		return (1);
	return (0);
}

int	get_wall_texture_bonus(void)
{
	int	tex_id;

	tex_id = 0;
	if (v_player()->was_hit_vertical)
	{
		if (is_ver_door_tex())
			tex_id = TEX_DOOR;
		else if (v_player()->end_p_x > v_player()->p_x)
			tex_id = TEX_WEST;
		else
			tex_id = TEX_EAST;
	}
	else
	{
		if (is_hor_door_tex())
			tex_id = TEX_DOOR;
		else if (v_player()->end_p_y > v_player()->p_y)
			tex_id = TEX_SOUTH;
		else
			tex_id = TEX_NORTH;
	}
	return (tex_id);
}

void	render_bonus(int ray_index, double ray_angle)
{
	int (wall_strip_hight), (color), (wall_tex);
	double (start_y), (end_y), (img_start_h), (step);
	wall_tex = get_wall_texture_bonus();
	wall_strip_hight = get_wall_strip_hight(ray_angle);
	start_y = (v_global()->win_img->img_height / 2) - (wall_strip_hight / 2);
	end_y = start_y + wall_strip_hight;
	img_start_h = get_tex_start_bonus(start_y, end_y, wall_tex);
	step = get_tex_step_bonus(wall_tex, (end_y - start_y));
	if (start_y < 0)
		start_y = 0;
	if (end_y > WINDOW_HEIGHT)
		end_y = WINDOW_HEIGHT;
	while (start_y < end_y)
	{
		color = my_mlx_get_pixel_color(*get_textures_bonus(wall_tex),
				get_img_start_w((*get_textures_bonus(wall_tex))->img_width),
				img_start_h);
		draw_pixel_depend_distance(start_y, ray_index, color);
		img_start_h += step;
		start_y++;
	}
}
