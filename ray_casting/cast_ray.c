/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 23:08:49 by imeslaki          #+#    #+#             */
/*   Updated: 2025/08/12 16:34:01 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_casting.h"

void    get_vertical_x_hit(double   rad, double *vert_x, double *x_step_v)
{
    if (cos(rad) > 0)
    {
        *vert_x = floor(v_player()->p_x / TILESIZE) * TILESIZE + TILESIZE;
        *x_step_v = TILESIZE;
    }
    else
    {
        *vert_x = floor(v_player()->p_x / TILESIZE) * TILESIZE  ;
        *x_step_v = -TILESIZE;
    }
}

void  get_vertical_y_hit(double   rad, double *vert_x, double *vert_y, double *y_step_v)
{
    *vert_y = v_player()->p_y + (*vert_x - v_player()->p_x) * tan(rad);

    *y_step_v = fabs(TILESIZE * tan(rad));
    if (sin(rad) < 0)
        *y_step_v *= -1;
}

void find_vertical_hit(double *hit_x, double *hit_y, double rad)
{
    double vert_x, vert_y;
    double x_step_v, y_step_v;
    
    
    get_vertical_x_hit(rad, &vert_x, &x_step_v);
    get_vertical_y_hit(rad, &vert_x, &vert_y, &y_step_v);
    v_player()->x_step_v = x_step_v;
    v_player()->y_step_v = y_step_v;
    while (1)
    {
        int map_x, left_x, right_x;
        if (cos(rad) > 0)
        {
            map_x = vert_x / TILESIZE;
        }
        else
        {
            map_x = (vert_x - 1) / TILESIZE;
        }
        int map_y, left_y, right_y; 
        map_y = vert_y / TILESIZE;

        if (is_wall(map_x, map_y))
            break;
        vert_x += x_step_v;
        vert_y += y_step_v;
    }
    *hit_x = vert_x;
    *hit_y = vert_y;
}

void    get_horizontal_y_hit(double  rad, double *hor_y, double  *y_step_h)
{
    if (sin(rad) > 0)
    {
        *hor_y = floor(v_player()->p_y / TILESIZE) * TILESIZE + TILESIZE;
        *y_step_h = TILESIZE;
    }
    else
    {
        *hor_y = floor(v_player()->p_y / TILESIZE) * TILESIZE ;
        *y_step_h = -TILESIZE;
    }
}

void    get_horizontal_x_hit(double  rad, double *hor_y, double *hor_x, double  *x_step_h)
{
    *hor_x = v_player()->p_x + (*hor_y - v_player()->p_y) / tan(rad);

    *x_step_h = fabs((double)TILESIZE / tan(rad));
    if (cos(rad) < 0)
        *x_step_h *= -1;
}

void find_horizontal_hit(double *hit_x, double *hit_y, double rad)
{
    double hor_x, hor_y;
    double x_step_h, y_step_h;

    get_horizontal_y_hit(rad, &hor_y, &y_step_h);
    get_horizontal_x_hit(rad, &hor_y, &hor_x, &x_step_h);
    v_player()->x_step_h = x_step_h;
    v_player()->y_step_h = y_step_h;

    while (1)
    {
        int map_x, left_x, right_x;
        int map_y, left_y, right_y;
        
        map_x = hor_x / TILESIZE;
        if (sin(rad) > 0)
        {
            map_y = hor_y / TILESIZE;
        }
        else
        {
            map_y = (hor_y - 1) / TILESIZE;
        }
        if (is_wall(map_x, map_y))
            break;
        
        hor_x += x_step_h;
        hor_y += y_step_h;
    }
    *hit_x = hor_x;
    *hit_y = hor_y;
}



void ray_casting(double angle)
{
    double vx, vy;
    double hx, hy;
    double radian;

    radian = angle * (M_PI / 180.0);

    find_vertical_hit(&vx, &vy, radian);
    find_horizontal_hit(&hx, &hy, radian);

    double dist_vert =  distance_from_player(vx, vy);
    double dist_hor =   distance_from_player(hx, hy);


    if (dist_vert < dist_hor)
    {
        v_player()->end_p_x = vx;
        v_player()->end_p_y = vy;
        v_player()->was_hit_vertical = 1;
    }
    else
    {
        v_player()->end_p_x = hx;
        v_player()->end_p_y = hy;
        v_player()->was_hit_vertical = 0;
    }
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
t_ray_data  get_horizontal_y_intersection(t_point   start_pos, double radian, double   step_speed)
{
    t_ray_data  horizontal_hit;

    if(sin(radian) > 0)
    {
        horizontal_hit.hit_point.y = floor(start_pos.y / TILESIZE) * TILESIZE + TILESIZE;
        horizontal_hit.step_y = step_speed;
    }
    else
    {
        horizontal_hit.hit_point.y = floor(start_pos.y / TILESIZE) * TILESIZE;
        horizontal_hit.step_y = -step_speed; 
    }
    return (horizontal_hit);
}

t_ray_data  get_horizontal_x_intersection(t_point   start_pos, t_ray_data  horizontal_hit, double radian, double   step_speed)
{
    double  dist;

    dist = horizontal_hit.hit_point.y - start_pos.y;
    horizontal_hit.hit_point.x = start_pos.x + dist / tan(radian);
    horizontal_hit.step_x =  fabs((double)step_speed / tan(radian));
    if (cos(radian) < 0)
        horizontal_hit.step_x *= -1;
    return (horizontal_hit);
}

t_ray_data  find_horizontal_intersection(t_point   start_pos, double radian, double   step_speed)
{
    t_ray_data  horizontal_hit;
    int         map_x;
    int         map_y;

    horizontal_hit = get_horizontal_y_intersection(start_pos, radian, step_speed);
    horizontal_hit = get_horizontal_x_intersection(start_pos, horizontal_hit, radian, step_speed);
    
    while (1)
    {
        map_x = horizontal_hit.hit_point.x / TILESIZE;
        if(sin(radian) > 0)
            map_y = horizontal_hit.hit_point.y / TILESIZE;
        else
            map_y = (horizontal_hit.hit_point.y - 1) / TILESIZE;
        if(is_wall(map_x, map_y))
            break;
        horizontal_hit.hit_point.x += horizontal_hit.step_x;
        horizontal_hit.hit_point.y += horizontal_hit.step_y;
    }
    horizontal_hit.wall_direction = 0;
    return (horizontal_hit);
}

t_ray_data  get_vertical_x_intersection(t_point   start_pos, double radian, double   step_speed)
{
    t_ray_data  vertical_hit;

    if(cos(radian) > 0)
    {
        vertical_hit.hit_point.x = floor(start_pos.x / TILESIZE) * TILESIZE + TILESIZE;
        vertical_hit.step_x = step_speed;
    }
    else
    {
        vertical_hit.hit_point.x = floor(start_pos.x / TILESIZE) * TILESIZE;
        vertical_hit.step_x = -step_speed;
    }
    return (vertical_hit);
}

t_ray_data  get_vertical_y_intersection(t_point   start_pos, t_ray_data  vertical_hit, double radian, double   step_speed)
{
    double  dist;

    dist = vertical_hit.hit_point.x - start_pos.x;
    vertical_hit.hit_point.y = start_pos.y + dist * tan(radian);
    vertical_hit.step_y = fabs(step_speed * tan(radian));
    if(sin(radian) < 0)
        vertical_hit.step_y *= -1;
    return (vertical_hit);
}

t_ray_data  find_vertical_intersection(t_point   start_pos, double radian, double   step_speed)
{
    t_ray_data  vertical_hit;
    int         map_x;
    int         map_y;

    vertical_hit = get_vertical_x_intersection(start_pos, radian, step_speed);
    vertical_hit = get_vertical_y_intersection(start_pos, vertical_hit, radian, step_speed);
    
    while (1)
    {
        map_y = vertical_hit.hit_point.y / TILESIZE;
        if(cos(radian) > 0)
            map_x = vertical_hit.hit_point.x / TILESIZE;
        else
            map_x = (vertical_hit.hit_point.x - 1) / TILESIZE;
        if(is_wall(map_x, map_y))
            break;
        vertical_hit.hit_point.x += vertical_hit.step_x;
        vertical_hit.hit_point.y += vertical_hit.step_y;
    }
    vertical_hit.wall_direction = 1;
    return (vertical_hit);
}

double distance_from_player(double x2, double y2)
{
    double  dx;
    double  dy;

    dx = v_player()->p_x - x2;
    dy = v_player()->p_y - y2;
    return sqrt(dx * dx + dy * dy);
}

t_ray_data    cast_ray(t_point   start_pos, double angle, double   step_speed)
{
    double      radian;
    double      dist_vert;
    double      dist_hor;
    t_ray_data  horizontal_hit;
    t_ray_data  vertical_hit;

    radian = angle * (M_PI / 180.0);

    vertical_hit = find_vertical_intersection(start_pos, radian, step_speed);
    horizontal_hit = find_horizontal_intersection(start_pos, radian, step_speed);

    dist_vert =  distance_from_player(vertical_hit.hit_point.x, vertical_hit.hit_point.y);
    dist_hor =   distance_from_player(horizontal_hit.hit_point.x, horizontal_hit.hit_point.y);

    if (dist_vert < dist_hor)
        return  (vertical_hit);
    else
        return (horizontal_hit);
}

void ray_casting_update_p(double    angle)
{
    t_point player_pos;
    t_ray_data  hit_position;

    player_pos.x = v_player()->p_x;
    player_pos.y = v_player()->p_y;
    hit_position = cast_ray(player_pos, angle, TILESIZE);
    v_player()->was_hit_vertical = hit_position.wall_direction;
    v_player()->end_p_x = hit_position.hit_point.x;
    v_player()->end_p_y = hit_position.hit_point.y;
}
