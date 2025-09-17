/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 14:02:21 by imeslaki          #+#    #+#             */
/*   Updated: 2025/09/17 21:41:33 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

void	update_player_position(double angle)
{
	t_ray_data	hit_wall;
	t_point		player_pos;
	double		radian;
	int			dist;

	player_pos.x = v_player()->p_x;
	player_pos.y = v_player()->p_y;
	hit_wall = cast_ray(player_pos, angle, 1);
	dist = distance_from_player(hit_wall.hit_point.x, hit_wall.hit_point.y);
	radian = DEG_TO_RAD(angle);
	if (dist > PLAYER_SPEED)
		dist = PLAYER_SPEED;
	if (!check_wall(v_player()->save_x, v_player()->save_y, angle, dist))
	{
		v_player()->save_x += dist * cos(radian);
		v_player()->save_y += dist * sin(radian);
	}
}

void	player_move_straight_walk(void)
{
	double	angle;

	angle = v_player()->rotation_angle;
	if (v_player()->walk_direction == -1)
	{
		angle += 180;
		if (angle > 360)
			angle -= 360;
		update_player_position(angle);
	}
	else
		update_player_position(angle);
}

void	player_move_side_walk(void)
{
	double	angle;

	angle = v_player()->rotation_angle + 90;
	if (v_player()->side_direction == -1)
	{
		angle += 180;
		if (angle > 360)
			angle -= 360;
		update_player_position(angle);
	}
	else
		update_player_position(angle);
}

void	move_the_player(void)
{
	v_player()->save_x = v_player()->p_x;
	v_player()->save_y = v_player()->p_y;
	if (v_player()->turn_direction != 0)
		rotate_player();
	if (v_mouse()->mouse_direction != 0)
		mouse_rotation();
	if (v_player()->walk_direction != 0)
		player_move_straight_walk();
	if (v_player()->side_direction != 0)
		player_move_side_walk();
	v_player()->p_x = v_player()->save_x;
	v_player()->p_y = v_player()->save_y;
}
