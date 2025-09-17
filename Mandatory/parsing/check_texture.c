/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 06:08:57 by oel-bann          #+#    #+#             */
/*   Updated: 2025/09/17 22:13:54 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void check_faces_texture_file()
{
    int fd;

    fd = ft_open(get_map_info()->no, O_RDONLY, 0666);
    close(fd);
    fd = ft_open(get_map_info()->so, O_RDONLY, 0666);
    close(fd);
    fd = ft_open(get_map_info()->we, O_RDONLY, 0666);
    close(fd);
    fd = ft_open(get_map_info()->ea, O_RDONLY, 0666);
    close(fd);
}

char **check_rgb(char *str)
{
    int i;
    char **rgb;

    i = 0;
    while(str && str[i])
    {
        if ((str[i] < '0' && str[i] > '9') || \
        (!(str[i] >= '0' && str[i] <= '9') && str[i] != ','))
            return(NULL);
        i++;
    }
    i = 0;
    while(str && str[i])
    {
        if ((str[i] == ',' && (str[i + 1] == ',' || str[i + 1] == '\0')) || str[0] == ',')
            return(NULL);
        i++;
    }
    rgb = ft_split(str, ",");
    i = 0;
    while(rgb[i])
        i++;
    if (i != 3)
        return(NULL);
    return (rgb);
}
int *get_rgb_int_value(char **x_rgb)
{
    int *tab;
    int i;
    int value;

    i = 0;
    value = 0;
    tab = ft_calloc(3, sizeof(int));
    while (x_rgb && x_rgb[i])
    {
        value = ft_atoi(x_rgb[i]);
        if (value > 255 || value < 0)
        {
            write(2, "Error\n --> Outrage The RGB Range\n", 33);
            ft_exit(255);
        }
        tab[i] = value;
        i++;
    }
    return (tab);
}

void check_floor_cell_rgb(void)
{
    char **c_rgb;
    char **f_rgb;

    c_rgb = check_rgb(get_map_info()->cell_rgb);
    f_rgb = check_rgb(get_map_info()->floor_rgb);
    if (!c_rgb || !f_rgb)
    {
        write(2, "Error\n --> Something Wrong In The Cell Floor RGB\n", 49);
        ft_exit(255);
    }
    get_map_info()->f_rgb_tab = get_rgb_int_value(f_rgb);
    get_map_info()->c_rgb_tab = get_rgb_int_value(c_rgb);
}

void check_texture()
{
    check_faces_texture_file();
    check_floor_cell_rgb();
}
