/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_shrink_image.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bann <oel-bann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 23:10:04 by oel-bann          #+#    #+#             */
/*   Updated: 2025/07/30 00:52:08 by oel-bann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helper.h"

t_data *mlx_shrink_img(t_data *src, int width, int height)
{
    int x;
    int y;
    int i;
    int j;
    int color;
    int w_skip_count;
    int h_skip_count;
    static t_data *dst;

    i = 0;
    y = 0;
    w_skip_count = src->img_width / width;
    h_skip_count = src->img_height / height;
    dst = ft_calloc(1, sizeof(t_data));
    dst->img = mlx_new_image(v_global()->mlx, width, height);
    dst->addr = mlx_get_data_addr(dst->img, &dst->bits_per_pixel, &dst->line_length, &dst->endian);
    while (i < src->img_height)
    {
        x = 0;
        j = 0;
        if (h_skip_count != src->img_height / height)
        {
            i++;
            h_skip_count++;
            continue;
        }
        h_skip_count = 1;
        while (j <  src->img_width)
        {
            if (w_skip_count != src->img_width / width)
            {
                j++;
                w_skip_count++;
                continue;
            }
            w_skip_count = 1;
            color =  my_mlx_get_pixel_color(src, j, i);
            if (color != 0)
                my_mlx_pixel_put(dst, x, y, color);
            j++;
            x++;
        }
        i++;
        y++;
    }
    return (dst);
}
