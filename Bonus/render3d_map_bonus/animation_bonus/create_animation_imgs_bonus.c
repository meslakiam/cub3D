/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_animation_imgs_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 12:08:19 by oel-bann          #+#    #+#             */
/*   Updated: 2025/09/25 21:58:31 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d_bonus.h"

t_img	*get_run_pathlst(void)
{
	static t_img	*run_path_lst;

	if (!run_path_lst)
		count_img("Bonus/textures/p_run/", &run_path_lst);
	return (run_path_lst);
}

t_data_list	*get_run_imgs(int flag)
{
	static t_data_list	*run_lst;
	static t_data_list	*lst_head;
	t_img				*run_path_lst;

	if (!run_lst)
	{
		run_path_lst = get_run_pathlst();
		while (run_path_lst)
		{
			ft_lstadd_back_imgs(&run_lst, create_image(run_path_lst, 0, 0));
			run_path_lst = run_path_lst->next;
		}
		lst_head = run_lst;
		run_lst = run_lst->prev;
	}
	else if (flag == 1)
		run_lst = run_lst->next;
	else if (flag == 2)
		run_lst = lst_head;
	return (run_lst);
}

t_img	*get_fire_pathlst(void)
{
	static t_img	*run_path_lst;

	if (!run_path_lst)
		count_img("Bonus/textures/gun_fire/", &run_path_lst);
	return (run_path_lst);
}

t_data_list	*get_fire_imgs(int flag)
{
	static t_data_list	*fire_lst;
	static t_data_list	*lst_head;
	t_img				*fire_path_lst;

	if (!fire_lst)
	{
		fire_path_lst = get_fire_pathlst();
		while (fire_path_lst)
		{
			ft_lstadd_back_imgs(&fire_lst, create_image(fire_path_lst, 0, 0));
			fire_path_lst = fire_path_lst->next;
		}
		lst_head = fire_lst;
	}
	if (fire_lst->next == lst_head)
		v_player()->fire = 0;
	if (flag == 1)
		fire_lst = fire_lst->next;
	return (fire_lst);
}

t_data_list	*get_static_pos(void)
{
	static t_data_list	*s_pos;
	t_img				s_pos_path;

	s_pos_path.path_img = "Bonus/textures/s_pos/img_000.xpm";
	if (!s_pos)
	{
		s_pos = create_image(&s_pos_path, 0, 0);
	}
	return (s_pos);
}
