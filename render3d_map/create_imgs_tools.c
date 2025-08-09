/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_imgs_tools.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bann <oel-bann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 17:29:44 by oel-bann          #+#    #+#             */
/*   Updated: 2025/08/06 12:31:19 by oel-bann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "render.h"

char	*create_image_path(char *semi_path, int first_time)
{
	static char *(img_name);
	char *(full_path);
	if (!img_name || first_time)
		img_name = ft_strdup("img_000.xpm");
	while (1)
	{
		if (img_name[6] != '9')
			img_name[6] = img_name[6] + 1;
		else if (img_name[5] != '9')
		{
			img_name[5] = img_name[5] + 1;
			img_name[6] = '0';
		}
		else if (img_name[4] != '9')
		{
			img_name[4] = img_name[4] + 1;
			img_name[5] = '0';
			img_name[6] = '0';
		}
		full_path = ft_strjoin(semi_path, img_name);
		if (open(full_path, O_RDONLY, 0666) != -1)
			return (full_path);
		else
			return (NULL);
	}
}

int	count_img(char *semi_path, t_img **img_saver)
{
	int		count;
	char	*img_full_path;

	count = 0;
	img_full_path = ft_strjoin(semi_path, "img_000.xpm");
	while (img_full_path != NULL)
	{
		ft_lstadd_img(img_saver, ft_lstnew_img(img_full_path));
		img_full_path = create_image_path(semi_path, !count);
		count++;
	}
	return (count);
}

t_img	*get_torch_pathlst(void)
{
	static t_img	*torch_path_lst;

	if (!torch_path_lst)
		count_img("textures/torch/", &torch_path_lst);
	return (torch_path_lst);
}

t_data_list	*get_torch_imgs()
{
	static t_data_list	*torch_lst;
	t_img			*torch_path_lst;

	if (!torch_lst)
	{
		torch_path_lst = get_torch_pathlst();
		while (torch_path_lst)
		{
			ft_lstadd_back_imgs(&torch_lst,create_image(torch_path_lst, 0, 0));
			torch_path_lst = torch_path_lst->next;
		}
	}
	return(torch_lst);
}

t_data_list *get_torch_corner_lst(int texture)
{
	t_data_list	*torch_lst;
	t_data_list *new_torch_lst;
	t_data_list *new_img;
	t_data_list *first_img;
	int (y), (x);
	double (i), (j);
	int color;

	torch_lst = get_torch_imgs();
	first_img = torch_lst;
	new_torch_lst = NULL;
	while (torch_lst)
	{
		new_img = mlx_copy_img(get_textures(texture), 512, 512);
		mlx_put_image_to_window(v_global()->mlx, v_global()->mlx_win, new_img->content.img, 0, 0);
		y = new_img->content.img_height / 2 - torch_lst->content.img_height;
		i = 0;
		while (y < new_img->content.img_height / 2 - torch_lst->content.img_height / 2 + torch_lst->content.img_height * 2)
		{
			x = new_img->content.img_width / 2 - torch_lst->content.img_width;
			j = 0;
			while (x < new_img->content.img_width / 2 - torch_lst->content.img_width / 2 + torch_lst->content.img_width * 2)
			{
				color =  my_mlx_get_pixel_color(&torch_lst->content, j, i);
				if (color != 0)
            		my_mlx_pixel_put(&new_img->content, x, y, color);
				x++;
				j += (double)torch_lst->content.img_width / ((double)torch_lst->content.img_width * 2);
			}
			y++;
			i += (double)torch_lst->content.img_height / ((double)torch_lst->content.img_height * 2);
		}
		ft_lstadd_back_imgs(&new_torch_lst, new_img);
		torch_lst = torch_lst->next;
		if (first_img == torch_lst)
			break;
	}
	return (new_torch_lst);
}

t_data_list *get_west_torch_lst()
{
	static t_data_list *west_torch_lst;

	if (!west_torch_lst)
	{
		west_torch_lst = get_torch_corner_lst(TEX_WEST);
		return(west_torch_lst);
	}
	west_torch_lst = west_torch_lst->next;
	return (west_torch_lst);
}

t_data_list *get_east_torch_lst()
{
	static t_data_list *east_torch_lst;

	if (!east_torch_lst)
	{
		east_torch_lst = get_torch_corner_lst(TEX_EAST);
		return(east_torch_lst);
	}
	east_torch_lst = east_torch_lst->next;
	return (east_torch_lst);
}
// int get_new_win_flag(int set)
// {
// 	static int new_win_flag;

// 	if (set == 1)
// 		new_win_flag = 1;
// 	else if (set == 2)
// 		new_win_flag = 0;
// 	return (new_win_flag);
// }