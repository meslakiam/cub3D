/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew _ray.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bann <oel-bann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 03:51:47 by oel-bann          #+#    #+#             */
/*   Updated: 2025/07/31 06:49:57 by oel-bann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helper.h"

t_rays_data	*ft_lstnew_ray(int r_dis, int ray_ang, double end_x_y)
{
	t_rays_data	*node;

	node = (t_rays_data *)ft_calloc(1, sizeof(t_rays_data));
	if (!node)
		return (NULL);
	node->ray_distance = r_dis;
	node->ray_angle = ray_ang;
    node->end_x_y = end_x_y;
	node->next = NULL;
	return (node);
}
