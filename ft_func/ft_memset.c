/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bann <oel-bann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 03:46:42 by oel-bann          #+#    #+#             */
/*   Updated: 2025/07/16 03:47:10 by oel-bann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_func.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*tab;
	size_t			i;

	tab = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		tab[i] = (unsigned char)c;
		i++;
	}
	return ((void *)tab);
}
