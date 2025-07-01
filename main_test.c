#include "cub3d.h"

#include "mlx.h"
#include "cub3d.h"
#include <stdio.h> // if you want printf

void put_pixel(int x, int y, int color)
{
	char *dst;
    t_data *data;

    data = v_data();
	// Bounds check to stay inside the window
	if (x < 0 || y < 0)
		return;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void draw_square(int start_x, int start_y, int color)
{
    int x;
    int y;

    y = start_y;
	while ( y < start_y + PIXEL)
	{
        x = start_x;
		while ( x < start_x + PIXEL)
		{
			put_pixel(x, y, color);
            x++;
		}
        y++;
	}
}

void draw_point(int start_x, int start_y, int color)
{
    int x;
    int y;

    y = start_y;
    x = start_x;
}

// void draw_player_circle(void)
// {

//     // Center of the tile (grid cell)
//     int cx = v_player()->p_x * PIXEL + PIXEL / 2;
//     int cy = v_player()->p_y * PIXEL + PIXEL / 2;
//     int radius = PIXEL / 4; // Circle radius: smaller than the tile

//     int x, y;

//     for (y = cy - radius; y <= cy + radius; y++)
//     {
//         for (x = cx - radius; x <= cx + radius; x++)
//         {
//             int dx = x - cx;
//             int dy = y - cy;

//             if (dx * dx + dy * dy <= radius * radius)
//                 put_pixel( x, y, 0x00FF0000); // Red circle
//         }
//     }
// }

// void draw_player_triangle(void)
// {
//     int cx = v_player()->p_x * PIXEL + PIXEL / 2;
//     int cy = v_player()->p_y * PIXEL + PIXEL / 2;
//     int height = PIXEL / 3; // triangle height

//     int y_start = cy - height / 2;
//     int y_end = cy + height / 2;

//     for (int y = y_start; y <= y_end; y++)
//     {
//         // Calculate relative vertical position inside the triangle (0 at top, height at bottom)
//         int rel_y = y - y_start;

//         // Calculate half width of triangle at this row
//         // Width linearly grows from 0 at top to height at base
//         float half_width = (float)rel_y * (float)(height) / (float)(height);

//         int x_start = cx - (int)half_width;
//         int x_end = cx + (int)half_width;

//         for (int x = x_start; x <= x_end; x++)
//         {
//             put_pixel(x, y, 0x00FF0000); // red color
//         }
//     }
// }

void draw_player_triangle(void)
{
    int cx = v_player()->p_x * PIXEL + PIXEL / 2;
    int cy = v_player()->p_y * PIXEL + PIXEL / 2;
    int height = PIXEL / 5;   // shorter triangle height
    int half_width = 4;       // narrow fixed width

    int y_start = cy - height / 2;
    int y_end = cy + height / 2;

    for (int y = y_start; y <= y_end; y++)
    {
        int rel_y = y - y_start;
        float factor = 1.0f - (float)rel_y / (float)height;
        int current_half_width = (int)(half_width * factor);

        int x_start = cx - current_half_width;
        int x_end = cx + current_half_width;

        for (int x = x_start; x <= x_end; x++)
            put_pixel(x, y, 0x00FF0000);
    }
}



void draw_map(void)
{
	int row;
	int col;
    static int first;
    char **map;
    
    row = 0;
    map = v_map()->map;
	while (map[row])
	{
		col = 0;
		while (map[row][col])
		{
			if (map[row][col] == '1')
				draw_square(col * PIXEL, row * PIXEL, 0x00404040); // Dark Gray wall
			else if (map[row][col] == '0' || map[row][col] == 'P')
			{
            	draw_square(col * PIXEL, row * PIXEL, 0x00F5F5DC); // Light Beige floor
                if( !first && map[row][col] == 'P')
                {
                    first = 1;
                    v_player()->p_y = row;
                    v_player()->p_x = col;
                }
            }
            col++;
		}
		row++;
	}
}

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
		"1001100000P000110001",
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
	map->col = i; // rows
	map->raw = ft_strlen(line[0]); // columns
	map->map[i] = NULL;
}

void fill_data(void)
{
	t_data *data;
	int win_width;
	int win_height;

	data = v_data();
	win_width = v_map()->raw * PIXEL;
	win_height = v_map()->col * PIXEL;

	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, win_width, win_height, "Map Draw");
	data->img = mlx_new_image(data->mlx, win_width, win_height);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
}
int move_player(int key_code)
{
    t_player    *player;
    t_data *data = v_data();
    int         new_x;
    int         new_y;

    player = v_player();
    new_x = player->p_x;
    new_y = player->p_y;
    if(key_code == key_up)
    {
        new_y--;
    }
    else if(key_code == key_down)
    {
        new_y++;
    }
    else if(key_code == key_right)
    {
        new_x++;
    }
    else if(key_code == key_left)
    {
        new_x--;
    }
    // else if(key_code == key_rotate_right)
    // {
// 
    // }
    // else if(key_code == key_rotate_left)
    // {
// 
    // }
    if(v_map()->map[new_y][new_x] != '1')
    {
        v_player()->p_x = new_x;
        v_player()->p_y = new_y;
        // printf("px = %d py = %d\n", v_player()->p_x, v_player()->p_y);
    }
    data->img = mlx_new_image(data->mlx, v_map()->raw * PIXEL, v_map()->col * PIXEL);
    data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
    draw_map();
    draw_player_triangle();
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
    printf("x = %d y = %d\n", v_player()->p_x, v_player()->p_y);
    return 1;
}

int main(void)
{
	t_data *data;

	data = v_data();
	fill_map();
	fill_data();
	draw_map();
    draw_player_triangle();
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
    mlx_hook(data->mlx_win, 2, 1L << 0, move_player, NULL);
	mlx_loop(data->mlx);

	return 0;
}
