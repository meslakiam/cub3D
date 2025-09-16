/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 04:18:45 by oel-bann          #+#    #+#             */
/*   Updated: 2025/09/16 16:14:00 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

t_data	*get_textures(int texture)
{
	static t_data	n_texture;
	static t_data	s_texture;
	static t_data	e_texture;
	static t_data	w_texture;
	static t_data	door_texture;

	if (texture == TEX_NORTH)
		return (&n_texture);
	else if (texture == TEX_SOUTH)
		return (&s_texture);
	else if (texture == TEX_EAST)
		return (&e_texture);
	else if (texture == TEX_WEST)
		return (&w_texture);
	else if (texture == TEX_DOOR)
		return (&door_texture);
	return (NULL);
}

void	set_textures(void)
{
	int			texture;
	static int	first;
	t_data		*img;
	char		*img_path;

	texture = 1;
	while (!first && texture <= 5)
	{
		if (texture == TEX_NORTH)
			img_path = get_map_info()->no;
		else if (texture == TEX_SOUTH)
			img_path = get_map_info()->so;
		else if (texture == TEX_EAST)
			img_path = get_map_info()->ea;
		else if (texture == TEX_WEST)
			img_path = get_map_info()->we;
		else if (texture == TEX_DOOR)
			img_path = get_map_info()->door;
		img = get_textures(texture);
		img->img = mlx_xpm_file_to_image(v_global()->mlx, img_path,
				&img->img_width, &img->img_height);
		img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
				&img->line_length, &img->endian);
		texture++;
	}
	if (!first)
		first = 1;
}

double	get_tex_step(int texture, int ligne_h)
{
	int		image_hight;
	double	step;

    if(texture == TEX_DOOR)
        image_hight = get_textures(TEX_DOOR)->img_height;
	else if (texture == TEX_EAST)
		image_hight = get_textures(TEX_EAST)->img_height;
	else if (texture == TEX_WEST)
		image_hight = get_textures(TEX_WEST)->img_height;
	else if (texture == TEX_NORTH)
		image_hight = get_textures(TEX_NORTH)->img_height;
	else if (texture == TEX_SOUTH)
		image_hight = get_textures(TEX_SOUTH)->img_height;
	step = (double)image_hight / (double)ligne_h;
	return (step);
}

double	get_tex_start(int start_y, int end_y, int texture)
{
	if (start_y < 0)
		return (abs(start_y) * get_tex_step(texture, end_y
				- start_y));
	return (0);
}

double	get_tex_end(int start_y, int end_y, int texture)
{
	if (end_y > window_height)
		return ((abs(start_y) + window_height) * get_tex_step(texture, end_y - start_y));
	return (get_textures(texture)->img_height);
}
