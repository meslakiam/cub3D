/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 13:27:18 by imeslaki          #+#    #+#             */
/*   Updated: 2025/08/05 16:24:47 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void	get_player_direction(void)
{
	if (v_player()->direction == 'N')
		v_player()->rotation_angle = 270;
	if (v_player()->direction == 'S')
		v_player()->rotation_angle = 90;
	if (v_player()->direction == 'E')
		v_player()->rotation_angle = 360;
	if (v_player()->direction == 'W')
		v_player()->rotation_angle = 180;
}

void	init_player(int col, int row)
{
	static int	first;

	if (!first)
	{
		first = 1;
		v_player()->p_x = row * TILESIZE + TILESIZE / 2;
		v_player()->p_y = col * TILESIZE + TILESIZE / 2;
		get_player_direction();
	}
}

bool	is_player(char c)
{
	if (c == 'P')
		return (true);
	if (c == 'N')
	{
		v_player()->direction = c;
		return (true);
	}
	if (c == 'E')
	{
		v_player()->direction = c;
		return (true);
	}
	if (c == 'W')
	{
		v_player()->direction = c;
		return (true);
	}
	if (c == 'S')
	{
		v_player()->direction = c;
		return (true);
	}
	return (false);
}

void	draw_player(void)
{
//     t_global	*data;
// 	t_data		*shrinked_map;

//     data = v_global();
	draw_circle(v_player()->p_y, v_player()->p_x, RADIUS, 0x00FF0000);
	// cast_ray(v_player()->rotation_angle);
	// draw_line((int)v_player()->p_x, (int)v_player()->p_y, (int)v_player()->end_p_x , (int)v_player()->end_p_y , 0x00FF0000);
	// shrinked_map = mlx_shrink_img(data->win_img, 440, 160);
	// mlx_put_image_to_window(data->mlx, data->mlx_win, shrinked_map->img, 0, 0);
	// mlx_put_image_to_window(data->mlx, data->mlx_win, data->win_img->img, 0, 0);
}

void	draw_map(void)
{
	int			row;
	int			col;
	char		**map;
	t_player	*p;

	p = v_player();
	col = 0;
	map = get_final_map(0,0);
	while (map[col])
	{
		row = 0;
		while (map[col][row])
		{
			if (map[col][row] == '1')
				draw_square(col * TILESIZE, row * TILESIZE, 0x00404040); // Wall
			else if (map[col][row] == '0' || is_player(map[col][row]))
			{
				if(is_player(map[col][row]))
					init_player(col, row);
				draw_square(col * TILESIZE, row * TILESIZE, 0x00F5F5DC); // Floor
			}
			row++;
		}
		col++;
	}
	draw_player();
}
