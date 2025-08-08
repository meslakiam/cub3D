/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 03:34:07 by oel-bann          #+#    #+#             */
/*   Updated: 2025/08/08 21:37:18 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helper.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

int	ft_strslen(char **strs)
{
	int	i;

	i = 0;
	while (strs && strs[i])
		i++;
	return (i);
}
