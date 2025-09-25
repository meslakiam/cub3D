/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bann <oel-bann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 13:23:56 by imeslaki          #+#    #+#             */
/*   Updated: 2025/09/25 16:53:20 by oel-bann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	cast_rays_and_render_game(void)
{
	t_ray_info	ray;
	t_global	*data;
	int			i;

	i = 0;
	data = v_global();
	ray = get_ray_info();
	set_textures();
	while (i < ray.num_of_rays)
	{
		ray_casting_update_p(ray.ray_angle);
		render(i, ray.ray_angle);
		ray.ray_angle += (double)FOV / (double)ray.num_of_rays;
		i++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->win_img->img, 0, 0);
}

int	create_game(void)
{
	render_floor_and_sky();
	move_the_player();
	cast_rays_and_render_game();
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
		mlx_mouse_move(v_global()->mlx, v_global()->mlx_win, WINDOW_WIDTH / 2,
				WINDOW_HEIGHT / 2);
		mlx_mouse_hide(v_global()->mlx, v_global()->mlx_win);
		mlx_hook(v_global()->mlx_win, 17, 0, destroy_window, NULL);
		mlx_hook(v_global()->mlx_win, 2, 1L << 0, key_press, NULL);
		mlx_hook(v_global()->mlx_win, 3, 1L << 1, key_release, NULL);
		mlx_loop_hook(v_global()->mlx, create_game, NULL);
		mlx_loop(v_global()->mlx);
	}
	return (0);
}
