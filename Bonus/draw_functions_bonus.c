/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_functions_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 15:35:48 by imeslaki          #+#    #+#             */
/*   Updated: 2025/09/25 22:31:14 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d_bonus.h"

void	draw_pixel(int y, int x, int color)
{
	t_data	*data;
	char	*tmp;

	data = v_global()->win_img;
	if (x < 0 || y < 0 || x >= get_map_info()->win_w * TILESIZE
		|| y >= get_map_info()->win_h * TILESIZE)
		return ;
	tmp = data->addr + ((y * data->line_length)
			+ (x * (data->bits_per_pixel / 8)));
	*(unsigned int *)tmp = color;
}

void	draw_circle(double center_y, double center_x, int radius, int color)
{
	int	y;
	int	x;

	y = -radius;
	while (y <= radius)
	{
		x = -radius;
		while (x <= radius)
		{
			if (x * x + y * y <= radius * radius)
				draw_pixel((int)round(center_y) + y,
					(int)round(center_x) + x, color);
			x++;
		}
		y++;
	}
}
