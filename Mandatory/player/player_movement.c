/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 14:02:21 by imeslaki          #+#    #+#             */
/*   Updated: 2025/09/17 18:14:50 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

// void frames()
// {
//     static struct timeval start;
//     struct timeval now;
//     static int count;
//     long time;

//     if (!count)
//         gettimeofday(&start, NULL);

//     if (print_time(start))
//     {
//         printf("%d frame/sec\n", count);
//         count = 0;
//     }
//     else
//     {
//         gettimeofday(&now, NULL);
//         int turn_time = 1000000/30;
//         long time_paste = (now.tv_sec * 1000000 + now.tv_usec)
//	- (start.tv_sec * 1000000 + start.tv_usec);
//         long time_of_this_tour = (turn_time * (count + 1));
//         time = time_of_this_tour - time_paste;
//         if (time > 0 && time_paste)
//         {
//             usleep(time);
//         }
//         count++;
//     }
// }

void	update_player_position(double x1, double y1, double angle)
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
		update_player_position(v_player()->p_x, v_player()->p_y, angle);
	}
	else
		update_player_position(v_player()->p_x, v_player()->p_y, angle);
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
		update_player_position(v_player()->p_x, v_player()->p_y, angle);
	}
	else
		update_player_position(v_player()->p_x, v_player()->p_y, angle);
}

void	move_the_player(void)
{
	double	new_x;
	double	new_y;

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
