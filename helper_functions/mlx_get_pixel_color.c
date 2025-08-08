/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_get_pixel_color.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bann <oel-bann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 23:33:06 by oel-bann          #+#    #+#             */
/*   Updated: 2025/08/07 12:44:07 by oel-bann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helper.h"

int	my_mlx_get_pixel_color(t_data *data, int x, int y)
{
    int *dst;

    dst = (int *)(data->addr + (y * data->line_length) + (x * (data->bits_per_pixel / 8)));
    return (*dst);
}