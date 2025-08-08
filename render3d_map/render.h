/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bann <oel-bann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 19:24:32 by oel-bann          #+#    #+#             */
/*   Updated: 2025/08/05 19:34:01 by oel-bann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
#define RENDER_H

# include "../helper_functions/helper.h"
# include "../player/player.h"

void		render_floor_and_sky();
void		render(int ray_index, double ray_angle);
void		set_textures();
int         is_map_corners();

t_data		*get_textures(int texture);
double      get_tex_step(int texture, int animation, int ligne_h);
double      get_tex_start(int start_y, int end_y, int texture, int animation);
double      get_tex_end(int start_y, int end_y, int texture, int animation);
double		get_img_start_w(int img_w);
t_data      *get_animation_wall(int set, int wall_tex);
t_data_list *get_west_torch_lst();
t_data_list *get_east_torch_lst();


#endif