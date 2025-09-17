/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 19:12:16 by oel-bann          #+#    #+#             */
/*   Updated: 2025/08/16 17:09:00 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
#define PARSING_H

#include "../helper_functions/helper.h"
#include "../get/get_next_line.h"


typedef struct s_map_data
{
    char    *no;
    char    *so;
    char    *we;
    char    *ea;
    char    *door;
    char    *floor_rgb;
    char    *cell_rgb;
    int     *f_rgb_tab;
    int     *c_rgb_tab;
    int     player_x;
    int     player_y;
    int     win_h;
    int     win_w;
    char    direction;
    t_map   **map;
} t_map_data;

t_map_data  *get_map_info();
int			*get_all_filled();
t_map		**get_map();
void        get_map_width();
char        **get_final_map(int set, char **map);
int         get_map_hight(int set);
int         check_all_filled();
int         check_is_in_cube_faces(char *face);
void        fill_cube_faces(char **splited_line);
void        check_texture();
int         is_newline(char *str);
void        remove_extra_from_map();
char        **flood_fill_map();
void		flood_fill(char **map, int x, int y);

int         check_ext_isvalid(char *file_name);
int         check_component();
int         check_closed_wall();
void        check_texture();
void        fill_map_infos(char *filename);
void        check_map(char *filename);

#endif