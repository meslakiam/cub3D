/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bann <oel-bann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 04:18:45 by oel-bann          #+#    #+#             */
/*   Updated: 2025/09/25 16:10:05 by oel-bann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d_bonus.h"

t_data	**get_textures_bonus(int texture)
{
	static t_data	*n_texture;
	static t_data	*s_texture;
	static t_data	*e_texture;
	static t_data	*w_texture;
	static t_data	*door_texture;

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

void	set_textures_bonus(void)
{
	int			texture;
	static int	first;
	t_data		**img;
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
		else
			img_path = get_map_info()->door;
		img = get_textures_bonus(texture);
		*img = &create_image(&(t_img){img_path, 0}, 0, 0)->content;
		texture++;
	}
	if (!first)
		first = 1;
}

double	get_tex_step_bonus(int texture, int ligne_h)
{
	int		image_hight;
	double	step;

	image_hight = 0;
	step = 0;
    if(texture == TEX_DOOR)
        image_hight = (*get_textures_bonus(TEX_DOOR))->img_height;
	else if (texture == TEX_EAST)
		image_hight = (*get_textures_bonus(TEX_EAST))->img_height;
	else if (texture == TEX_WEST)
		image_hight = (*get_textures_bonus(TEX_WEST))->img_height;
	else if (texture == TEX_NORTH)
		image_hight = (*get_textures_bonus(TEX_NORTH))->img_height;
	else if (texture == TEX_SOUTH)
		image_hight = (*get_textures_bonus(TEX_SOUTH))->img_height;
	step = (double)image_hight / (double)ligne_h;
	return (step);
}

double	get_tex_start_bonus(int start_y, int end_y, int texture)
{
	if (start_y < 0)
		return (abs(start_y) * get_tex_step_bonus(texture, end_y
				- start_y));
	return (0);
}