/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bann <oel-bann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 18:13:28 by oel-bann          #+#    #+#             */
/*   Updated: 2025/07/19 13:32:10 by oel-bann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"
#include "garbage_collector.h"

void	ft_free_all(void)
{
	t_mem_list	**list;
	t_mem_list	*tmp;
	void		*mem;

	list = ft_mem_list();
	if (!list || !(*list))
		return ;
	while (*list)
	{
		tmp = *list;
		*list = (*list)->next;
		free(tmp->mem);
		free(tmp);
	}
	mem = current_working_mem(NULL, 0);
	free(mem);
	current_working_mem(NULL, 1);
}

void	find_to_free(void *mem)
{
	t_mem_list	*head;
	t_mem_list	*prev;

	head = (*ft_mem_list());
	while (head)
	{
		prev = head;
		head = head->next;
		if (head->mem == mem)
		{
			prev->next = head->next;
			free(head->mem);
			free(head);
			return ;
		}
	}
	free(mem);
}

void	ft_free(void *mem)
{
	t_mem_list	**mems;
	t_mem_list	*head;

	mems = ft_mem_list();
	if (!(*mems))
		return ;
	head = (*mems);
	if ((*mems)->mem == mem)
	{
		(*mems) = (*mems)->next;
		free(head->mem);
		free(head);
		return ;
	}
	find_to_free(mem);
}

void	ft_destroy_all(void)
{
	t_mem_list	**list;
	t_mem_list	*tmp;

	list = ft_img_list();
	if (!list || !(*list))
		return ;
	while (*list)
	{
		tmp = *list;
		*list = (*list)->next;
		mlx_destroy_image(*(g_mlx()), tmp->mem);
		free(tmp);
	}
}
