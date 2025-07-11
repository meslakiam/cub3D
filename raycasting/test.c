// // /* ************************************************************************** */
// // /*                                                                            */
// // /*                                                        :::      ::::::::   */
// // /*   main.c                                             :+:      :+:    :+:   */
// // /*                                                    +:+ +:+         +:+     */
// // /*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
// // /*                                                +#+#+#+#+#+   +#+           */
// // /*   Created: 2025/07/01 15:51:07 by imeslaki          #+#    #+#             */
// // /*   Updated: 2025/07/04 17:09:53 by imeslaki         ###   ########.fr       */
// // /*                                                                            */
// // /* ************************************************************************** */

#include "cub3d.h"



void fill_map(void)
{
	t_map *map;
	int i;

	map = v_map();
	char *line[] = {
		"11111111111111111111",
		"10000000000000000001",
		"10000000001111100001",
		"10111000000011110001",
		"10000000000000000001",
		"100110000000P0110001",
		"10000011100000000001",
		"10000011100000000001",
		"10000000000001111001",
		"10000000011101100001",
		"10000000000000000001",
		"11111111111111111111",
		NULL
	};

	i = 0;
	map->map = ft_malloc(sizeof(char *) * 13); // 12 lines + NULL
	while (line[i])
	{
		map->map[i] = ft_strdup(line[i]);
		i++;
	}
	map->col = i;
	map->raw = ft_strlen(line[0]);
	map->map[i] = NULL;
}

void fill_data(void)
{
	t_data *data;

	data = v_data();
	data->win_width = v_map()->raw * PIXEL;
	data->win_height = v_map()->col * PIXEL;

	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, data->win_width, data->win_height, "Map Draw");
	data->img = mlx_new_image(data->mlx, data->win_width, data->win_height);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
}

void    ray_direction(void)
{
    // v_player()->rotation_angle = 270;
    int ray_length = 40 * 5;
    v_player()->rotation_radian_angle = DEG_TO_RAD(v_player()->rotation_angle);
    v_player()->end_p_x = v_player()->p_x + cos(v_player()->rotation_radian_angle) * ray_length;
    v_player()->end_p_y = v_player()->p_y + sin(v_player()->rotation_radian_angle) * ray_length;
   draw_line(v_player()->p_x, v_player()->p_y, v_player()->end_p_x, v_player()->end_p_y, 0x00FF0000);
}

void draw_map(void)
{
	int row;
	int col;
	char **map;
    static int first;
	t_player *p;
    
    p = v_player();
	col = 0;
	map = v_map()->map;
	while (map[col])
	{
		row = 0;
		while (map[col][row])
		{
			if (map[col][row] == '1')
				draw_square(col * PIXEL, row * PIXEL , 0x00404040); // Wall
			else if(map[col][row] == '0' || map[col][row] == 'P' )
            {
                if (map[col][row] == 'P' && !first)
                {
                	first = 1;
                	v_player()->p_x = row * PIXEL + PIXEL / 2;
                	v_player()->p_y = col * PIXEL + PIXEL / 2;
                }
				draw_square(col * PIXEL, row * PIXEL , 0x00F5F5DC); // Floor
            }
			row++;
		}
		col++;
	}
	draw_filled_circle(p->p_y, p->p_x, RADIUS, 0x00FF0000);
    
    ray_direction();

	mlx_put_image_to_window(v_data()->mlx, v_data()->mlx_win, v_data()->img, 0, 0);
}

int key_press(int keycode)
{
    if(keycode == key_Esc)
        exit(0);
    if(keycode == key_rotate_right)
        v_player()->turn_direction = 1;
    if(keycode == key_rotate_left)
        v_player()->turn_direction = -1;
    if(keycode == key_up)
        v_player()->walk_direction = 1;
    if(keycode == key_down)
        v_player()->walk_direction = -1;
    if(keycode == key_right)
        v_player()->side_direction = 1;
    if(keycode == key_left)
        v_player()->side_direction = -1;
    return 0;
}

int key_release(int keycode)
{
    if(keycode == key_rotate_right || keycode == key_rotate_left)
        v_player()->turn_direction = 0;
    if(keycode == key_up || keycode == key_down)
        v_player()->walk_direction = 0;
    if(keycode == key_right || keycode == key_left)
        v_player()->side_direction = 0;
    return 0;
}

