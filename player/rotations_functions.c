/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 16:44:07 by imeslaki          #+#    #+#             */
/*   Updated: 2025/08/14 18:53:12 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

void	rotate_player(void)
{
	v_player()->rotation_angle += (double)v_player()->turn_direction
		* ROTATION_SPEED;
	if (v_player()->rotation_angle > 360)
		v_player()->rotation_angle -= 360;
	if (v_player()->rotation_angle < 0)
		v_player()->rotation_angle += 360;
}

void	mouse_rotation(void)
{
	double mouse_speed;

	// mouse_speed = v_mouse()->mouse_speed_anlge;
	// if(mouse_speed >= 3  && mouse_speed < 10)
	// 	v_mouse()->mouse_speed_anlge = 3.05;
	// else if(mouse_speed >= 10 && mouse_speed < 20)
	// 	v_mouse()->mouse_speed_anlge = 6.05;
	// else if(mouse_speed >= 20 && mouse_speed < 40)
	// 	v_mouse()->mouse_speed_anlge = 10.05;
	// else if(mouse_speed >= 40 && mouse_speed < 70)
	// 	v_mouse()->mouse_speed_anlge = 15.05;
	// else if(mouse_speed >= 70 )
	// 	v_mouse()->mouse_speed_anlge = 20.05;
	
		// v_mouse()->mouse_speed_anlge = 0.015;
	v_player()->rotation_angle += (double)v_mouse()->mouse_direction * v_mouse()->mouse_speed_anlge;
	v_mouse()->mouse_speed_anlge = 0;
	if (v_player()->rotation_angle > 360)
		v_player()->rotation_angle -= 360;
	if (v_player()->rotation_angle < 0)
	v_player()->rotation_angle += 360;
}
