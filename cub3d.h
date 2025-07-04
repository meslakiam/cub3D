/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:31:27 by imeslaki          #+#    #+#             */
/*   Updated: 2025/07/04 19:12:38 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "garbage_collector/garbage_collector.h"
# include "helper_functions/helper.h"
# include "player_movement/player_movement.h"
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define window_width 800
# define window_height 1000
# define rotation_speed 3
# define move_speed 5
# define PIXEL 40
# define key_up 119
# define key_down 115
# define key_right 100
# define key_left 97
# define key_rotate_right 65363
# define key_rotate_left 65361
# define SPEED 2

typedef struct s_player
{
	char	**map;
	int		turn_direction;
	int		walk_direction;
	int		rotation_angle;
	char	direction;
	int		p_x;
	int		p_y;
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
}			t_data;

t_map		*v_map(void);
t_data		*v_data(void);
t_player	*v_player(void);
void		draw_player_triangle(int player_x, int player_y);
void		draw_map(void);
int			move_player(int key_code);

#endif