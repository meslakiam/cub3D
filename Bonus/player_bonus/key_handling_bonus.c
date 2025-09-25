/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handling_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 13:56:01 by imeslaki          #+#    #+#             */
/*   Updated: 2025/09/25 21:40:41 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d_bonus.h"

void	door_and_mouse_key_press(int keycode)
{
	int	x;
	int	y;

	x = v_player()->p_x / TILESIZE;
	y = v_player()->p_y / TILESIZE;
	if (keycode == KEY_DOOR)
	{
		if (is_closed_door())
			;
		else if (is_open_door())
			;
	}
	if (keycode == KEY_MOUSE_ON_OFF && v_mouse()->use_mouse)
		v_mouse()->use_mouse = 0;
	else if (keycode == KEY_MOUSE_ON_OFF && !v_mouse()->use_mouse)
	{
		mlx_mouse_move(v_global()->mlx, v_global()->mlx_win, WINDOW_WIDTH / 2,
			WINDOW_HEIGHT / 2);
		v_mouse()->use_mouse = 1;
	}
}

int	mouse_hook(int button, int x, int y, void *param)
{
	(void)x;
	(void)y;
	(void)param;
	if (button == MOUSE_LEFT_KEY)
	{
		v_player()->fire = 1;
	}
	return (0);
}

int	key_press_bonus(int keycode)
{
	if (keycode == KEY_ESC)
		ft_exit(0);
	if (keycode == KEY_ROTATE_RIGHT)
		v_player()->turn_direction = 1;
	if (keycode == KEY_ROTATE_LEFT)
		v_player()->turn_direction = -1;
	if (keycode == KEY_UP)
		v_player()->walk_direction = 1;
	if (keycode == KEY_DOWN)
		v_player()->walk_direction = -1;
	if (keycode == KEY_RIGHT)
		v_player()->side_direction = 1;
	if (keycode == KEY_LEFT)
		v_player()->side_direction = -1;
	door_and_mouse_key_press(keycode);
	return (0);
}
