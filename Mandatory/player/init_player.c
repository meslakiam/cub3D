/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bann <oel-bann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 14:36:21 by imeslaki          #+#    #+#             */
/*   Updated: 2025/09/25 16:50:16 by oel-bann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

void	get_player_direction(void)
{
	if (v_player()->direction == 'N')
		v_player()->rotation_angle = 270;
	if (v_player()->direction == 'S')
		v_player()->rotation_angle = 90;
	if (v_player()->direction == 'E')
		v_player()->rotation_angle = 360;
	if (v_player()->direction == 'W')
		v_player()->rotation_angle = 180;
}

void	init_player(void)
{
	v_player()->p_x = get_map_info()->player_x * TILESIZE + TILESIZE / 2;
	v_player()->p_y = get_map_info()->player_y * TILESIZE + TILESIZE / 2;
	v_player()->direction = get_map_info()->direction;
	get_player_direction();
}

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
