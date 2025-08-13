/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal_intersection.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 16:51:46 by imeslaki          #+#    #+#             */
/*   Updated: 2025/08/13 16:54:59 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_casting.h"

t_ray_data	get_horizontal_y_intersection(t_point start_pos, double radian,
		double step_speed)
{
	t_ray_data	horizontal_hit;

	if (sin(radian) > 0)
	{
		horizontal_hit.hit_point.y = floor(start_pos.y / TILESIZE) * TILESIZE
			+ TILESIZE;
		horizontal_hit.step_y = step_speed;
	}
	else
	{
		horizontal_hit.hit_point.y = floor(start_pos.y / TILESIZE) * TILESIZE;
		horizontal_hit.step_y = -step_speed;
	}
	return (horizontal_hit);
}

t_ray_data	get_horizontal_x_intersection(t_point start_pos,
		t_ray_data horizontal_hit, double radian, double step_speed)
{
	double	dist;

	dist = horizontal_hit.hit_point.y - start_pos.y;
	horizontal_hit.hit_point.x = start_pos.x + dist / tan(radian);
	horizontal_hit.step_x = fabs((double)step_speed / tan(radian));
	if (cos(radian) < 0)
		horizontal_hit.step_x *= -1;
	return (horizontal_hit);
}

t_ray_data	find_horizontal_intersection(t_point start_pos, double radian,
		double step_speed)
{
	t_ray_data	horizontal_hit;
	int			map_x;
	int			map_y;

	horizontal_hit = get_horizontal_y_intersection(start_pos, radian,
			step_speed);
	horizontal_hit = get_horizontal_x_intersection(start_pos, horizontal_hit,
			radian, step_speed);
	while (1)
	{
		map_x = horizontal_hit.hit_point.x / TILESIZE;
		if (sin(radian) > 0)
			map_y = horizontal_hit.hit_point.y / TILESIZE;
		else
			map_y = (horizontal_hit.hit_point.y - 1) / TILESIZE;
		if (is_wall(map_x, map_y))
			break ;
		horizontal_hit.hit_point.x += horizontal_hit.step_x;
		horizontal_hit.hit_point.y += horizontal_hit.step_y;
	}
	horizontal_hit.wall_direction = 0;
	return (horizontal_hit);
}
