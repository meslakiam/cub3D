/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_img.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bann <oel-bann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:50:09 by oel-bann          #+#    #+#             */
/*   Updated: 2025/07/18 23:43:15 by oel-bann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_func.h"

void	ft_lstadd_img(t_img **lst, t_img *new)
{
	t_img	*temp;

	if (!lst)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		temp = *lst;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}
}

// int main()
// {
//     t_list *node = NULL;
//     // t_list new = {"NULL",NULL};
//     // t_list new1 = {"ilyass", NULL};
//     // t_list new2 = {"ggg",NULL};
//     // t_list new3 = {"oss", NULL};
//     // ft_lstadd_front(&node,&new);
//     // ft_lstadd_front(&node,&new1);
//     // ft_lstadd_front(&node,&new2);
//     // ft_lstadd_front(&node,&new3);
//     t_list last = {"NULL",NULL};
//     ft_lstadd_back(NULL,&last);
//     while(node)
//     {
//         printf("%s\n",node->content);
//         node = node ->next;
//     }
// }