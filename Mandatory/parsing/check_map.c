/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 06:50:09 by oel-bann          #+#    #+#             */
/*   Updated: 2025/09/25 20:54:17 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	check_map(char *filename)
{
	if (!check_ext_isvalid(filename))
	{
		write(2, "Error\n --> Extention Not Valid\n", 31);
		ft_exit(255);
	}
	fill_map_infos(filename);
	check_texture();
	if (!check_component())
	{
		write(2, "Error\n --> Component In Map Not Valid\n", 38);
		ft_exit(255);
	}
	get_map_width();
	check_closed_wall();
}
