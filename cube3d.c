/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bann <oel-bann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 02:52:21 by oel-bann          #+#    #+#             */
/*   Updated: 2025/07/19 17:10:57 by oel-bann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int key_press()
{
    
}
int main(int argc, char *argv[])
{
    if (argc != 2)
        write(2, "Error\n ---> The Map Args Not Valid\n", 35);
    else
    {
        check_map(argv[1]);
	    g_window();
        draw_map();
        mlx_hook(*g_window(), on_keydown, key_press, )
	    mlx_loop(*g_mlx());
        
    }
    return 0;
}
