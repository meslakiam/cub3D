/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 13:56:40 by imeslaki          #+#    #+#             */
/*   Updated: 2025/08/14 17:04:18 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include "../cube3d.h"
# include "../defines.h"

typedef struct s_player
{
	char	direction;
	double	rotation_radian_angle;
	double	rotation_angle;
	double	walk_direction;
	double	turn_direction;
	double	side_direction;
	double	save_x;
	double	save_y;
	double	p_x;
	double	p_y;
	double	end_p_x;
	double	end_p_y;
	int		was_hit_vertical;
}			t_player;

t_player	*v_player(void);
void		init_player(void);

int			check_wall_y(double x1, double y1, double angle, int d);
int			check_wall_x(double x1, double y1, double angle, int d);
int			is_wall(int map_x, int map_y);

double		distance(double x1, double y1, double x2, double y2);
double		distance_from_player(double x2, double y2);

int			key_press(int keycode);
int			key_release(int keycode);

void		move_the_player(void);
void		rotate_player(void);
void		mouse_rotation(void);

#endif