/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 15:31:03 by imeslaki          #+#    #+#             */
/*   Updated: 2025/09/16 18:09:25 by imeslaki         ###   ########.fr       */
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
# include <stdint.h>
# include <fcntl.h>
# include <sys/types.h>

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

# define window_height      1080
# define window_width       1920

# define MOUSE_ROTATION_SPEED(a) (a / 10)
# define ROTATION_SPEED 	4
# define PLAYER_SPEED 		3


# define FOV				75
# define TILESIZE 			20
# define WALL_HIGHT         20
#define PLAYER_RADIUS       2
# define RADIUS 			TILESIZE / 10
# define DEG_TO_RAD(a) ((a)*M_PI / 180.0)

# define MINI_MAP_MARGIN    50
# define MINI_MAP_W         200
# define MINI_MAP_H         MINI_MAP_W
# define MINI_MAP_R         MINI_MAP_W / 2
# define MINI_MAP_POS_X     50
# define MINI_MAP_POS_Y     MINI_MAP_POS_X
# define WALL_COLOR         0xAAAAAA
# define FLOOR_COLOR        0x000FF0
# define CLOSE_DOOR_COLOR   0x8B0000
# define OPEN_DOOR_COLOR    0x228B22

# define key_mouse_on_off   32
# define key_door           101
# define key_Esc 			65307
# define key_up 			119
# define key_down 			115
# define key_right 			100
# define key_left 			97
# define key_rotate_right 	65363
# define key_rotate_left	65361

#endif