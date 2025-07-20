/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 03:46:42 by oel-bann          #+#    #+#             */
/*   Updated: 2025/07/19 18:32:01 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helper.h"

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
