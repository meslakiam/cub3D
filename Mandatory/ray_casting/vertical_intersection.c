/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical_intersection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 16:51:24 by imeslaki          #+#    #+#             */
/*   Updated: 2025/08/24 21:04:12 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_casting.h"

t_ray_data	get_vertical_x_intersection(t_point start_pos, double radian,
		double step_speed)
{
	t_ray_data	vertical_hit;

	if (cos(radian) > 0)
	{
	vertical_hit.hit_point.x = floor(start_pos.x / TILESIZE) * TILESIZE
			+ TILESIZE;
		vertical_hit.step_x = step_speed;
	}
	else
	{
		vertical_hit.hit_point.x = floor(start_pos.x / TILESIZE) * TILESIZE;
		vertical_hit.step_x = -step_speed;
	}
	return (vertical_hit);
}

t_ray_data	get_vertical_y_intersection(t_point start_pos,
		t_ray_data vertical_hit, double radian, double step_speed)
{
	double	dist;

	dist = vertical_hit.hit_point.x - start_pos.x;
	vertical_hit.hit_point.y = start_pos.y + dist * tan(radian);
	vertical_hit.step_y = fabs(step_speed * tan(radian));
	if (sin(radian) < 0)
		vertical_hit.step_y *= -1;
	return (vertical_hit);
}

t_ray_data	find_vertical_intersection(t_point start_pos, double radian,
		double step_speed)
{
	t_ray_data	vertical_hit;
	int			map_x;
	int			map_y;

	vertical_hit = get_vertical_x_intersection(start_pos, radian, step_speed);
	vertical_hit = get_vertical_y_intersection(start_pos, vertical_hit, radian,
			step_speed);
	while (1)
	{
		map_y = vertical_hit.hit_point.y / TILESIZE;
		if (cos(radian) > 0)
			map_x = vertical_hit.hit_point.x / TILESIZE;
		else
			map_x = (vertical_hit.hit_point.x - 1) / TILESIZE;
		if (is_wall(map_x, map_y))
			break ;
		vertical_hit.hit_point.x += vertical_hit.step_x;
		vertical_hit.hit_point.y += vertical_hit.step_y;
	}
	vertical_hit.wall_direction = 1;
	return (vertical_hit);
}
