/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:31:27 by imeslaki          #+#    #+#             */
/*   Updated: 2025/07/16 16:34:45 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdbool.h> 
# include "garbage_collector/garbage_collector.h"
# include "helper_functions/helper.h"
// # include "player/player.h"
# include "map/map.h"
# include "defines.h"
// # include "ray_casting/ray_casting.h"



typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		win_width;
	int		win_height;
}			t_data;



//          global
t_data		*v_data(void);
int    move_the_player(void);
void        draw_circle(double y, double x, int radius, int color);
void		draw_map(void);
void		fill_data(void);












// double  normalize_angle(double anlge);
// int			move_player(int key_code);
// void		draw_square(int y, int x, int color);
// double		draw_line(int x0, int y0, int x1, int y1, int color);
// void		draw_pixel(int y, int x, int color);

#endif