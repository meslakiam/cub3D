/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 13:27:18 by imeslaki          #+#    #+#             */
/*   Updated: 2025/08/11 11:05:34 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"



bool	is_player(char c)
{
	if (c == 'P')
		return (true);
	if (c == 'N')
	{
		v_player()->direction = c;
		return (true);
	}
	if (c == 'E')
	{
		v_player()->direction = c;
		return (true);
	}
	if (c == 'W')
	{
		v_player()->direction = c;
		return (true);
	}
	if (c == 'S')
	{
		v_player()->direction = c;
		return (true);
	}
	return (false);
}


void	draw_map(void)
{
	int			row;
	int			col;
	char		**map;
	t_player	*p;

	p = v_player();
	col = 0;
	map = get_final_map(0,0);
	while (map[col])
	{
		row = 0;
		while (map[col][row])
		{
			if (map[col][row] == '1')
				draw_square(col * TILESIZE, row * TILESIZE, 0x00404040); // Wall
			else if (map[col][row] == '0' || is_player(map[col][row]))
			{
				draw_square(col * TILESIZE, row * TILESIZE, 0x00F5F5DC); // Floor
			}
			row++;
		}
		col++;
	}
}
