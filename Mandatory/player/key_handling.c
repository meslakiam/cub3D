/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 13:56:01 by imeslaki          #+#    #+#             */
/*   Updated: 2025/09/25 21:05:35 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

int	destroy_window(void *param)
{
	(void)param;
	mlx_destroy_image(v_global()->mlx, v_global()->win_img->img);
	free(v_global()->win_img);
	mlx_destroy_window(v_global()->mlx, v_global()->mlx_win);
	if (v_global()->mlx)
		mlx_destroy_display(v_global()->mlx);
	free(v_global()->mlx);
	exit(0);
	return (0);
}

int	key_press(int keycode)
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
	return (0);
}

int	key_release(int keycode)
{
	if (keycode == KEY_ROTATE_RIGHT || keycode == KEY_ROTATE_LEFT)
		v_player()->turn_direction = 0;
	if (keycode == KEY_UP || keycode == KEY_DOWN)
		v_player()->walk_direction = 0;
	if (keycode == KEY_RIGHT || keycode == KEY_LEFT)
		v_player()->side_direction = 0;
	return (0);
}
