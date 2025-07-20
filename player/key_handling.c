/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 13:56:01 by imeslaki          #+#    #+#             */
/*   Updated: 2025/07/20 20:23:57 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

int	key_press(int keycode)
{
	if (keycode == key_Esc)
		exit(0);
	if (keycode == key_rotate_right)
		v_player()->turn_direction = 1;
	if (keycode == key_rotate_left)
		v_player()->turn_direction = -1;
	if (keycode == key_up)
		v_player()->walk_direction = 1;
	if (keycode == key_down)
		v_player()->walk_direction = -1;
	if (keycode == key_right)
		v_player()->side_direction = 1;
	if (keycode == key_left)
		v_player()->side_direction = -1;
	return (0);
}

int	key_release(int keycode)
{
	if (keycode == key_rotate_right || keycode == key_rotate_left)
		v_player()->turn_direction = 0;
	if (keycode == key_up || keycode == key_down)
		v_player()->walk_direction = 0;
	if (keycode == key_right || keycode == key_left)
		v_player()->side_direction = 0;
	return (0);
}
