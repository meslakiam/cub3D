/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bann <oel-bann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 04:10:33 by oel-bann          #+#    #+#             */
/*   Updated: 2025/07/16 04:12:42 by oel-bann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_func.h"

int	ft_strcmp(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	if ((!s1 && s2) || (s1 && !s2))
		return (1);
	if (!s1 && !s2)
		return (0);
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_strncmp(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	if ((!s1 && s2) || (s1 && !s2))
		return (1);
	if (!s1 && !s2)
		return (0);
	while ((s1[i] || s2[i]) && n > i)
	{
		if (s1[i] != s2[i])
			return (1);
		i++;
	}
	return (0);
}