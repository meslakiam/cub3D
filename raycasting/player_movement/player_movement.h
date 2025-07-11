/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 16:29:17 by imeslaki          #+#    #+#             */
/*   Updated: 2025/07/04 16:53:17 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_MOVEMENT_H
# define PLAYER_MOVEMENT_H

# include "../cub3d.h"

int     calcul_player_x(void);
int     calcul_player_y(void);
int     player_moves_by_pixels(int *param);
int     player_in_position(void);
int     move_player(int key_code);

#endif