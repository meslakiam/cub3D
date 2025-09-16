/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 13:23:56 by imeslaki          #+#    #+#             */
/*   Updated: 2025/09/16 17:40:34 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	fill_data(void)
{
	t_global	*data;

	data = v_global();
	data->win_img = ft_malloc(sizeof(t_data));
	data->map_img = ft_malloc(sizeof(t_data));
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, window_width, window_height,
			"CUBE3D");
	data->win_img->img_width = window_width;
	data->win_img->img_height = window_height;
	data->map_img->img_width = get_map_info()->win_w * TILESIZE;
	data->map_img->img_height = get_map_info()->win_h * TILESIZE;
	data->win_img->img = mlx_new_image(data->mlx, data->win_img->img_width,
			data->win_img->img_height);
	data->win_img->addr = mlx_get_data_addr(data->win_img->img,
			&data->win_img->bits_per_pixel, &data->win_img->line_length,
			&data->win_img->endian);
	data->map_img->img = mlx_new_image(data->mlx, data->map_img->img_width,
			data->map_img->img_height);
	data->map_img->addr = mlx_get_data_addr(data->map_img->img,
			&data->map_img->bits_per_pixel, &data->map_img->line_length,
			&data->map_img->endian);
}

void	cast_rays_and_render_game(void)
{
	t_ray_info	ray;
	t_global	*data;
	t_data		*shrinked_map;
	int			i;

	i = 0;
	data = v_global();
	ray = get_ray_info();
	get_door_imgs(1);
	while (i < ray.num_of_rays)
	{
		ray_casting_update_p(ray.ray_angle);
		render(i, ray.ray_angle);
		ray.ray_angle += (double)FOV / (double)ray.num_of_rays;
		i++;
	}
	shrinked_map = mlx_shrink_img(data->map_img, v_global()->map_img->img_width
			/ 2, v_global()->map_img->img_height / 2);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->win_img->img, 0, 0);
}

int	create_game(void)
{
	// frames();
	mouse_move();
	render_floor_and_sky();
	move_the_player();
	cast_rays_and_render_game();
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
		mlx_hook(v_global()->mlx_win, 2, 1L << 0, key_press, NULL);
		mlx_hook(v_global()->mlx_win, 3, 1L << 1, key_release, NULL);
		mlx_loop_hook(v_global()->mlx, create_game, NULL);
		mlx_loop(v_global()->mlx);
	}
	return (0);
}
