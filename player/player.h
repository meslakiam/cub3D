/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 13:56:40 by imeslaki          #+#    #+#             */
/*   Updated: 2025/08/12 17:17:16 by imeslaki         ###   ########.fr       */
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





// t_map   *v_map(void);
// t_data		*v_data(void);

t_player	*v_player(void);

int 		check_wall_y(double x1, double y1, double angle, int d);
int 		check_wall_x(double x1, double y1, double angle, int d);
double 		distance_from_player(double x2, double y2);
int			is_wall(int map_x, int map_y);
int			key_press(int keycode);
int			key_release(int keycode);
void		move_the_player(void);

void		init_player(void);
#endif