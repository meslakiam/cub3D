/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 19:24:32 by oel-bann          #+#    #+#             */
/*   Updated: 2025/09/17 21:36:49 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
#define RENDER_H

# include "../helper_functions/helper.h"
# include "../player/player.h"

void		render_floor_and_sky();
void		render(int ray_index, double ray_angle);
void		set_textures(void);

t_data		*get_textures(int texture);
double      get_tex_step(int texture, int ligne_h);
double      get_tex_start(int start_y, int end_y, int texture);
double      get_tex_end(int start_y, int end_y, int texture);
double		get_img_start_w(int img_w);
t_data_list	*get_door_imgs(int flag);
void        draw_pixel_depend_distance(int y, int x, int color);
int         get_wall_strip_hight(int r_angle);

#endif