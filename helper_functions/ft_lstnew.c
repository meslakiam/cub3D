/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 03:51:47 by oel-bann          #+#    #+#             */
/*   Updated: 2025/07/19 18:32:01 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helper.h"

t_map	*ft_lstnew(void *content)
{
	t_map	*node;

	node = (t_map *)ft_calloc(1, sizeof(t_map));
	if (!node)
		return (NULL);
	node->map_line = content;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}
