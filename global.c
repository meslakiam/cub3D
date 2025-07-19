/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:49:00 by imeslaki          #+#    #+#             */
/*   Updated: 2025/07/16 13:28:25 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_map   *v_map(void)
{
    static t_map   map;

    return &map;
}

t_player   *v_player(void)
{
    static t_player   player;

    return &player;
}

t_data   *v_data(void)
{
    static t_data   data;

    return &data;
}
