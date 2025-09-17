/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blend_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bann <oel-bann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 05:21:03 by oel-bann          #+#    #+#             */
/*   Updated: 2025/07/26 05:21:26 by oel-bann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "helper.h"

unsigned int blend_colors(unsigned int bg, unsigned int fg, float alpha) {
    int r_bg = (bg >> 16) & 0xFF;
    int g_bg = (bg >> 8) & 0xFF;
    int b_bg = bg & 0xFF;

    int r_fg = (fg >> 16) & 0xFF;
    int g_fg = (fg >> 8) & 0xFF;
    int b_fg = fg & 0xFF;

    int r = r_bg + (r_fg - r_bg) * alpha;
    int g = g_bg + (g_fg - g_bg) * alpha;
    int b = b_bg + (b_fg - b_bg) * alpha;

    return (r << 16) | (g << 8) | b;
}