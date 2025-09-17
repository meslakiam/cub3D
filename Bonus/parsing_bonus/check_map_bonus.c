/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 06:50:09 by oel-bann          #+#    #+#             */
/*   Updated: 2025/09/17 22:18:53 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d_bonus.h"

void check_map_bonus(char *filename)
{
    if (!check_ext_isvalid(filename))
    {
        write(2, "Error\n --> Extention Not Valid\n", 31);
        ft_exit(255);
    }
    fill_map_infos_bonus(filename);
    check_texture_bonus();
    if (!check_component_bonus())
    {
        write(2, "Error\n --> Component In Map Not Valid\n", 38);
        ft_exit(255);
    }
    get_map_width();
    check_closed_wall_bonus();
}
