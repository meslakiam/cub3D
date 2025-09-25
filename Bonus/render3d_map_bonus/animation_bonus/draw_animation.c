/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_animation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bann <oel-bann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 00:47:40 by oel-bann          #+#    #+#             */
/*   Updated: 2025/09/22 18:21:07 by oel-bann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d_bonus.h"

void draw_animation(t_data_list *img)
{
    double step_w;
    double step_h;
    double i, (j), (x), (y);
    int color;

    i = 0;
    y = 0;
    step_w = (double)img->content.img_width / (double)v_global()->win_img->img_width;
    step_h = (double)img->content.img_height/ (double)v_global()->win_img->img_height;
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