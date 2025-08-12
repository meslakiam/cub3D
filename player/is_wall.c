/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_wall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 16:02:02 by imeslaki          #+#    #+#             */
/*   Updated: 2025/08/12 17:18:23 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

int is_wall(int map_x, int map_y)
{
    if (map_y < 0 || map_y >= get_map_info()->win_h)
        return (1);
    if (map_x < 0 || map_x >= get_map_info()->win_w)
        return (1);
    return (get_final_map(0, 0)[map_y][map_x] == '1');
}

int check_wall_y(double x1, double y1, double angle, int d)
{
    int col;
    int row;
    double radian;

    radian = DEG_TO_RAD(angle);
    row = x1;
    col = y1 + (d + 2) * sin(radian);
    if (get_final_map(0,0)[col / TILESIZE][row / TILESIZE] == '1')
        return 1;
    return 0;
}

int check_wall_x(double x1, double y1, double angle, int d)
{
    int col;
    int row;
    double radian;

    radian = DEG_TO_RAD(angle);
    row = x1 + (d + 2) * cos(radian);
    col = y1;
    if (get_final_map(0,0)[col / TILESIZE][row / TILESIZE] == '1')
        return 1;
    return 0;
}