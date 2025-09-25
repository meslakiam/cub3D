/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_animation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bann <oel-bann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 12:11:30 by oel-bann          #+#    #+#             */
/*   Updated: 2025/09/24 00:07:43 by oel-bann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d_bonus.h"

int check_is_running()
{
    if (v_player()->walk_direction == 1)
        return (1);
    else
        return (0);
}

t_data_list *get_curr_player_animation()
{
    if (check_is_running())
        return (get_run_imgs(1));
    else
    {
        if (v_player()->fire == 1)
            return (get_fire_imgs(1));
        return (get_static_pos());
    }
    return (NULL);
}

// t_data_list *fire_animation()
// {
//     t_data_list *fire_lst;
//     t_data_list *head;

//     fire_lst = get_fire_imgs();
//     head = fire_lst;
//     if (v_player()->fire == 1)
//     {
//         while (fire_lst->next != head)
//         {
//             draw_animation(fire_lst);
//             fire_lst = fire_lst->next;
//         }
//     }
// }