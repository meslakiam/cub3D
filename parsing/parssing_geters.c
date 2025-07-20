/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing_geters.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 06:07:03 by oel-bann          #+#    #+#             */
/*   Updated: 2025/07/19 19:22:55 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"



t_map **get_map()
{
    static t_map *map;

    if (!map)
        get_map_info()->map = &map;
    return (&map);
}

int *get_all_filled()
{
    static int is_filled[6];
    return(is_filled);
}

char **get_final_map(int set, char **map)
{
	static char **final_map;

	if (set)
		final_map = map;
	return (final_map);
}

int get_map_hight(int set)
{
	int static hight;
	int i;
	t_map *map;

	i = 0;
	if (set)
	{
		map = *get_map();
		while (map)
		{
			map = map->next;
			i++;
		}
		hight = i;
		get_map_info()->win_h = i;
	}
	return (hight);
}

void get_map_width()
{
	char		**map;
	int			i;
	int			map_len;

	i = 0;
	map_len = 0;
	get_map_info()->win_w = 0;
	map = get_final_map(0, 0);
	while (map[i])
	{
		map_len = ft_strlen(map[i]);
		if (get_map_info()->win_w < map_len)
			get_map_info()->win_w = map_len;
		i++;
	}
}
