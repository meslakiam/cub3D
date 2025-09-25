/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bann <oel-bann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 21:22:09 by imeslaki          #+#    #+#             */
/*   Updated: 2025/09/25 15:54:30 by oel-bann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	fill_data(void)
{
	t_global	*data;

	data = v_global();
	data->win_img = ft_malloc(sizeof(t_data));
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "CUBE3D");
	data->win_img = &create_image(NULL,  WINDOW_WIDTH, WINDOW_HEIGHT)->content;
}
