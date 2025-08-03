/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_expand_image.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bann <oel-bann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 23:10:04 by oel-bann          #+#    #+#             */
/*   Updated: 2025/07/30 00:45:53 by oel-bann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helper.h"

t_data *mlx_expand_img(t_data *src, int width, int height)
{
    int x;
    int y;
    int i;
    int j;
    int color;
    int w_add_count;
    int h_add_count;
    t_data *dst;

    i = 0;
    y = 0;
    dst = ft_calloc(1, sizeof(t_data));
    dst->img = mlx_new_image(v_global()->mlx, width, height);
    dst->addr = mlx_get_data_addr(dst->img, &dst->bits_per_pixel, &dst->line_length, &dst->endian);
    while (y < height)
    {
        h_add_count = 0;
        while(h_add_count < (height - y) / (src->img_height - i))
        {
            x = 0;
            j = 0;
            while (x <  width)
            {
                w_add_count = 0;
                while (w_add_count < (width - x) / (src->img_width - j))
                {
                    color =  my_mlx_get_pixel_color(src, j, i);
                    my_mlx_pixel_put(dst, x, y, color);
                    w_add_count++;
                    x++;
                }
                x++;
                j++;
            }
            y++;
            h_add_count++;
        }
        y++;
        i++;
    }
    return (dst);
}
