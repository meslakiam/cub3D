/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_component.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 12:10:37 by oel-bann          #+#    #+#             */
/*   Updated: 2025/08/16 19:22:04 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int check_component()
{
    int i, (j), (repeated);
    char **map;

    i = 0;
    repeated = 0;
    map = get_final_map(0, 0);
    while(map[i])
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
    if(repeated != 1)
        return (0);
    return (1);
}

void get_player_pos(char **map_c)
{
    int i, (j);
    char **map;

    i = 0;
    j = 0;
    map = map_c;
    while(map[i])
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

char **flood_fill_map()
{
    char **map;
    char **new_map;
	int i, (y), (j), (h);
	
	map = get_final_map(0, 0);
	i = 0;
    y = 1;
	new_map = ft_calloc(get_map_hight(1) + 3, sizeof(char *));
    new_map[0] = ft_calloc(ft_strlen(map[0]) + 3, sizeof(char));
    ft_memset(new_map[0], '*', ft_strlen(map[0]) + 2);
    new_map[get_map_hight(0) + 1] = ft_calloc(ft_strlen(map[get_map_hight(0) - 1]) + 3, sizeof(char));
    ft_memset(new_map[get_map_hight(0) + 1], '*', ft_strlen(map[get_map_hight(0) - 1]) + 2);
	while (map[i])
	{
		new_map[y] = ft_calloc(ft_strlen(map[i]) + 3, sizeof(char));
		j = 0;
        h = 0;
        new_map[y][j] = '*';
        j++;
		while(map[i][h])
		{
			if (ft_strchr("01NSEW ", map[i][h]))
				new_map[y][j] = map[i][h];
            else
                new_map[y][j] = '*';
			j++;
            h++;
		}
        new_map[y][j] = '*';
		i++;
        y++;
	}
	return (new_map);
}

void flood_fill(char **map, int x, int y)
{
    int len1 = ft_strlen(map[y]);
    int len2 = get_map_hight(0) + 2;
	if (x < 0 || y < 0 || x >=  len1 || y >= len2)
		return ;
    if (map[y][x] == '2')
        return;
    else if (map[y][x] == '*')
        return;
    else if (map[y][x] == ' ' && (map[y][x - 1] != '0' && map[y][x + 1] != '0' && map[y - 1][x] != '0' && map[y + 1][x] != '0'))
        return;
    else if (map[y][x] == '0' && map[y][x] == 'D' && (map[y][x - 1] == '*' || map[y][x + 1] == '*'))
    {
        write(2, "Error\n ---> The Map Not Closed\n",31);
        ft_exit(255);
    }
    else if (map[y][x] == '0' && map[y][x] == 'D' &&  (map[y - 1][x] == '*' || map[y + 1][x] == '*'))
    {
        write(2, "Error\n ---> The Map Not Closed\n",31);
        ft_exit(255);
    }
    else if (ft_strchr("NEWSD", map[y][x]) || map[y][x] == '0')
		map[y][x] = '2';
    else if (map[y][x] == '1')
		map[y][x] = '2';
    else
    {
        write(2, "Error\n ---> The Map Not Closed\n",31);
        ft_exit(255);
    }
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}

int check_closed_wall()
{
    char **map;
    char **map2;

    map = flood_fill_map();
    int i = 0;
    while (map[i])
    {
       printf("|%s|\n",map[i]);
       i++;
    }
    get_player_pos(map);
    flood_fill(map, get_map_info()->player_x, get_map_info()->player_y);
    get_map_info()->player_x -= 1;
    get_map_info()->player_y -= 1;
     i = 0;
    while (map[i])
    {
       printf("|%s|\n",map[i]);
       i++;
    }
    return(1);
}
