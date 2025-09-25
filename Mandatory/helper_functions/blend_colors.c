/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blend_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bann <oel-bann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 05:21:03 by oel-bann          #+#    #+#             */
/*   Updated: 2025/09/25 01:16:10 by oel-bann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helper.h"

unsigned int	blend_colors(unsigned int bg, unsigned int fg, float alpha)
{
	int r_bg, (g_bg), (b_bg);
	int r_fg, (g_fg), (b_fg);
	int r, (g), (b);
	r_bg = (bg >> 16) & 0xFF;
	g_bg = (bg >> 8) & 0xFF;
	b_bg = bg & 0xFF;
	r_fg = (fg >> 16) & 0xFF;
	g_fg = (fg >> 8) & 0xFF;
	b_fg = fg & 0xFF;
	r = r_bg + (r_fg - r_bg) * alpha;
	g = g_bg + (g_fg - g_bg) * alpha;
	b = b_bg + (b_fg - b_bg) * alpha;
	return ((r << 16) | (g << 8) | b);
}
