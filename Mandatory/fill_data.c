/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 21:22:09 by imeslaki          #+#    #+#             */
/*   Updated: 2025/09/17 21:22:31 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	fill_data(void)
{
	t_global	*data;

	data = v_global();
	data->win_img = ft_malloc(sizeof(t_data));
	data->map_img = ft_malloc(sizeof(t_data));
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, window_width, window_height,
			"CUBE3D");
	data->win_img->img_width = window_width;
	data->win_img->img_height = window_height;
	data->map_img->img_width = get_map_info()->win_w * TILESIZE;
	data->map_img->img_height = get_map_info()->win_h * TILESIZE;
	data->win_img->img = mlx_new_image(data->mlx, data->win_img->img_width,
			data->win_img->img_height);
	data->win_img->addr = mlx_get_data_addr(data->win_img->img,
			&data->win_img->bits_per_pixel, &data->win_img->line_length,
			&data->win_img->endian);
	data->map_img->img = mlx_new_image(data->mlx, data->map_img->img_width,
			data->map_img->img_height);
	data->map_img->addr = mlx_get_data_addr(data->map_img->img,
			&data->map_img->bits_per_pixel, &data->map_img->line_length,
			&data->map_img->endian);
}
