/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 18:41:43 by imeslaki          #+#    #+#             */
/*   Updated: 2025/09/17 22:20:22 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef     CUBE3D_BONUS_H
# define    CUBE3D_BONUS_H

#include "../Mandatory/player/player.h"
#include "../Mandatory/render3d_map/render.h"
#include "../Mandatory/cube3d.h"

void check_map_bonus(char *filename);
int check_component_bonus(void);
void check_texture_bonus(void);
int check_is_in_cube_faces_bonus(char *face);
void fill_cube_faces_bonus(char **splited_line);
void fill_map_infos_bonus(char *filename);
int check_closed_wall_bonus(void);


void		draw_circle(double y, double x, int radius, int color);
void		draw_mini_map(void);
void        mouse_move(void);
double      get_tex_start_bonus(int start_y, int end_y, int texture);
void		render_bonus(int ray_index, double ray_angle);
void		set_textures_bonus(void);
t_data		*get_textures_bonus(int texture);
double      get_tex_step_bonus(int texture, int ligne_h);
int			key_press_bonus(int keycode);
void		move_the_player_bonus(void);

#endif