/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 14:59:51 by imeslaki          #+#    #+#             */
/*   Updated: 2025/08/09 15:00:13 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_casting.h"

t_ray_info  get_ray_info(void)
{
    t_ray_info  ray;
    double  player_angle;
    double  half_fov;

    ray.num_of_rays = window_width;
    player_angle = v_player()->rotation_angle;
    half_fov = FOV / 2;
    ray.ray_angle = player_angle - half_fov;
    set_textures();
    get_animation_wall(1, 0);
    return (ray);
}
