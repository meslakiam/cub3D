/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bann <oel-bann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 19:24:09 by oel-bann          #+#    #+#             */
/*   Updated: 2025/08/05 11:44:39 by oel-bann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

double get_img_start_w(int img_w)
{
    double img_start_w;
    double end_x_y;
    int pos;

    if (v_player()->was_hit_vertical)
        end_x_y = v_player()->end_p_y;
    else
        end_x_y = v_player()->end_p_x;
    pos = end_x_y / TILESIZE;
    img_start_w = (end_x_y - (pos * TILESIZE)) * (img_w / TILESIZE);
    return (img_start_w);
}

int is_map_corners()
{
    int i;
    int j;
    char **map;

    i = v_player()->end_p_y / TILESIZE;
    j = v_player()->end_p_x / TILESIZE;
    map = get_final_map(0, 0);
    if (j + 1 >= 0 && j + 1 < get_map_info()->win_w && j - 1 >= 0 && j - 1 < get_map_info()->win_w)
    {
        if (i + 1 >= 0 && i + 1 < get_map_info()->win_h && i - 1 >= 0 && i - 1 < get_map_info()->win_h)
        {
            if (map[i][j] == '1' && (map[i + 1][j + 1] == '1' || map[i + 1][j - 1] == '1'))
                return (TEX_EAST);
            if (map[i][j] == '1' && (map[i - 1][j + 1] == '1' || map[i - 1][j - 1] == '1'))
                return (TEX_WEST);
        }
    }
    return (0);
}