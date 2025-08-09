/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_copy_image.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bann <oel-bann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 23:10:04 by oel-bann          #+#    #+#             */
/*   Updated: 2025/08/06 12:03:44 by oel-bann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helper.h"

t_data_list *mlx_copy_img(t_data *src, int width, int height)
{
    t_data_list *dst;
    int x, (y), (i), (j);
    int color;
    double w_step;
    double h_step;

    j = 0;
    y = 0;
    w_step = src->img_width / width;
    h_step = src->img_height / height;
    dst = create_image(NULL, width, height);
    while (y < height)
    {
        i = 0;
        x = 0;
        while (x < width)
        {
            color =  my_mlx_get_pixel_color(src, x, y);
            my_mlx_pixel_put(&(dst->content), i, j, color);
            x += w_step;
            i++;
        }
        y += h_step;
        j++;
    }
    return (dst);
}
