/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_component.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bann <oel-bann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 12:10:37 by oel-bann          #+#    #+#             */
/*   Updated: 2025/09/25 01:00:27 by oel-bann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	check_component(void)
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
			if (!ft_strchr(" 01NSEW", map[i][j]))
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

void	fill_new_map(char **new_map, char **map, int i, int y)
{
	int	j;
	int	h;

	j = 0;
	h = 0;
	new_map[y][j++] = '*';
	while (map[i][h])
	{
		new_map[y][j] = map[i][h];
		j++;
		h++;
	}
	while (j < get_map_info()->win_w)
		new_map[y][j++] = '*';
	new_map[y][j] = '*';
}

char	**flood_fill_map(void)
{
	char	**map;
	char	**new_map;

	int i, (y);
	map = get_final_map(0, 0);
	i = 0;
	y = 1;
	new_map = ft_calloc(get_map_hight(1) + 3, sizeof(char *));
	new_map[0] = ft_calloc(ft_strlen(map[0]) + 3, sizeof(char));
	ft_memset(new_map[0], '*', ft_strlen(map[0]) + 2);
	new_map[get_map_hight(0) + 1] = ft_calloc(ft_strlen(map[get_map_hight(0)
				- 1]) + 3, sizeof(char));
	ft_memset(new_map[get_map_hight(0) + 1], '*', ft_strlen(map[get_map_hight(0)
			- 1]) + 2);
	while (map[i])
	{
		new_map[y] = ft_calloc(get_map_info()->win_w + 3, sizeof(char));
		fill_new_map(new_map, map, i, y);
		i++;
		y++;
	}
	return (new_map);
}

void	flood_fill(char **map, int x, int y)
{
	if (x < 0 || y < 0 || x >= ft_strlen(map[y]) || y >= get_map_hight(0) + 2)
		return ;
	if (map[y][x] == '2')
		return ;
	else if (map[y][x] == '*')
		return ;
	else if (map[y][x] == ' ' && (map[y][x - 1] != '0' && map[y][x + 1] != '0'
			&& map[y - 1][x] != '0' && map[y + 1][x] != '0'))
		return ;
	else if ((map[y][x] == '0' || ft_strchr("NEWS", map[y][x])) && (!\
		ft_strchr("012", map[y][x - 1]) || !ft_strchr("012", map[y][x + 1])))
		print_not_closed_map();
	else if ((map[y][x] == '0' || ft_strchr("NEWS", map[y][x])) && (!\
		ft_strchr("012", map[y - 1][x]) || !ft_strchr("012", map[y + 1][x])))
		print_not_closed_map();
	else if (ft_strchr("NEWS", map[y][x]) || map[y][x] == '0')
		map[y][x] = '2';
	else if (map[y][x] == '1')
		map[y][x] = '2';
	else
		print_not_closed_map();
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}

int	check_closed_wall(void)
{
	char	**map;

	map = flood_fill_map();
	get_player_pos(map);
	flood_fill(map, get_map_info()->player_x, get_map_info()->player_y);
	get_map_info()->player_x -= 1;
	get_map_info()->player_y -= 1;
	return (1);
}
