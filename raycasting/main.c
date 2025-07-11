// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   main.c                                             :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2025/07/07 15:53:48 by imeslaki          #+#    #+#             */
// /*   Updated: 2025/07/08 15:58:41 by imeslaki         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "cub3d.h"



// void fill_map(void)
// {
// 	t_map *map;
// 	int i;

// 	map = v_map();
// 	char *line[] = {
// 		"11111111111111111111",
// 		"10000000000000000001",
// 		"10000000001111100001",
// 		"10111000000011110001",
// 		"10000000000000000001",
// 		"100110000000P0110001",
// 		"10000011100000000001",
// 		"10000011100000000001",
// 		"10000000000001111001",
// 		"10000000011101100001",
// 		"10000000000000000001",
// 		"11111111111111111111",
// 		NULL
// 	};

// 	i = 0;
// 	map->map = ft_malloc(sizeof(char *) * 13); // 12 lines + NULL
// 	while (line[i])
// 	{
// 		map->map[i] = ft_strdup(line[i]);
// 		i++;
// 	}
// 	map->col = i;
// 	map->raw = ft_strlen(line[0]);
// 	map->map[i] = NULL;
// }

// void fill_data(void)
// {
// 	t_data *data;
// 	int win_width;
// 	int win_height;

// 	data = v_data();
// 	win_width = v_map()->raw * PIXEL;
// 	win_height = v_map()->col * PIXEL;

// 	data->mlx = mlx_init();
// 	data->mlx_win = mlx_new_window(data->mlx, win_width, win_height, "Map Draw");
// 	data->img = mlx_new_image(data->mlx, win_width, win_height);
// 	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
// }



// void    draw_pixel(int y, int x, int color)
// {
//     t_data  *data;
//     char *tmp;

//     if (x < 0 || y < 0)
// 		return;
//     data = v_data();
//     tmp = data->addr + ((y * data->line_length) + (x * (data->bits_per_pixel / 8)));
//     *(unsigned int *)tmp = color;
// }

// void    draw_square(int y, int x, int color)
// {
//     int start_y;
//     int start_x;

//     start_y = y;
//     start_x = x;
//     while (y < start_y + PIXEL)
//     {
//         x = start_x;
//         while (x < start_x + PIXEL)
//         {
//             draw_pixel(y, x, color);
//             x++;
//         }
//         y++;
//     }
    
// }

// void draw_filled_circle(int center_y, int center_x, int radius, int color)
// {
//     int y = -radius;
//     int x;

//     while (y <= radius)
//     {
//         x = -radius;
//         while (x <= radius)
//         {
//             if (x * x + y * y <= radius * radius) // inside the circle
//                 draw_pixel(center_y + y, center_x + x, color);
//             x++;
//         }
//         y++;
//     }
// }

// void draw_line(int x0, int y0, int x1, int y1, int color)
// {
//     float dx = x1 - x0;
//     float dy = y1 - y0;

//     int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

//     float x_inc = dx / steps;
//     float y_inc = dy / steps;

//     float x = x0;
//     float y = y0;

//     for (int i = 0; i <= steps; i++)
//     {
//         draw_pixel((int)(y + 0.5), (int)(x + 0.5), color);
//         x += x_inc;
//         y += y_inc;
//     }
// }

// void draw_line(int x0, int y0, int x1, int y1, int color)
// {
//     int dx;
//     int dy;
//     int sx;
//     int sy;
//     int err;
//     int e2;

//     dx = abs(x1 - x0);
//     dy = abs(y1 - y0);

//     if (x0 < x1)
//         sx = 1;
//     else
//         sx = -1;

//     if (y0 < y1)
//         sy = 1;
//     else
//         sy = -1;

//     err = dx - dy;

//     while (1)
//     {
//         draw_pixel(y0, x0, color);

//         if (x0 == x1 && y0 == y1)
//             break;

//         e2 = 2 * err;

//         if (e2 > dy)
//         {
//             err -= dy;
//             x0 += sx;
//         }

//         if (e2 < dx)
//         {
//             err += dx;
//             y0 += sy;
//         }
//     }
// }

// // void draw_line(int cercle_cx, int cercle_cy, int line_w , int color)
// // {
// //     int i;

// //     i = 0;
// //     while (i < line_w)
// //     {
// //          draw_pixel(cercle_cy, cercle_cx + i, color);
// //          i++;
// //     }
// // }

// void draw_map(void)
// {
// 	int row;
// 	int col;
// 	char **map;
//     static int first;
// 	t_player *p;
    
