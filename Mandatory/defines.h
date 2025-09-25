/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 15:31:03 by imeslaki          #+#    #+#             */
/*   Updated: 2025/09/25 22:11:59 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <sys/types.h>
# include <unistd.h>

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

# define WINDOW_HEIGHT 1080
# define WINDOW_WIDTH 1920

# define ROTATION_SPEED 4
# define PLAYER_SPEED 3

# define FOV 75
# define TILESIZE 20
# define WALL_HIGHT 20
# define PLAYER_RADIUS 2
# define RADIUS 2

# define MINI_MAP_MAR 50
# define MINI_MAP_W 200
# define MINI_MAP_H MINI_MAP_W
# define MINI_MAP_POS_X 50
# define MINI_MAP_POS_Y MINI_MAP_POS_X
# define WALL_COLOR 0xAAAAAA
# define FLOOR_COLOR 0x000FF0
# define CLOSE_DOOR_COLOR 0x8B0000
# define OPEN_DOOR_COLOR 0x228B22

# define REDOT 2

# define KEY_MOUSE_ON_OFF 32
# define KEY_DOOR 101
# define MOUSE_LEFT_KEY 1
# define KEY_ESC 65307
# define KEY_UP 119
# define KEY_DOWN 115
# define KEY_RIGHT 100
# define KEY_LEFT 97
# define KEY_ROTATE_RIGHT 65363
# define KEY_ROTATE_LEFT 65361

#endif