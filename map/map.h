/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 15:41:15 by imeslaki          #+#    #+#             */
/*   Updated: 2025/07/19 19:38:53 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H


# include "../garbage_collector/garbage_collector.h"
# include "../helper_functions/helper.h"
# include "../player/player.h"
// # include "../cube3d.h"
# include "../defines.h"



// typedef struct s_data t_data;

t_map   *v_map(void);
void    draw_pixel(int y, int x, int color);
void    draw_square(int y, int x, int color);
void    draw_circle(double center_y, double center_x, int radius, int color);
double draw_line(int x0, int y0, int x1, int y1, int color);

#endif