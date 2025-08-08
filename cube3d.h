/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bann <oel-bann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 03:24:07 by oel-bann          #+#    #+#             */
/*   Updated: 2025/08/07 12:31:00 by oel-bann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
#define CUBE3D_H

# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <sys/time.h>
# include <sys/types.h>
# include "get/get_next_line.h"
#include "helper_functions/helper.h"
# include "parsing/parsing.h"
# include "map/map.h"
# include "defines.h"
# include "render3d_map/render.h"

t_data	*get_pos_img(char dir, int rotation);
t_data	* get_wall_img();
t_data	* get_floor_img();

t_map_data *get_map_info(void);
int         move_the_player(void);
void        draw_circle(double y, double x, int radius, int color);
void		draw_map(void);
void		fill_data(void);
void        draw_mini_map();



#endif