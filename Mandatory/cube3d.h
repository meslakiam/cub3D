/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 03:24:07 by oel-bann          #+#    #+#             */
/*   Updated: 2025/09/17 21:37:30 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include "defines.h"
# include "get/get_next_line.h"
# include "helper_functions/helper.h"
# include "parsing/parsing.h"
# include "ray_casting/ray_casting.h"
# include "render3d_map/render.h"

t_map_data	*get_map_info(void);
void		fill_data(void);
void		move_the_player(void);
void		cast_rays_and_render_game(void);

#endif