/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_img.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bann <oel-bann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 01:07:38 by oel-bann          #+#    #+#             */
/*   Updated: 2025/08/03 07:01:50 by oel-bann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helper.h"

t_img	*ft_lstnew_img(char *content)
{
	t_img	*node;

	node = (t_img *)ft_calloc(sizeof(t_img), 1);
	if (!node)
		return (NULL);
	node->path_img = content;
	node->next = NULL;
	return (node);
}
