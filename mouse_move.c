/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 17:45:31 by imeslaki          #+#    #+#             */
/*   Updated: 2025/08/13 19:19:09 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cube3d.h"

long	current_milliseconds(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000L) + (tv.tv_usec / 1000L);
}

void    save_mouse_stauts(int keycode)
{
    v_mouse()->save_mouse_status = v_mouse()->mouse_move;
	v_mouse()->save_mouse_event_status = keycode;
    v_mouse()->last_update_time = current_milliseconds();
    if (v_mouse()->check_mouse_sides == 0)
		v_mouse()->check_mouse_sides = 1;
}

int	mouse_move(int keycode)
{
	save_mouse_stauts(keycode);
	if (keycode < v_mouse()->mouse_move)
		v_mouse()->mouse_direction = -1;
	else if (keycode > v_mouse()->mouse_move)
		v_mouse()->mouse_direction = 1;
	else if (v_mouse()->mouse_move == keycode)
		v_mouse()->mouse_direction = 0;
	else
		v_mouse()->mouse_direction = 0;
	v_mouse()->mouse_move = keycode;
	return (0);
}

bool in_range(float start, float end, float num)
{
    return (start <= num && end >= num);
}

void	mouse_check(void)
{
	if (current_milliseconds() - v_mouse()->last_update_time > 10)
		v_mouse()->mouse_direction = 0;
	if (v_mouse()->check_mouse_sides != 0)
	{
		if (current_milliseconds() - v_mouse()->last_update_time > 10
			&& (in_range(window_width - 5, window_width, v_mouse()->mouse_move)))
			v_mouse()->mouse_direction = 1;
		else if (current_milliseconds() - v_mouse()->last_update_time > 10 && (v_mouse()->mouse_move == 0 
                && in_range(0, 9, v_mouse()->mouse_move)))
            v_mouse()->mouse_direction = -1;
	}
}