double  normalize_angle(double anlge)
{
    double c = (2 * M_PI);
    anlge = fmod(anlge, c) ;
    if(anlge < 0)
        anlge = c + anlge;
    return anlge;
}

void    draw_FOV(void)
{
    double  radian1;
    double  radian2;
    double  player_angle;
    double  half_fov;
    double ray_angle;
    int     end_x;
    int     end_y;
    int     num_of_rays;

    // num_of_rays = v_data()->win_width / 4;
    // player_angle = DEG_TO_RAD(v_player()->rotation_angle);
    // half_fov = (DEG_TO_RAD(FOV) / 2);
    // radian1 = normalize_angle(player_angle + half_fov);
    // radian2 = player_angle - half_fov;
    // while ((int)radian1 != (int)player_angle)
    // {
    //     end_x = v_player()->p_x + cos(radian1) * 70;
    //     end_y = v_player()->p_y + sin(radian1) * 70;
    //     draw_line(v_player()->p_x, v_player()->p_y, end_x, end_y, 0x00FF0000);
    //     radian1 -= 40;

    // }
    // end_x = v_player()->p_x + cos(radian2) * 70;
    // end_y = v_player()->p_y + sin(radian2) * 70;
    // draw_line(v_player()->p_x, v_player()->p_y, end_x, end_y, 0x00FF0000);
    int i = 0;

    num_of_rays = v_data()->win_width / 4;
    player_angle = DEG_TO_RAD(v_player()->rotation_angle);
    half_fov = DEG_TO_RAD(FOV) / 2;

    ray_angle = player_angle - half_fov;

    while (i < num_of_rays)
    {
        ray_angle = normalize_angle(ray_angle);
        end_x = v_player()->p_x + cos(ray_angle) * 1000;
        end_y = v_player()->p_y + sin(ray_angle) * 1000;


         printf("%g\n", draw_line(v_player()->p_x, v_player()->p_y, end_x, end_y, 0x00FF0000));

        ray_angle += DEG_TO_RAD(FOV) / num_of_rays;  // step size in radians
        i++;
    }

}

int    move_the_player(void)
{
    double  side_radian;
    double  radian;
    double  new_x;
    double  new_y;

    new_x = v_player()->p_x;
    new_y = v_player()->p_y;
    if(v_player()->turn_direction != 0)
    {
        v_player()->rotation_angle += v_player()->turn_direction * ROTATION_SPEED;
        if(v_player()->rotation_angle  > 360)
            v_player()->rotation_angle -= 360;
        if(v_player()->rotation_angle < 0)
            v_player()->rotation_angle += 360;
    }
    if(v_player()->walk_direction != 0)
    {
        
        radian = DEG_TO_RAD(v_player()->rotation_angle);
        new_x += cos(radian) * v_player()->walk_direction * SPEED;
        new_y += sin(radian) * v_player()->walk_direction * SPEED;
    }
    if(v_player()->side_direction != 0)
    {
        radian = DEG_TO_RAD(v_player()->rotation_angle);
        side_radian = radian + DEG_TO_RAD(90);
        new_x += cos(side_radian) * v_player()->side_direction * SPEED;
        new_y += sin(side_radian) * v_player()->side_direction * SPEED;
    }
    if (v_map()->map[(int)(v_player()->p_y / PIXEL)][(int)(new_x / PIXEL)] != '1')
        v_player()->p_x = new_x;
    if (v_map()->map[(int)(new_y / PIXEL)][(int)(v_player()->p_x / PIXEL)] != '1')
        v_player()->p_y = new_y;
    draw_map();
    draw_FOV();
    usleep(10000);
    return 0;
}

int main(int argc, char const *argv[])
{
    fill_map();
    fill_data();
    draw_map();
    mlx_hook(v_data()->mlx_win, 2, 1L << 0, key_press, NULL);
    mlx_hook(v_data()->mlx_win, 3, 1L << 1, key_release, NULL);
    mlx_loop_hook(v_data()->mlx, move_the_player, NULL);
    mlx_loop(v_data()->mlx);
    return 0;
}
