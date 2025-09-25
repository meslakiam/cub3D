/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_animation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 00:47:40 by oel-bann          #+#    #+#             */
/*   Updated: 2025/09/25 21:45:28 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d_bonus.h"

void	steps(double *step_w, double *step_h, t_data_list *img)
{
	*step_w = (double)img->content.img_width
		/ (double)v_global()->win_img->img_width;
	*step_h = (double)img->content.img_height
		/ (double)v_global()->win_img->img_height;
}

void	draw_animation(t_data_list *img)
{
	double	step_w;
	double	step_h;
	int		color;

	double i, (j), (x), (y);
	i = 0;
	y = 0;
	steps(&step_w, &step_h, img);
	while (y < v_global()->win_img->img_height)
	{
		j = 0;
		x = 0;
		while (x < v_global()->win_img->img_width)
		{
			color = my_mlx_get_pixel_color(&img->content, j, i);
			if (color != 0xFF0000)
				my_mlx_pixel_put(v_global()->win_img, x, y, color);
			j += step_w;
			x++;
		}
		i += step_h;
		y++;
	}
}
