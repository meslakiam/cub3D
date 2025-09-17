/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handling_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 13:56:01 by imeslaki          #+#    #+#             */
/*   Updated: 2025/09/17 20:57:52 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d_bonus.h"

int	is_closed_door(void)
{
	int	x;
	int	y;

	x = v_player()->p_x / TILESIZE;
	y = v_player()->p_y / TILESIZE;
	if(get_final_map(0, 0)[y + 1][x] == 'D')
	{
		get_final_map(0, 0)[y + 1][x] = 'O';
		return 1;
	}
	if(get_final_map(0, 0)[y][x + 1] == 'D')
	{
		get_final_map(0, 0)[y][x + 1] = 'O';
		return 1;
	}
	if(get_final_map(0, 0)[y - 1][x] == 'D')
	{
		get_final_map(0, 0)[y - 1][x] = 'O';
		return 1;
	}
	if(get_final_map(0, 0)[y][x - 1] == 'D')
	{
		get_final_map(0, 0)[y][x - 1] = 'O';
		return 1;
	}
	return 0;	
}

int	is_open_door(void)
{
	int	x;
	int	y;

	x = v_player()->p_x / TILESIZE;
	y = v_player()->p_y / TILESIZE;
	if(get_final_map(0, 0)[y + 1][x] == 'O')
	{	
		get_final_map(0, 0)[y + 1][x] = 'D';
		return 1;
	}
	if(get_final_map(0, 0)[y][x + 1] == 'O')
	{
		get_final_map(0, 0)[y][x + 1] = 'D';
		return 1;
	}
	if(get_final_map(0, 0)[y - 1][x] == 'O')
	{	
		get_final_map(0, 0)[y - 1][x] = 'D';
		return 1;
	}
	if(get_final_map(0, 0)[y][x - 1] == 'O')
	{
		get_final_map(0, 0)[y][x - 1] = 'D';
		return 1;
	}
	return 0;
}

void	door_and_mouse_key_press(int keycode)
{
	int	x;
	int	y;

	x = v_player()->p_x / TILESIZE;
	y = v_player()->p_y / TILESIZE;
	if(keycode == key_door)
	{
		if(is_closed_door())
			;
		else if (is_open_door())
			;
	}
	if(keycode == key_mouse_on_off && v_mouse()->use_mouse)
		v_mouse()->use_mouse = 0;
	else if(keycode == key_mouse_on_off && !v_mouse()->use_mouse)
	{
		mlx_mouse_move(v_global()->mlx, v_global()->mlx_win, window_width / 2,
				window_height / 2);
		v_mouse()->use_mouse = 1;
	}
}

int	key_press_bonus(int keycode)
{
	if (keycode == key_Esc)
		ft_exit(0);
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
	door_and_mouse_key_press(keycode);
	return (0);
}
