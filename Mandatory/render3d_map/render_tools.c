/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 19:24:09 by oel-bann          #+#    #+#             */
/*   Updated: 2025/09/25 20:40:09 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

double	get_img_start_w(int img_w)
{
	double	img_start_w;
	double	end_x_y;
	int		pos;

	if (v_player()->was_hit_vertical)
		end_x_y = v_player()->end_p_y;
	else
		end_x_y = v_player()->end_p_x;
	pos = end_x_y / TILESIZE;
	img_start_w = (end_x_y - (pos * TILESIZE)) * (img_w / TILESIZE);
	return (img_start_w);
}
