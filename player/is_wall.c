/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_wall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bann <oel-bann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 16:02:02 by imeslaki          #+#    #+#             */
/*   Updated: 2025/08/05 09:51:16 by oel-bann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

int is_wall(int map_x, int map_y)
{
    if (map_x < 0 || map_x >= get_map_info()->win_w)
        return (1);
    if(map_y < 0 || map_y >= get_map_info()->win_h)
        return (1);
    return (get_final_map(0,0)[map_y][map_x] == '1');
}

// int is_wall(int map_x, int map_y)
// {
//     if (map_x >= 0 && map_y >= 0 && map_x < get_map_info()->win_h && map_x < get_map_info()->win_w)
//         return (get_final_map(0,0)[map_y][map_x] == '1');
//     return(0);
// }
