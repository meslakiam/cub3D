/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bann <oel-bann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 14:59:51 by imeslaki          #+#    #+#             */
/*   Updated: 2025/09/25 01:26:12 by oel-bann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_casting.h"

double	distance(double x1, double y1, double x2, double y2)
{
	double	dx;
	double	dy;

	dx = x1 - x2;
	dy = y1 - y2;
	return (sqrt(dx * dx + dy * dy));
}

	double	distance_from_player(double x2, double y2)
{
	double	dx;
	double	dy;

	dx = v_player()->p_x - x2;
	dy = v_player()->p_y - y2;
	return (sqrt(dx * dx + dy * dy));
}

t_ray_info	get_ray_info(void)
{
	t_ray_info	ray;
	double		player_angle;
	double		half_fov;

	ray.num_of_rays = WINDOW_WIDTH;
	player_angle = v_player()->rotation_angle;
	half_fov = FOV / 2;
	ray.ray_angle = player_angle - half_fov;
	return (ray);
}
