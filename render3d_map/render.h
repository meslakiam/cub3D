/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bann <oel-bann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 19:24:32 by oel-bann          #+#    #+#             */
/*   Updated: 2025/08/03 02:29:27 by oel-bann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
#define RENDER_H

# include "../helper_functions/helper.h"
# include "../player/player.h"

typedef enum e_texture
{
	TEX_WEST = 1,
	TEX_EAST = 2,
	TEX_NORTH = 3,
	TEX_SOUTH = 4
} e_tex;

void		render_floor_and_sky();
void		render(int ray_index, double ray_angle);
void		set_textures();

t_data		*get_textures(int texture);
double		get_tex_step(int texture, int ligne_h);
double		get_tex_start(int start_y, int end_y, int texture);
double		get_tex_end(int start_y, int end_y, int texture);
double		get_img_start_w(int img_w);


#endif