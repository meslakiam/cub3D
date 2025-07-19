/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bann <oel-bann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 03:24:07 by oel-bann          #+#    #+#             */
/*   Updated: 2025/07/19 15:54:35 by oel-bann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
#define CUBE3D_H

# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>
# include <string.h>
# include <unistd.h>
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <sys/types.h>
# include "get/get_next_line.h"
# include "ft_func/ft_func.h"
# include "parsing/parsing.h"

# define CELL_H 40
# define CELL_W 40

typedef struct s_vars
{
	void			*mlx;
	void			*win;
}					t_vars;

typedef enum {
    no_mask            = 0L,
    key_press          = (1L << 0),
    key_release        = (1L << 1),
    btn_press          = (1L << 2),
    btn_release        = (1L << 3),
    enter_win          = (1L << 4),
    leave_win          = (1L << 5),
    ptr_motion         = (1L << 6),
    ptr_motion_hint    = (1L << 7),
    btn1_motion        = (1L << 8),
    btn2_motion        = (1L << 9),
    btn3_motion        = (1L << 10),
    btn4_motion        = (1L << 11),
    btn5_motion        = (1L << 12),
    btn_motion         = (1L << 13),
    keymap_state       = (1L << 14),
    expose             = (1L << 15),
    visibility         = (1L << 16),
    structure_notify   = (1L << 17),
    resize_redirect    = (1L << 18),
    sub_notify         = (1L << 19),
    sub_redirect       = (1L << 20),
    focus_change       = (1L << 21),
    property_change    = (1L << 22),
    colormap_change    = (1L << 23),
    owner_grab         = (1L << 24)
} evt_mask_t;

typedef enum s_events
{
	on_keydown = 2,
	on_keyup = 3,
	on_mousedown = 4,
	on_mouseup = 5,
	on_mousemove = 6,
	on_expose = 12,
	on_destroy = 17
}					t_events;

void	**g_mlx(void);
void	**g_window(void);
void	draw_map();
int		my_mlx_get_pixel_color(t_data *data, int x, int y);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
t_data	*get_pos_img(char dir, int rotation);
t_data	* get_wall_img();
t_data	* get_floor_img();

#endif