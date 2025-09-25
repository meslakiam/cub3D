/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_component_tools.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bann <oel-bann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 00:59:23 by oel-bann          #+#    #+#             */
/*   Updated: 2025/09/25 01:00:41 by oel-bann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	get_player_pos(char **map_c)
{
	char	**map;

	int i, (j);
	i = 0;
	j = 0;
	map = map_c;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (ft_strchr("SNEW", map[i][j]))
			{
				get_map_info()->player_x = j;
				get_map_info()->player_y = i;
				get_map_info()->direction = map[i][j];
			}
			j++;
		}
		i++;
	}
}

void	print_not_closed_map(void)
{
	write(2, "Error\n --//-> The Map Not Closed\n", 31);
	ft_exit(255);
}
