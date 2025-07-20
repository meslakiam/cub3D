/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 03:24:07 by oel-bann          #+#    #+#             */
/*   Updated: 2025/07/19 20:00:16 by imeslaki         ###   ########.fr       */
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
#include "../helper_functions/helper.h"
# include "parsing/parsing.h"
# include "map/map.h"
# include "defines.h"



typedef struct s_global
{
	void	*mlx;
	void	*mlx_win;
	int		win_width;
	int		win_height;
	t_data	*win_img;
}			t_global;


int		my_mlx_get_pixel_color(t_data *data, int x, int y);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
t_data	*get_pos_img(char dir, int rotation);
t_data	* get_wall_img();
t_data	* get_floor_img();


t_global   *v_global(void);
t_map_data *get_map_info(void);
int         move_the_player(void);
void        draw_circle(double y, double x, int radius, int color);
void		draw_map(void);
void		fill_data(void);



#endif