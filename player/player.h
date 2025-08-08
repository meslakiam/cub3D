/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 13:56:40 by imeslaki          #+#    #+#             */
/*   Updated: 2025/08/08 23:10:12 by imeslaki         ###   ########.fr       */
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
	int		p_col;
	int		p_row;
	double	x_step_v;
	double	y_step_v;
	double	x_step_h;
	double	y_step_h;
	
}			t_player;

// typedef	struct s_step
// {
// 	double	x;
// 	double	y;
// }			t_step;

typedef	struct s_point
{
	double	x;
	double	y;
}			t_point;

typedef struct s_ray_data
{
	t_point	hit_point;
	double	angle;
	t_point  step;
}			t_ray_data;

// typedef struct s_data t_data;
// typedef struct s_map t_map;

// t_map   *v_map(void);
// t_data		*v_data(void);
t_player	*v_player(void);

double		distance(double x2, double y2);
int			is_wall(int map_x, int map_y);
int			key_press(int keycode);
int			key_release(int keycode);
int			move_the_player(void);
void		cast_ray(double angle);
#endif