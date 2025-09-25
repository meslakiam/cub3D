/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_move_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bann <oel-bann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 17:45:31 by imeslaki          #+#    #+#             */
/*   Updated: 2025/09/25 01:30:29 by oel-bann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d_bonus.h"

void	mouse_move(void)
{
	int 	x;
	int		y;
	double	dist_x;
	t_point	center_of_map;

	if(!v_mouse()->use_mouse)
	{
		v_mouse()->mouse_direction = 0;
		return ;
	}
	center_of_map.x = WINDOW_WIDTH / 2;
	center_of_map.y = WINDOW_HEIGHT / 2;
	mlx_mouse_get_pos(v_global()->mlx, v_global()->mlx_win, &x, &y);
	dist_x = (double)x - center_of_map.x;
	v_mouse()->mouse_speed_anlge =  fabs(MOUSE_ROTATION_SPEED(dist_x));
	if(x > center_of_map.x)
		v_mouse()->mouse_direction = 1;
	else if(x < center_of_map.x)
		v_mouse()->mouse_direction = -1;
	else
		v_mouse()->mouse_direction = 0;
	mlx_mouse_move(v_global()->mlx, v_global()->mlx_win, center_of_map.x, center_of_map.y);
	mlx_mouse_get_pos(v_global()->mlx, v_global()->mlx_win, &x, &y);
}
