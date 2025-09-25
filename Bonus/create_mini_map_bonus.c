/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_mini_map_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 00:24:22 by oel-bann          #+#    #+#             */
/*   Updated: 2025/09/25 22:32:18 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d_bonus.h"

static void	draw_pixel(int y, int x, int color)
{
	my_mlx_pixel_put(v_global()->win_img, y, x, color);
}

static int	get_map_color(int y, int x)
{
	return (get_mini_map_color(v_player()->p_x + x, v_player()->p_y + y));
}

static void	chouse_drawing_color(int y, int x, int j, int i)
{
	int	color;

	color = get_map_color(x, y);
	if (x * x + y * y >= (MINI_MAP_W / 2 - 3) * (MINI_MAP_W / 2 - 3))
		draw_pixel(MINI_MAP_MAR + j, MINI_MAP_MAR + i, 0xFFFFFF);
	else
		draw_pixel(MINI_MAP_MAR + j, MINI_MAP_MAR + i, color);
}

int	get_mini_map_color(double x, double y)
{
	char	map_cor;

	int col, (row);
	col = y / TILESIZE;
	row = x / TILESIZE;
	if (x < 0 || y < 0 || col > get_map_info()->win_h
		|| row > ft_strlen(get_final_map(0, 0)[col]) - 1)
		return (0);
	if (col * TILESIZE == (int)y || row * TILESIZE == (int)x)
		return (0);
	map_cor = get_final_map(0, 0)[col][row];
	if (map_cor == '1')
		return (WALL_COLOR);
	if (ft_strchr("0NSWE", map_cor))
		return (FLOOR_COLOR);
	if (ft_strchr("D", map_cor))
		return (CLOSE_DOOR_COLOR);
	if (ft_strchr("O", map_cor))
		return (OPEN_DOOR_COLOR);
	else
		return (0);
}

void	draw_mini_map(void)
{
	int i, (j), (x), (y);
	y = -MINI_MAP_W / 2;
	i = 0;
	while (y <= MINI_MAP_W / 2)
	{
		x = -MINI_MAP_W / 2;
		j = 0;
		while (x <= MINI_MAP_W / 2)
		{
			if (x * x + y * y <= MINI_MAP_W / 2 * MINI_MAP_W / 2)
				chouse_drawing_color(y, x, j, i);
			x++;
			j++;
		}
		y++;
		i++;
	}
	draw_circle(MINI_MAP_MAR + MINI_MAP_W / 2, MINI_MAP_MAR + MINI_MAP_W / 2,
		RADIUS, 0x00FF0000);
}
