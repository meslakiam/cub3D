/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_map_extra.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bann <oel-bann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 03:20:01 by oel-bann          #+#    #+#             */
/*   Updated: 2025/07/20 20:13:27 by oel-bann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int line_start()
{
	static int line_start;
	int first;
	int j;
	t_map *map;

	first = 0;
	if (!line_start)
	{
		map = *get_map();
		while(map)
		{
			j = 0;
			while (strchr(" \t", map->map_line[j]))
				j++;
			if (!first || j < line_start)
			{
				first = 1;
				line_start = j;
			}
			map = map->next;
		}
	}
	return (line_start);
}


int line_end(char *str)
{
	int j;
	int end;

	j = 0;
	end = 0;
	if (is_newline(str))
		return(ft_strlen(str));
	while (strchr(" \t", str[j]))
		j++;
	while(str[j])
	{
		if (!strchr(" \t\n", str[j]))
			end = j;
		j++;
	}
	return (end);
}

char *get_line(char *str)
{
	char *new_line;
	int start;
	int end;
	int i;

	i = 0;
	end = line_end(str);
	start = line_start();
	new_line = ft_calloc((end -  start) + 2, sizeof(char));
	while (str && str[start] && start <= end)
	{
		new_line[i] = str[start];
		start++;
		i++;
	}
	return (new_line);
}

char **copy_map_in_tab()
{
	t_map *map;
	char **new_map;
	int i;
	
	map = *get_map();
	i = 0;
	new_map = ft_calloc(get_map_hight(1) + 1, sizeof(char *));
	while (map)
	{
		if (is_newline(map->map_line))
		{
			write (2, "Error \n ---> Newline Detected In The Map\n", 41);
			ft_exit(255);
		}
		new_map[i] = get_line(map->map_line);
		i++;
		map = map->next;
	}
	return (new_map);
}

void remove_extra_from_map()
{
	t_map *map;
	t_map *prev;

	map = *get_map();
	while (map->next)
		map = map->next;
	while (is_newline(map->map_line))
	{
		prev = map->prev;
		// if (is_newline(map->map_line))
		// {
			ft_lstremove(get_map(), map);
		// }
		map = prev;
	}
	get_final_map(1, copy_map_in_tab());
}