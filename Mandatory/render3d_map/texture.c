/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 04:18:45 by oel-bann          #+#    #+#             */
/*   Updated: 2025/09/25 20:39:45 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

t_data	**get_textures(int texture)
{
	static t_data	*n_texture;
	static t_data	*s_texture;
	static t_data	*e_texture;
	static t_data	*w_texture;

	if (texture == TEX_NORTH)
		return (&n_texture);
	else if (texture == TEX_SOUTH)
		return (&s_texture);
	else if (texture == TEX_EAST)
		return (&e_texture);
	else if (texture == TEX_WEST)
		return (&w_texture);
	return (NULL);
}

void	set_textures(void)
{
	int			texture;
	static int	first;
	t_data		**img;
	char		*img_path;

	texture = 1;
	while (!first && texture <= 4)
	{
		if (texture == TEX_NORTH)
			img_path = get_map_info()->no;
		else if (texture == TEX_SOUTH)
			img_path = get_map_info()->so;
		else if (texture == TEX_EAST)
			img_path = get_map_info()->ea;
		else if (texture == TEX_WEST)
			img_path = get_map_info()->we;
		img = get_textures(texture);
		*img = &create_image(&(t_img){img_path, 0}, 0, 0)->content;
		texture++;
	}
	if (!first)
		first = 1;
}

double	get_tex_step(int texture, int ligne_h)
{
	int		image_hight;
	double	step;

	image_hight = 0;
	step = 0;
	if (texture == TEX_EAST)
		image_hight = (*get_textures(TEX_EAST))->img_height;
	else if (texture == TEX_WEST)
		image_hight = (*get_textures(TEX_WEST))->img_height;
	else if (texture == TEX_NORTH)
		image_hight = (*get_textures(TEX_NORTH))->img_height;
	else if (texture == TEX_SOUTH)
		image_hight = (*get_textures(TEX_SOUTH))->img_height;
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
	if (end_y > WINDOW_HEIGHT)
		return ((abs(start_y) + WINDOW_HEIGHT)
			* get_tex_step(texture, end_y - start_y));
	return ((*get_textures(texture))->img_height);
}
