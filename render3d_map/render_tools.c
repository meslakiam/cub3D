/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 19:24:09 by oel-bann          #+#    #+#             */
/*   Updated: 2025/08/06 17:21:34 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

t_rays_data *store_one_wall_rays()
{
    static t_rays_data *rs_data;

    
}

int get_first(int set)
{
    static int first;
    if (set == 2)
        first = 0;
    else if (set == 1)
        first = 1;
    return (first);
}

double get_img_start_w(int img_w)
{
    double img_start_w;
    double end_x_y;
    int pos;

    
    if (v_player()->was_hit_vertical)
        end_x_y = v_player()->end_p_y;
    else
        end_x_y = v_player()->end_p_x;
    pos = end_x_y / TILESIZE;
    img_start_w = (end_x_y - (pos * TILESIZE)) * (img_w / TILESIZE);
    if(img_start_w < 0)
        img_start_w = 0;
    return (img_start_w);
}

int is_ray_from_cur_wall()
{
    static int cur_end_x_y;
    static int cur_start_x_y;
    static int hit;

    if (!get_first(0))
    {
        cur_end_x_y = 0;
        cur_start_x_y = 0;
        hit = 0;
        cur_end_x_y = (v_player()->end_p_y / TILESIZE) * TILESIZE + TILESIZE;
        cur_start_x_y = (v_player()->end_p_y / TILESIZE) * TILESIZE;
        if (!v_player()->was_hit_vertical)
        {
            cur_end_x_y = (v_player()->end_p_x / TILESIZE) * TILESIZE + TILESIZE;
            cur_start_x_y = (v_player()->end_p_x / TILESIZE) * TILESIZE;
        }
        hit = v_player()->was_hit_vertical;
        // get_wall_first_hit(1);
        get_first(1);
    }
    if (!hit && v_player()->end_p_x >= cur_start_x_y && v_player()->end_p_x <= cur_end_x_y)
        return (1);
    else if (hit && v_player()->end_p_y >= cur_start_x_y && v_player()->end_p_y <= cur_end_x_y)
        return (1);
    return(0);
}
