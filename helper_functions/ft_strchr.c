/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 04:04:24 by oel-bann          #+#    #+#             */
/*   Updated: 2025/07/20 15:53:36 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helper.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;
	int	lents;

	i = 0;
	if (!s)
		return (NULL);
	lents = (int)ft_strlen(s);
	if ((char)c == '\0')
		return ((char *)&s[lents]);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}