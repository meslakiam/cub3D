/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_wall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 16:02:02 by imeslaki          #+#    #+#             */
/*   Updated: 2025/07/16 16:31:10 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

int is_wall(int map_x, int map_y)
{
    if (map_x < 0 || map_x >= v_data()->win_width / TILESIZE)
        return (1);
    if(map_y < 0 || map_y >= v_data()->win_height / TILESIZE)
        return (1);
    return (v_map()->map[map_y][map_x] == '1');
}
