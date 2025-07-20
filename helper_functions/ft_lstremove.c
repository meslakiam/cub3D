/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstremove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 05:41:47 by oel-bann          #+#    #+#             */
/*   Updated: 2025/07/19 18:32:01 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helper.h"

void ft_lstremove(t_map **map, t_map *node)
{

    if (!map || !*map || !node)
        return;

    if (node->prev)
        node->prev->next = node->next;
    else
        *map = node->next;
        
    if (node->next)
        node->next->prev = node->prev;
        
    node->next = NULL;
    node->prev = NULL;
}