//     p = v_player();
// 	col = 0;
// 	map = v_map()->map;
// 	while (map[col])
// 	{
// 		row = 0;
// 		while (map[col][row])
// 		{
// 			if (map[col][row] == '1')
// 				draw_square(col * PIXEL, row * PIXEL , 0x00404040); // Wall
// 			else if(map[col][row] == '0' || map[col][row] == 'P' )
//             {
//                 if (map[col][row] == 'P' && !first)
//                 {
//                 	first = 1;
//                 	v_player()->p_x = 1 * PIXEL + PIXEL / 2;
//                 	v_player()->p_y = 1 * PIXEL + PIXEL / 2;
//                 }
// 				draw_square(col * PIXEL, row * PIXEL , 0x00F5F5DC); // Floor
//             }
// 			row++;
// 		}
// 		col++;
// 	}

// 	draw_filled_circle(p->p_y, p->p_x, RADIUS, 0x00FF0000); // radius 1/4 cell

//     int ray_length = PIXEL * 2;
//     double rad = DEG_TO_RAD(p->rotation_angle);
//     int ray_end_x = p->p_x + cos(rad) * ray_length;
//     int ray_end_y = p->p_y + sin(rad) * ray_length;

//     // draw_line(p->p_x, p->p_y, 20, 0x00FF0000);
//     draw_line(p->p_x, p->p_y, ray_end_x, ray_end_y, 0x00FF0000); // green ray

// 	mlx_put_image_to_window(v_data()->mlx, v_data()->mlx_win, v_data()->img, 0, 0);
// }

// int key_press(int keycode)
// {
//     t_player *player = v_player();

//     if (keycode == key_up)
//         player->walk_direction = 1;
//     else if (keycode == key_down)
//         player->walk_direction = -1;
//     if (keycode == key_left)
//         player->side_direction = -1;
//     else if (keycode == key_left)
//         player->side_direction = 1;
//     else if (keycode == key_rotate_left)
//         player->turn_direction = -1;
//     else if (keycode == key_rotate_right)
//         player->turn_direction = 1;
//     else if (keycode == key_Esc)
//         exit(0);

//     return 0;
// }

// int key_release(int keycode)
// {
//     t_player *player = v_player();

//     if (keycode == key_up || keycode == key_down)
//         player->walk_direction = 0;
//     else if(keycode == key_left || keycode == key_right)
//         player->side_direction = 0;
//     else if (keycode == key_rotate_left || keycode == key_rotate_right)
//         player->turn_direction = 0;

//     return 0;
// }

// int loop_hook(void)
// {
//     t_player *player = v_player();
//     t_map *map = v_map();

//     // Rotate player smoothly
//     player->rotation_angle += player->turn_direction * 5;
//     if (player->rotation_angle >= 360)
//         player->rotation_angle -= 360;
//     else if (player->rotation_angle < 0)
//         player->rotation_angle += 360;

//     double rad = DEG_TO_RAD(player->rotation_angle);
//     double rad_strafe = rad + DEG_TO_RAD(90);


//     double move_x = 0;
//     double move_y = 0;

//     if (player->walk_direction != 0)
//     {
//         move_x += cos(rad) * SPEED * player->walk_direction;
//         move_y += sin(rad) * SPEED * player->walk_direction;
//     }

//     if (player->side_direction != 0)
//     {
//         move_x += cos(rad_strafe) * SPEED * player->side_direction;
//         move_y += sin(rad_strafe) * SPEED * player->side_direction;
//     }

//     int new_x = player->p_x + move_x;
//     int new_y = player->p_y + move_y;

//     // === Add buffer check ===
//     double buffer = 5.0;

//     int map_row_x = new_x / PIXEL;
//     int map_col_x1 = (player->p_y + buffer) / PIXEL;
//     int map_col_x2 = (player->p_y - buffer) / PIXEL;

//     int map_col_y = new_y / PIXEL;
//     int map_row_y1 = (player->p_x + buffer) / PIXEL;
//     int map_row_y2 = (player->p_x - buffer) / PIXEL;

//     // Check X move with buffer
//     if (map->map[map_col_x1][map_row_x] != '1' && map->map[map_col_x2][map_row_x] != '1')
//         player->p_x = new_x;

//     // Check Y move with buffer
//     if (map->map[map_col_y][map_row_y1] != '1' && map->map[map_col_y][map_row_y2] != '1')
//         player->p_y = new_y;

//     draw_map();

//     usleep(16000);

//     return 0;
// }

// // int main()
// // {
// //     t_map   *map;
// //     t_data *data;

// //     map = v_map();
// //     data = v_data();
// //     int i = 0;
// //     fill_map();
// //     fill_data();
// //     draw_map();
// //     mlx_hook(data->mlx_win, 2, 1L << 0, key_press, NULL);
// //     mlx_hook(data->mlx_win, 3, 1L << 1, key_release, NULL);
// //     mlx_loop_hook(data->mlx, loop_hook, NULL);
// //     mlx_loop(data->mlx);
// // }
