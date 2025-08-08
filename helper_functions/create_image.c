/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bann <oel-bann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 19:45:31 by oel-bann          #+#    #+#             */
/*   Updated: 2025/08/05 19:12:42 by oel-bann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helper.h"

t_data_list	*create_image(t_img	*path_lst, int width, int height)
{
	t_data_list	*data;

	data = ft_calloc(1, sizeof(t_data_list));
	if (path_lst)
		data->content.img = mlx_xpm_file_to_image(v_global()->mlx, path_lst->path_img, &(data->content.img_width), &(data->content.img_height));
	else
	{
		data->content.img = mlx_new_image(v_global()->mlx, width, height);
		data->content.img_width = width;
		data->content.img_height = height;
	}
	data->content.addr = mlx_get_data_addr(data->content.img, &data->content.bits_per_pixel, &data->content.line_length, &data->content.endian);
	data->next = NULL;
	// save_img(data->img);
	return (data);
}