/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:49:00 by imeslaki          #+#    #+#             */
/*   Updated: 2025/07/19 19:23:14 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

// t_map   *v_map(void)
// {
//     static t_map   map;

//     return &map;
// }

t_map_data *get_map_info(void)
{
    static t_map_data data;
    return (&data);
}

t_player   *v_player(void)
{
    static t_player   player;

    return &player;
}

t_global   *v_global(void)
{
    static t_global   data;

    return &data;
}
