/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map_infos_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 04:54:04 by oel-bann          #+#    #+#             */
/*   Updated: 2025/09/25 21:29:04 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d_bonus.h"

void	fill_map_infos_bonus(char *filename)
{
	char	*str;
	char	**splited_line;
	int		fd;

	fd = ft_open(filename, O_RDONLY, 0666);
	str = get_next_line(fd);
	while (str && !check_all_filled())
	{
		if (!is_newline(str))
		{
			splited_line = ft_split(str, " \t\n");
			if (check_is_in_cube_faces_bonus(splited_line[0]))
				fill_cube_faces_bonus(splited_line);
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
