/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 15:31:03 by imeslaki          #+#    #+#             */
/*   Updated: 2025/07/20 20:04:31 by imeslaki         ###   ########.fr       */
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
# include "garbage_collector/garbage_collector.h"
# include "helper_functions/helper.h"

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

# define PLAYER_SPEED 		1
# define ROTATION_SPEED 	0.5
# define FOV				45
# define TILESIZE 			40
# define RADIUS 			TILESIZE / 10
# define window_width 		800
# define window_height 		1000
# define DEG_TO_RAD(a) ((a)*M_PI / 180.0)


# define key_Esc 			65307
# define key_up 			119
# define key_down 			115
# define key_right 			100
# define key_left 			97
# define key_rotate_right 	65363
# define key_rotate_left	65361

#endif