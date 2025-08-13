/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 15:00:21 by imeslaki          #+#    #+#             */
/*   Updated: 2025/08/13 16:55:51 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_CASTING_H
# define RAY_CASTING_H

# include "../cube3d.h"
# include "../defines.h"

typedef struct s_point
{
	double	x;
	double	y;
}			t_point;

typedef struct s_ray_data
{
	t_point	hit_point;
	double	step_x;
	double	step_y;
	int		wall_direction;
}			t_ray_data;

typedef struct s_ray_info
{
	int		num_of_rays;
	double	ray_angle;
}			t_ray_info;

t_ray_info	get_ray_info(void);
t_ray_data	cast_ray(t_point start_pos, double angle, double step_speed);
void		ray_casting_update_p(double angle);
t_ray_data	find_horizontal_intersection(t_point start_pos, double radian,
				double step_speed);
t_ray_data	find_vertical_intersection(t_point start_pos, double radian,
				double step_speed);

#endif