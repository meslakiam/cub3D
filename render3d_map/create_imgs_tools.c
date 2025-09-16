/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_imgs_tools.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 17:29:44 by oel-bann          #+#    #+#             */
/*   Updated: 2025/09/16 17:38:51 by imeslaki         ###   ########.fr       */
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

t_img	*get_door_pathlst(void)
{
	static t_img	*door_path_lst;

	if (!door_path_lst)
		count_img("textures/door/", &door_path_lst);
	return (door_path_lst);
}

t_data_list	*get_door_imgs(int flag)
{
	static t_data_list	*door_lst;
	t_img			*door_path_lst;

	if (!door_lst)
	{
		door_path_lst = get_door_pathlst();
		while (door_path_lst)
		{
			ft_lstadd_back_imgs(&door_lst,create_image(door_path_lst, 0, 0));
			door_path_lst = door_path_lst->next;
		}
	}
	else if (flag == 1)
		door_lst = door_lst->next;
	return(door_lst);
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