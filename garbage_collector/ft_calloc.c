/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bann <oel-bann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 18:13:14 by oel-bann          #+#    #+#             */
/*   Updated: 2025/04/10 22:39:28 by oel-bann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "garbage_collector.h"

void	ft_bzero(void *mem, size_t size)
{
	char	*s;
	size_t	i;

	if (!mem)
		return ;
	s = (char *)mem;
	i = 0;
	while (i < size)
	{
		*s = '\0';
		s++;
		i++;
	}
}

void	*ft_calloc_without_save(size_t n, size_t type_size)
{
	void	*mem;
	size_t	full_size;

	full_size = n * type_size;
	mem = malloc(full_size);
	if (!mem)
	{
		write(2, "Error\n -> memory allocation\n", 28);
		ft_exit(1);
		return (NULL);
	}
	ft_bzero(mem, full_size);
	return (mem);
}

void	*ft_calloc(size_t n, size_t type_size)
{
	void	*mem;

	mem = ft_calloc_without_save(n, type_size);
	save_mem(mem);
	return (mem);
}
