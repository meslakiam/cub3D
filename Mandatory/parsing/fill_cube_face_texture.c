/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_cube_face_texture.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bann <oel-bann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 22:16:08 by oel-bann          #+#    #+#             */
/*   Updated: 2025/09/25 01:01:44 by oel-bann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	check_all_filled(void)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (!get_all_filled()[i])
			return (0);
		i++;
	}
	return (1);
}
int	check_is_in_cube_faces(char *face)
{
	int			i;
	static char	**faces;

	i = 0;
	if (!faces)
		faces = ft_split("NO SO WE EA F C", " ");
	if (!face[0])
		return (1);
	while (face && faces && faces[i])
	{
		if (!ft_strncmp(faces[i], face, ft_strlen(faces[i]))
			&& !get_all_filled()[i])
		{
			get_all_filled()[i] = 1;
			return (1);
		}
		i++;
	}
	return (0);
}

void	fill_cube_faces(char **splited_line)
{
	int	i;

	i = 0;
	while (splited_line[i])
		i++;
	if (i != 2)
	{
		write(2, "Error\n --> One Of Texture Line Has More Than Needed\n", 52);
		ft_exit(255);
	}
	if (!ft_strncmp("NO", splited_line[0], 3))
		get_map_info()->no = splited_line[1];
	else if (!ft_strncmp("SO", splited_line[0], 3))
		get_map_info()->so = splited_line[1];
	else if (!ft_strncmp("WE", splited_line[0], 3))
		get_map_info()->we = splited_line[1];
	else if (!ft_strncmp("EA", splited_line[0], 3))
		get_map_info()->ea = splited_line[1];
	else if (!ft_strncmp("F", splited_line[0], 2))
		get_map_info()->floor_rgb = splited_line[1];
	else if (!ft_strncmp("C", splited_line[0], 2))
		get_map_info()->cell_rgb = splited_line[1];
}
