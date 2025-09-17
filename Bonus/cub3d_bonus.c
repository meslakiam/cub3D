/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 13:23:56 by imeslaki          #+#    #+#             */
/*   Updated: 2025/09/17 20:55:52 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d_bonus.h"

void	cast_rays_and_render_game_bonus(void)
{
	t_ray_info	ray;
	t_global	*data;
	t_data		*shrinked_map;
	int			i;

	i = 0;
	data = v_global();
	ray = get_ray_info();
	set_textures_bonus();
	get_door_imgs(1);
	while (i < ray.num_of_rays)
	{
		ray_casting_update_p(ray.ray_angle);
		render_bonus(i, ray.ray_angle);
		ray.ray_angle += (double)FOV / (double)ray.num_of_rays;
		i++;
	}
	shrinked_map = mlx_shrink_img(data->map_img, v_global()->map_img->img_width
			/ 2, v_global()->map_img->img_height / 2);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->win_img->img, 0, 0);
}

int	create_game_bounus(void)
{
	// frames();
	mouse_move();
	render_floor_and_sky();
	move_the_player_bonus();
	cast_rays_and_render_game_bonus();
	draw_mini_map();
	return (0);
}

int	main(int argc, char *argv[])
{
	if (argc != 2)
		write(2, "Error\n ---> The Map Args Not Valid\n", 35);
	else
	{
		check_map(argv[1]);
		fill_data();
		init_player();
		v_mouse()->use_mouse = 1;
		mlx_mouse_move(v_global()->mlx, v_global()->mlx_win, window_width / 2,
				window_height / 2);
		mlx_mouse_hide(v_global()->mlx, v_global()->mlx_win);
		mlx_hook(v_global()->mlx_win, 17, 0, destroy_window, NULL);
		mlx_hook(v_global()->mlx_win, 2, 1L << 0, key_press_bonus, NULL);
		mlx_hook(v_global()->mlx_win, 3, 1L << 1, key_release, NULL);
		mlx_loop_hook(v_global()->mlx, create_game_bounus, NULL);
		mlx_loop(v_global()->mlx);
	}
	return (0);
}
