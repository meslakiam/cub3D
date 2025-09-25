/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_component_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bann <oel-bann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 12:10:37 by oel-bann          #+#    #+#             */
/*   Updated: 2025/09/25 00:55:15 by oel-bann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d_bonus.h"

int	check_component_bonus(void)
{
	char	**map;

	int i, (j), (repeated);
	i = 0;
	repeated = 0;
	map = get_final_map(0, 0);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!ft_strchr(" 01NSEWD", map[i][j]))
				return (0);
			if (ft_strchr("NSEW", map[i][j]))
				repeated++;
			if (ft_strchr("NSEW", map[i][j]) && repeated > 1)
				return (0);
			j++;
		}
		i++;
	}
	if (repeated != 1)
		return (0);
	return (1);
}

void	flood_fill_bonus(char **map, int x, int y)
{
	if (x < 0 || y < 0 || x >= ft_strlen(map[y]) || y >= get_map_hight(0) + 2)
		return ;
	if (map[y][x] == '2')
		return ;
	else if (map[y][x] == '*')
		return ;
	else if (map[y][x] == ' ' && (map[y][x - 1] != '0' && map[y][x + 1] != '0'\
		&& map[y - 1][x] != '0' && map[y + 1][x] != '0'))
		return ;
	else if ((map[y][x] == '0' || ft_strchr("NEWSD", map[y][x])) && (!\
		ft_strchr("012D", map[y][x - 1]) || !ft_strchr("012D", map[y][x + 1])))
		print_not_closed_map();
	else if ((map[y][x] == '0' || ft_strchr("NEWSD", map[y][x])) && (!\
		ft_strchr("012D", map[y - 1][x]) || !ft_strchr("012D", map[y + 1][x])))
		print_not_closed_map();
	else if (ft_strchr("NEWSD", map[y][x]) || map[y][x] == '0')
		map[y][x] = '2';
	else if (map[y][x] == '1')
		map[y][x] = '2';
	else
		print_not_closed_map();
	flood_fill_bonus(map, x + 1, y);
	flood_fill_bonus(map, x - 1, y);
	flood_fill_bonus(map, x, y + 1);
	flood_fill_bonus(map, x, y - 1);
}

int	check_closed_wall_bonus(void)
{
	char	**map;

	map = flood_fill_map();
	get_player_pos(map);
	flood_fill_bonus(map, get_map_info()->player_x, get_map_info()->player_y);
	get_map_info()->player_x -= 1;
	get_map_info()->player_y -= 1;
	return (1);
}
