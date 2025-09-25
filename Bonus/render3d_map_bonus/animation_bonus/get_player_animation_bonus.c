/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_animation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 12:11:30 by oel-bann          #+#    #+#             */
/*   Updated: 2025/09/25 21:42:24 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d_bonus.h"

int	check_is_running(void)
{
	if (v_player()->walk_direction == 1)
		return (1);
	else
		return (0);
}

t_data_list	*get_curr_player_animation(void)
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
