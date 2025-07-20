/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map_infos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bann <oel-bann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 04:54:04 by oel-bann          #+#    #+#             */
/*   Updated: 2025/07/16 12:28:27 by oel-bann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int is_newline(char *str)
{
    int i;

    i = 0;
    if (!str)
        return(0);
    while (str[i] == ' ' || str[i] == '\t') 
        i++;
    if (str[i] == '\n')
        return(1);
    return (0);
}

void fill_map(char *str, int fd)
{
    if (!str)
    {
        write(2, "Error\n --> The Map Not found\n", 29);
        ft_exit(255);
    }
    while(str && is_newline(str))
        str = get_next_line(fd);
    while(str)
    {
        ft_lstadd_back(get_map(), ft_lstnew(str));
        str = get_next_line(fd);
    }
    remove_extra_from_map();
}

void fill_map_infos(char *filename)
{
    int (fd) = 0;
    char *str;
    char **splited_line;

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

// int main()
// {
//     int i = 0;
//     check_map("/home/oel-bann/Desktop/Cube3D/map.cub");
//     printf("----------------------------------\n");
//     printf("NO %s\n", get_map_info()->no);
//     printf("SO %s\n", get_map_info()->so);
//     printf("WE %s\n", get_map_info()->we);
//     printf("EA %s\n", get_map_info()->ea);
//     printf("F %s\n", get_map_info()->floor_rgb);
//     printf("C %s\n", get_map_info()->cell_rgb);
//     printf("--------------cell rgb--------------------\n");
//     i = 0;
//     while (i < 3)
//     {
//         printf("rgb part %d ---> %d", i, get_map_info()->c_rgb_tab[i]);
//         i++;
//     }
//     printf("--------------floor rgb--------------------\n");
//     i = 0;
//     while (i < 3)
//     {
//         printf("rgb part %d ---> %d", i, get_map_info()->f_rgb_tab[i]);
//         i++;
//     }
//     printf("\n---------------NEW MAP-------------------\n");
//     char **new_map = get_final_map(0, 0);
//     int j= 0;
//     while (new_map[j])
//     {
//         printf("|%s|\n",new_map[j]);
//         j++;
//     }
//     return 0;
// }