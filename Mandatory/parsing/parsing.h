/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bann <oel-bann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 19:12:16 by oel-bann          #+#    #+#             */
/*   Updated: 2025/09/25 01:01:17 by oel-bann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../get/get_next_line.h"
# include "../helper_functions/helper.h"

typedef struct s_map_data
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*door;
	char	*floor_rgb;
	char	*cell_rgb;
	int		*f_rgb_tab;
	int		*c_rgb_tab;
	int		player_x;
	int		player_y;
	int		win_h;
	int		win_w;
	char	direction;
	t_map	**map;
}			t_map_data;

t_map_data	*get_map_info(void);
int			*get_all_filled(void);
t_map		**get_map(void);
void		get_map_width(void);
char		**get_final_map(int set, char **map);
int			get_map_hight(int set);
int			check_all_filled(void);
int			check_is_in_cube_faces(char *face);
void		fill_cube_faces(char **splited_line);
void		check_texture(void);
int			is_newline(char *str);
void		remove_extra_from_map(void);
char		**flood_fill_map(void);
void		flood_fill(char **map, int x, int y);

int			check_ext_isvalid(char *file_name);
int			check_component(void);
int			check_closed_wall(void);
void		check_texture(void);
void		fill_map_infos(char *filename);
void		check_map(char *filename);
void		check_floor_cell_rgb(void);
void		fill_map(char *str, int fd);
void		get_player_pos(char **map_c);
void		print_not_closed_map(void);

#endif