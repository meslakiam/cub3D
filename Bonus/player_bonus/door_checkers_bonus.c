/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_checkers_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 21:30:22 by imeslaki          #+#    #+#             */
/*   Updated: 2025/09/25 21:40:18 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d_bonus.h"

int	check_door_in_y(int y, int x, char grid, char new_grid)
{
	if (get_final_map(0, 0)[y][x + 1] == grid)
	{
		get_final_map(0, 0)[y][x + 1] = new_grid;
		return (1);
	}
	if (get_final_map(0, 0)[y][x - 1] == grid)
	{
		get_final_map(0, 0)[y][x - 1] = new_grid;
		return (1);
	}
	return (0);
}

int	check_door_in_x(int y, int x, char grid, char new_grid)
{
	if (get_final_map(0, 0)[y + 1][x] == grid)
	{
		get_final_map(0, 0)[y + 1][x] = new_grid;
		return (1);
	}
	if (get_final_map(0, 0)[y - 1][x] == grid)
	{
		get_final_map(0, 0)[y - 1][x] = new_grid;
		return (1);
	}
	return (0);
}

int	is_closed_door(void)
{
	int	x;
	int	y;

	x = v_player()->p_x / TILESIZE;
	y = v_player()->p_y / TILESIZE;
	if (check_door_in_x(y, x, 'D', 'O'))
		return (1);
	if (check_door_in_y(y, x, 'D', 'O'))
		return (1);
	return (0);
}

int	is_open_door(void)
{
	int	x;
	int	y;

	x = v_player()->p_x / TILESIZE;
	y = v_player()->p_y / TILESIZE;
	if (check_door_in_x(y, x, 'O', 'D'))
		return (1);
	if (check_door_in_y(y, x, 'O', 'D'))
		return (1);
	return (0);
}
