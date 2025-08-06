/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 14:02:21 by imeslaki          #+#    #+#             */
/*   Updated: 2025/08/06 18:18:31 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

// void frames()
// {
//     static struct timeval start;
//     struct timeval now;
//     static int count;
//     long time;
    
//     if (!count)
//         gettimeofday(&start, NULL);
    
//     if (print_time(start))
//     {
//         printf("%d frame/sec\n", count);
//         count = 0;
//     }
//     else
//     {
//         gettimeofday(&now, NULL);
//         int turn_time = 1000000/30;
//         long time_paste = (now.tv_sec * 1000000 + now.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec);
//         long time_of_this_tour = (turn_time * (count + 1));
//         time = time_of_this_tour - time_paste;
//         if (time > 0 && time_paste)
//         {
//             usleep(time);
//         }
//         count++;
//     }
// }


void    rotate_player(void)
{
    v_player()->rotation_angle += v_player()->turn_direction * ROTATION_SPEED;
    if(v_player()->rotation_angle  > 360)
        v_player()->rotation_angle -= 360;
    if(v_player()->rotation_angle < 0)
        v_player()->rotation_angle += 360;
}

int check_wall(double x1, double y1, double angle, int d)
{
    int col;
    int row;
    double radian;

    radian = DEG_TO_RAD(angle);
    row = x1 + (d + 2) * cos(radian);
    col = y1 + (d + 2) * sin(radian);
    if (get_final_map(0,0)[col / TILESIZE][row / TILESIZE] == '1')
        return 1;
    return 0;
}

void update_player_position(double x1, double y1, double angle, int d)
{
    double radian;
    
    radian = DEG_TO_RAD(angle);
    while (d <= PLAYER_SPEED)
    {
        if (check_wall(x1, y1, angle, d) 
            || check_wall(x1, y1+1, angle, d) 
            || check_wall(x1, y1-1, angle, d) 
            || check_wall(x1+1, y1, angle, d)
            || check_wall(x1-1, y1, angle, d))
            return;
        v_player()->save_x = x1 + d * cos(radian);
        v_player()->save_y = y1 + d * sin(radian);
        d++;
    }
}

void    player_move_straight_walk(void)
{
    double  angle;

    angle = v_player()->rotation_angle;
    if (v_player()->walk_direction == -1)
    {
        angle += 180;
        if (angle > 360)
            angle -= 360;
        update_player_position(v_player()->p_x, v_player()->p_y, angle, 1);
    }
    else
        update_player_position(v_player()->p_x, v_player()->p_y, angle, 1);
}

void    player_move_side_walk()
{
    double  angle;

    angle = v_player()->rotation_angle + 90;
    if (v_player()->side_direction == -1)
    {
        angle += 180;
        if (angle > 360)
            angle -= 360;
        update_player_position(v_player()->p_x, v_player()->p_y, angle, 1);
    }
    else
        update_player_position(v_player()->p_x, v_player()->p_y, angle, 1);
}

void    draw_FOV(void)
{
    double  player_angle;
    double  half_fov;
    double ray_angle;
    int     num_of_rays;
    t_global	*data;
	t_data		*shrinked_map;
    data = v_global();

    int i = 0;

    num_of_rays = v_global()->win_width;
    player_angle = v_player()->rotation_angle;
    half_fov = FOV / 2;
    ray_angle = player_angle - half_fov;
    while (i < num_of_rays)
    {
        cast_ray(ray_angle);
        //draw_line(round(v_player()->p_x), round(v_player()->p_y), round(v_player()->end_p_x) , round(v_player()->end_p_y) , 0x00FF0000);
        // draw_pixel(v_player()->end_p_x, v_player()->end_p_y, 0x00FF0000);
        // v_player()->end_p_x = (int)v_player()->end_p_x;
        // v_player()->end_p_y = (int)v_player()->end_p_y;
        my_mlx_pixel_put(data->map_img, v_player()->end_p_x, v_player()->end_p_y, 0xff0000);
        render(i, ray_angle);
        ray_angle += (double)FOV / (double)num_of_rays;
        i++;
    }
    // cast_ray(player_angle);
    // draw_circle(v_player()->end_p_y, v_player()->end_p_x,2 ,0xff0000);
    // my_mlx_pixel_put(data->map_img, v_player()->end_p_x, v_player()->end_p_y, 0xff0000);
    // shrinked_map = mlx_shrink_img(data->map_img, v_global()->map_img->img_width / 2, v_global()->map_img->img_height / 2);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->win_img->img, 0, 0);
    // mlx_put_image_to_window(data->mlx, data->mlx_win, data->map_img->img, 0, 0);
}

int    move_the_player(void)
{
    double  new_x;
    double  new_y;

    // frames();
    render_floor_and_sky();
    v_player()->save_x = v_player()->p_x;
    v_player()->save_y = v_player()->p_y;
    if(v_player()->turn_direction != 0)
        rotate_player();
    if(v_player()->walk_direction != 0)
        player_move_straight_walk();
    if(v_player()->side_direction != 0)
        player_move_side_walk();
    v_player()->p_x = v_player()->save_x;
    v_player()->p_y = v_player()->save_y;
    draw_map();
    draw_FOV();
    return 0;
}
