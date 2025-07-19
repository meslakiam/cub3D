/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 14:02:21 by imeslaki          #+#    #+#             */
/*   Updated: 2025/07/18 16:33:28 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"
// #include "../cub3d.h"


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

void    update_player_position(void)
{
    double  radian;
    double  side_radian;
    
    if(v_player()->walk_direction != 0)
    {
        
        radian = DEG_TO_RAD(v_player()->rotation_angle);
        v_player()->save_x += cos(radian) * v_player()->walk_direction * PLAYER_SPEED;
        v_player()->save_y += sin(radian) * v_player()->walk_direction * PLAYER_SPEED;
    }
    if(v_player()->side_direction != 0)
    {
        radian = DEG_TO_RAD(v_player()->rotation_angle);
        side_radian = radian + DEG_TO_RAD(90);
        v_player()->save_x += cos(side_radian) * v_player()->side_direction * PLAYER_SPEED;
        v_player()->save_y += sin(side_radian) * v_player()->side_direction * PLAYER_SPEED;
    }
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
// 
    // num_of_rays = v_data()->win_width / 4;
    // player_angle = DEG_TO_RAD(v_player()->rotation_angle);
    // half_fov = (DEG_TO_RAD(FOV) / 2);
    // radian1 = normalize_angle2(player_angle + half_fov);
    // radian2 = player_angle - half_fov;
    // while ((int)radian1 != (int)player_angle)
    // {
    //     end_x = v_player()->p_x + cos(radian1) * 70;
    //     end_y = v_player()->p_y + sin(radian1) * 70;
    //     draw_line(v_player()->p_x, v_player()->p_y, end_x, end_y, 0x00FF0000);
    //     radian1 -= 40;
// 
    // }
    // end_x = v_player()->p_x + cos(radian2) * 70;
    // end_y = v_player()->p_y + sin(radian2) * 70;
    // draw_line(v_player()->p_x, v_player()->p_y, end_x, end_y, 0x00FF0000);
    int i = 0;
    num_of_rays = v_data()->win_width / 4;
    player_angle = DEG_TO_RAD(v_player()->rotation_angle);
    half_fov = DEG_TO_RAD(FOV) / 2;
    ray_angle = player_angle - half_fov;
// 
    while (i < num_of_rays)
    {
        // ray_angle = normalize_angle2(ray_angle);
        // end_x = v_player()->p_x + cos(ray_angle) * 1000;
        // end_y = v_player()->p_y + sin(ray_angle) * 1000;
        // 
        cast_ray(ray_angle);
        ray_angle += DEG_TO_RAD(FOV) / num_of_rays;  // step size in radians
        i++;
    }
}

int    move_the_player(void)
{
    double  new_x;
    double  new_y;

    // frames();
    v_player()->save_x = v_player()->p_x;
    v_player()->save_y = v_player()->p_y;
    if(v_player()->turn_direction != 0)
        rotate_player();
    if(v_player()->walk_direction != 0 || v_player()->side_direction != 0)
        update_player_position();
    new_x = v_player()->save_x;
    new_y = v_player()->save_y;
    if (v_map()->map[(int)(v_player()->p_y / TILESIZE)][(int)(new_x / TILESIZE)] != '1')
        v_player()->p_x = new_x;
    if (v_map()->map[(int)(new_y / TILESIZE)][(int)(v_player()->p_x / TILESIZE)] != '1')
        v_player()->p_y = new_y;
    draw_map();
    draw_FOV();
    return 0;
}
