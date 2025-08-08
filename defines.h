/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 15:31:03 by imeslaki          #+#    #+#             */
/*   Updated: 2025/08/08 23:15:28 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdbool.h> 

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

# define PLAYER_SPEED 		5
# define ROTATION_SPEED 	5
# define FOV				75
# define TILESIZE 			40
# define WALL_HIGHT         40
# define RADIUS 			TILESIZE / 10
# define window_width 		800
# define window_height 		1000
# define DEG_TO_RAD(a) ((a)*M_PI / 180.0)

# define MINI_MAP_MARGIN    50
# define MINI_MAP_W         200
# define MINI_MAP_H         MINI_MAP_W
# define MINI_MAP_R         MINI_MAP_W / 2
# define MINI_MAP_POS_X     50
# define MINI_MAP_POS_Y     MINI_MAP_POS_X
# define WALL_COLOR         0xAAAAAA
# define DOOR_COLOR         0xFF0000
# define FLOOR_COLOR        0x000FF0

# define key_Esc 			65307
# define key_up 			119
# define key_down 			115
# define key_right 			100
# define key_left 			97
# define key_rotate_right 	65363
# define key_rotate_left	65361

#endif