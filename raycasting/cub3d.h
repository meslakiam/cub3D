/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:31:27 by imeslaki          #+#    #+#             */
/*   Updated: 2025/07/11 16:24:56 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../garbage_collector/garbage_collector.h"
# include "../helper_functions/helper.h"
# include "player_movement/player_movement.h"
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

# define FOV				45
# define PIXEL 				40
# define RADIUS 			PIXEL / 10
# define window_width 		800
# define window_height 		1000
# define move_speed 		5
# define key_Esc 			65307
# define key_up 			119
# define key_down 			115
# define key_right 			100
# define key_left 			97
# define key_rotate_right 	65363
# define key_rotate_left	65361
# define SPEED 				1
# define ROTATION_SPEED 	1

# define DEG_TO_RAD(a) ((a)*M_PI / 180.0)

typedef struct s_player
{
	char	**map;
	char	direction;
	int		dir;
	double	rotation_radian_angle;
	double	rotation_angle;
	int		walk_direction;
	int		turn_direction;
	int		side_direction;
	double	p_x;
	double	p_y;
	int		end_p_x;
	int		end_p_y;
	int		p_col;
	int		p_row;
}			t_player;

typedef struct s_map
{
	char	**map;
	int		col;
	int		raw;
	int		x;
	int		y;
}			t_map;

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

t_map		*v_map(void);
t_data		*v_data(void);
t_player	*v_player(void);
void		draw_map(void);
int			move_player(int key_code);
void		fill_data(void);
void		draw_square(int y, int x, int color);
void		draw_filled_circle(double center_y, double center_x, int radius,
				int color);
double		draw_line(int x0, int y0, int x1, int y1, int color);
void		draw_pixel(int y, int x, int color);

#endif