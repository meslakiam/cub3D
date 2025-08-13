/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 23:08:49 by imeslaki          #+#    #+#             */
/*   Updated: 2025/08/13 16:55:56 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_casting.h"

t_ray_data	cast_ray(t_point start_pos, double angle, double step_speed)
{
	double		radian;
	double		dist_vert;
	double		dist_hor;
	t_ray_data	horizontal_hit;
	t_ray_data	vertical_hit;

	radian = angle * (M_PI / 180.0);
	vertical_hit = find_vertical_intersection(start_pos, radian, step_speed);
	horizontal_hit = find_horizontal_intersection(start_pos, radian,
			step_speed);
	dist_vert = distance_from_player(vertical_hit.hit_point.x,
			vertical_hit.hit_point.y);
	dist_hor = distance_from_player(horizontal_hit.hit_point.x,
			horizontal_hit.hit_point.y);
	if (dist_vert < dist_hor)
		return (vertical_hit);
	else
		return (horizontal_hit);
}

void	ray_casting_update_p(double angle)
{
	t_point		player_pos;
	t_ray_data	hit_position;

	player_pos.x = v_player()->p_x;
	player_pos.y = v_player()->p_y;
	hit_position = cast_ray(player_pos, angle, TILESIZE);
	v_player()->was_hit_vertical = hit_position.wall_direction;
	v_player()->end_p_x = hit_position.hit_point.x;
	v_player()->end_p_y = hit_position.hit_point.y;
}
