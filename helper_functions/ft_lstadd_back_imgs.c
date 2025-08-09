/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_imgs.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bann <oel-bann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 03:50:32 by oel-bann          #+#    #+#             */
/*   Updated: 2025/08/04 20:35:34 by oel-bann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helper.h"

void	ft_lstadd_back_imgs(t_data_list **lst, t_data_list *new)
{
	t_data_list	*temp;

	if (!lst)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		new->prev = *lst;
		new->next = *lst;
	}
	else
	{
		temp = (*lst)->prev;
		new->next = *lst;
		new->prev = temp;
		temp->next = new;
	}
}
