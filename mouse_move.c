/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 17:45:31 by imeslaki          #+#    #+#             */
/*   Updated: 2025/08/14 19:31:48 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cube3d.h"

void	mouse_move(void)
{
	int x;
	int y;
	t_point	center_of_map;
	double dist_x;

	center_of_map.x = window_width / 2;
	center_of_map.y = window_height / 2;
	mlx_mouse_get_pos(v_global()->mlx, v_global()->mlx_win, &x, &y);
	dist_x = (double)x - center_of_map.x;
	v_mouse()->mouse_speed_anlge =  fabs(MOUSE_ROTATION_SPEED(dist_x));
	if(x > center_of_map.x)
		v_mouse()->mouse_direction = 1;
	else if(x < center_of_map.x)
		v_mouse()->mouse_direction = -1;
	else
		v_mouse()->mouse_direction = 0;
	printf("%d\n", v_mouse()->mouse_direction);
	mlx_mouse_move(v_global()->mlx, v_global()->mlx_win, center_of_map.x, center_of_map.y);
	mlx_mouse_get_pos(v_global()->mlx, v_global()->mlx_win, &x, &y);
}
