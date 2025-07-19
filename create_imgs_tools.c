/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_imgs_tools.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bann <oel-bann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 17:29:44 by oel-bann          #+#    #+#             */
/*   Updated: 2025/07/19 17:51:53 by oel-bann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cube3d.h"

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

void check_is_exp_dir(char *path, t_img **img_saver)
{
	if (ft_strnstr(path, "000", ft_strlen(path)))
		ft_lstadd_img(img_saver, ft_lstnew_img(path, 'E'));
	else if (ft_strnstr(path, "009", ft_strlen(path)))
		ft_lstadd_img(img_saver, ft_lstnew_img(path, 'N'));
	else if (ft_strnstr(path, "018", ft_strlen(path)))
		ft_lstadd_img(img_saver, ft_lstnew_img(path, 'W'));
	else if (ft_strnstr(path, "027", ft_strlen(path)))
		ft_lstadd_img(img_saver, ft_lstnew_img(path, 'S'));
	else
		ft_lstadd_img(img_saver, ft_lstnew_img(path, ' '));
}

int	count_img(char *semi_path, t_img **img_saver)
{
	int		count;
	char	*img_full_path;

	count = 0;
	img_full_path = ft_strjoin(semi_path, "img_000.xpm");
	while (img_full_path != NULL)
	{
		check_is_exp_dir(img_full_path, img_saver);
		img_full_path = create_image_path(semi_path, !count);
		count++;
	}
	return (count);
}

t_img	*get_pos_pathlst(void)
{
	static t_img	*pos_path_lst;

	if (!pos_path_lst)
		count_img("cube3d_img/palyer_pos/", &pos_path_lst);
	return (pos_path_lst);
}

t_data	*create_image(t_img	*pos_path_lst)
{
	t_data	*data;

	data = ft_calloc(1, sizeof(t_data));
	data->dir = pos_path_lst->dir;
	data->img = mlx_xpm_file_to_image(*g_mlx(), pos_path_lst->path_img,
			&(data->img_width), &(data->img_height));
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
	data->img_height = CELL_H;
    data->img_width = CELL_W;
	if (!(data->img))
	{
		write(2, "Error\n -> create image\n", 23);
		ft_exit(255);
	}
	data->next = NULL;
	save_img(data->img);
	return (data);
}

t_data	*get_pos_img(char dir, int rotation)
{
	static t_data	*pos_lst;
	t_img			*pos_path_lst;

	if (!pos_lst)
	{
		pos_path_lst = get_pos_pathlst();
		while (pos_path_lst)
		{
			ft_lstadd_back_pos(&pos_lst,create_image(pos_path_lst));
			pos_path_lst = pos_path_lst->next;
		}
	}
	while (pos_lst && ft_strrchr("ENWS", dir))
	{
		if (pos_lst->next->dir == dir)
			break;
		pos_lst = pos_lst->next;
	}
	if (pos_lst && rotation)
		pos_lst = pos_lst->next;
	else if (pos_lst && rotation == -1)
		pos_lst = pos_lst->prev;
	return(pos_lst);
}
