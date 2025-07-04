/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 16:29:02 by imeslaki          #+#    #+#             */
/*   Updated: 2025/07/04 16:53:06 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player_movement.h"



int calcul_player_x(void)
{
    return (v_player()->p_row * PIXEL);
}

int calcul_player_y(void)
{
    return (v_player()->p_col * PIXEL);
}

int	player_in_position(void)
{
	int	x;
	int	y;

	x = v_player()->p_x;
	y = v_player()->p_y;
	if (x == calcul_player_x() && y == calcul_player_y())
		return (1);
	return (0);
}

void    player_go_up(void)
{
    t_data      *data;

	data = v_data();
    if (calcul_player_y() < v_player()->p_y)
	{
		if ((v_player()->p_y - SPEED) < calcul_player_y())
			v_player()->p_y = calcul_player_y();
		else
			v_player()->p_y -= SPEED;
	}  
    data->img = mlx_new_image(data->mlx, v_map()->raw * PIXEL, v_map()->col * PIXEL);
    data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
    draw_map();
    draw_player_triangle(v_player()->p_x, v_player()->p_y);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
}


void    player_go_down(void)
{
    t_data      *data;

	data = v_data();
    if (calcul_player_y() > v_player()->p_y)
	{
        // printf("y_col = %d   y = %d\n", calcul_player_y(), v_player()->p_y);
		if ((v_player()->p_y + SPEED) > calcul_player_y())
			v_player()->p_y = calcul_player_y();
		else
			v_player()->p_y += SPEED;
	} 
    data->img = mlx_new_image(data->mlx, v_map()->raw * PIXEL, v_map()->col * PIXEL);
    data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
    draw_map();
    draw_player_triangle(v_player()->p_x, v_player()->p_y);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
    // v_player()->p_y += SPEED;
}

void    player_go_right(void)
{
    t_data      *data;

	data = v_data();
    if (calcul_player_x() > v_player()->p_x)
	{
		if ((v_player()->p_x + SPEED) > calcul_player_x())
			v_player()->p_x = calcul_player_x();
		else
			v_player()->p_x += SPEED;
	}    
    data->img = mlx_new_image(data->mlx, v_map()->raw * PIXEL, v_map()->col * PIXEL);
    data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
    draw_map();
    draw_player_triangle(v_player()->p_x, v_player()->p_y);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
}

void    player_go_left(void)
{
    t_data      *data;

	data = v_data();
    if (calcul_player_x() < v_player()->p_x)
	{
		if ((v_player()->p_x - SPEED) < calcul_player_x())
			v_player()->p_x = calcul_player_x();
		else
			v_player()->p_x -= SPEED;
	} 
    data->img = mlx_new_image(data->mlx, v_map()->raw * PIXEL, v_map()->col * PIXEL);
    data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
    draw_map();
    draw_player_triangle(v_player()->p_x, v_player()->p_y);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
}
int    player_moves_by_pixels(int *param)
{
    t_player    *player;

    (void)param;
    player = v_player();
    if (!player_in_position())
	{
		if (player->direction == 's')
			player_go_down();
		else if (player->direction == 'w')
			player_go_up();
		else if (player->direction == 'a')
			player_go_left();
		else if (player->direction == 'd')
			player_go_right();
	}
    // else
    // {
    //     draw_map();
    //     draw_player_triangle(v_player()->p_x, v_player()->p_y);
	//     mlx_put_image_to_window(v_data()->mlx, v_data()->mlx_win, v_data()->img, 0, 0);
    // }
    return 1;
}

int move_player(int key_code)
{
    t_player    *player;
    t_data *data = v_data();
    int         new_row;
    int         new_col;

    player = v_player();
    new_row = player->p_row;
    new_col = player->p_col;
    if(key_code == key_up)
    {
        v_player()->direction = 'w';
        new_col--;
    }
    else if(key_code == key_down)
    {
        v_player()->direction = 's';
        new_col++;
    }
    else if(key_code == key_right)
    {
        v_player()->direction = 'd';
        new_row++;
    }   
    else if(key_code == key_left)
    {
        v_player()->direction = 'a';
        new_row--;
    }
    printf("this first = %c\n", v_map()->map[new_col][new_row]);
    if(v_map()->map[new_col][new_row] != '1')
    {
        printf("this second = %c\n", v_map()->map[new_col][new_row]);
        v_player()->p_row = new_row;
        v_player()->p_col = new_col;
    }
    // player_moves_by_pixels();
    printf("\n           dir = %c        key = %d       \n", player->direction, key_code);
    return 1;
}
