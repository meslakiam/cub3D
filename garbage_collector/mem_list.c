/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bann <oel-bann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 18:13:49 by oel-bann          #+#    #+#             */
/*   Updated: 2025/04/11 09:39:30 by oel-bann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "garbage_collector.h"

t_mem_list	**ft_mem_list(void)
{
	static t_mem_list	*list;

	return (&list);
}

t_mem_list	**ft_img_list(void)
{
	static t_mem_list	*list;

	return (&list);
}
