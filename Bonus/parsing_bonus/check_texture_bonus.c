/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 06:08:57 by oel-bann          #+#    #+#             */
/*   Updated: 2025/09/17 22:11:30 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d_bonus.h"

void check_faces_texture_file_bonus(void)
{
    int fd;

    fd = ft_open(get_map_info()->door, O_RDONLY, 0666);
    close(fd);
    fd = ft_open(get_map_info()->no, O_RDONLY, 0666);
    close(fd);
    fd = ft_open(get_map_info()->so, O_RDONLY, 0666);
    close(fd);
    fd = ft_open(get_map_info()->we, O_RDONLY, 0666);
    close(fd);
    fd = ft_open(get_map_info()->ea, O_RDONLY, 0666);
    close(fd);
}

void check_texture_bonus(void)
{
    check_faces_texture_file_bonus();
    check_floor_cell_rgb();
}
