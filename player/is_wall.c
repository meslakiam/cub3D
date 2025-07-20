/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_wall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 16:02:02 by imeslaki          #+#    #+#             */
/*   Updated: 2025/07/19 20:03:10 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

int is_wall(int map_x, int map_y)
{
    if (map_x < 0 || map_x >= v_global()->win_width / TILESIZE)
        return (1);
    if(map_y < 0 || map_y >= v_global()->win_height / TILESIZE)
        return (1);
    return (get_final_map(0,0)[map_y][map_x] == '1');
}
