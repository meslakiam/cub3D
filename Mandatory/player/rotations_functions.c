/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 16:44:07 by imeslaki          #+#    #+#             */
/*   Updated: 2025/09/25 21:05:51 by imeslaki         ###   ########.fr       */
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
	v_player()->rotation_angle += (double)v_mouse()->mouse_direction
	* v_mouse()->mouse_speed_anlge;
	v_mouse()->mouse_speed_anlge = 0;
	if (v_player()->rotation_angle > 360)
		v_player()->rotation_angle -= 360;
	if (v_player()->rotation_angle < 0)
		v_player()->rotation_angle += 360;
}
