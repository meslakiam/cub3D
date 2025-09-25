/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map_infos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bann <oel-bann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 04:54:04 by oel-bann          #+#    #+#             */
/*   Updated: 2025/09/25 16:49:33 by oel-bann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	is_newline(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '\n')
		return (1);
	return (0);
}

void	fill_map(char *str, int fd)
{
	if (!str)
	{
		write(2, "Error\n --> The Map Not found\n", 29);
		ft_exit(255);
	}
	while (str && is_newline(str))
		str = get_next_line(fd);
	while (str)
	{
		ft_lstadd_back(get_map(), ft_lstnew(str));
		str = get_next_line(fd);
	}
	remove_extra_from_map();
}

void	fill_map_infos(char *filename)
{
	char	*str;
	char	**splited_line;

	int(fd) = 0;
	fd = ft_open(filename, O_RDONLY, 0666);
	str = get_next_line(fd);
	while (str && !check_all_filled())
	{
		if (!is_newline(str))
		{
			splited_line = ft_split(str, " \t\n");
			if (check_is_in_cube_faces(splited_line[0]))
				fill_cube_faces(splited_line);
			else
			{
				write(2, "Error\n --> Missing Texture OR Repeated\n", 39);
				ft_exit(255);
			}
		}
		str = get_next_line(fd);
	}
	fill_map(str, fd);
	close(fd);
}
