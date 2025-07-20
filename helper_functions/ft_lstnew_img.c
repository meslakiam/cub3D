/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_img.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 01:07:38 by oel-bann          #+#    #+#             */
/*   Updated: 2025/07/19 18:32:01 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helper.h"

t_img	*ft_lstnew_img(char *content, char dir)
{
	t_img	*node;

	node = (t_img *)ft_calloc(sizeof(t_img), 1);
	if (!node)
		return (NULL);
	node->path_img = content;
	node->dir = dir;
	node->next = NULL;
	return (node);
}
