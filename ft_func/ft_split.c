/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bann <oel-bann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 21:12:19 by marvin            #+#    #+#             */
/*   Updated: 2025/07/16 03:31:23 by oel-bann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_func.h"

int	countword(char *str, char *sep)
{
	int	i;
	int	countw;

	i = 0;
	countw = 0;
	while (str && str[i])
	{
		if ((!ft_strchr(sep, str[i]) && ft_strchr(sep, str[i + 1])) || \
			(!ft_strchr(sep, str[i]) && str[i + 1] == '\0'))
			countw++;
		i++;
	}
	return (countw);
}

int	countwletters(char *str, char *sep)
{
	int	countlet;

	countlet = 0;
	while (!ft_strchr(sep, str[countlet]) && str[countlet])
		countlet++;
	return (countlet);
}

char	*fill_word(char *str, char *sep)
{
	int		i;
	char	*tab;

	i = 0;
	tab = (char *)ft_calloc(countwletters(str, sep) + 1, sizeof(char));
	if (!tab)
		return (NULL);
	while (i < countwletters(str, sep))
	{
		tab[i] = str[i];
		i++;
	}
	return (tab);
}

char	**ft_split(char const *s, char *c)
{
	char	**tab;

	int i, (y);
	if (!s)
		return (NULL);
	i = 0;
	tab = (char **)ft_calloc((countword((char *)s, c) + 1), sizeof(char *));
	if (!tab)
		return (NULL);
	y = 0;
	while (s && s[i])
	{
		if (!ft_strchr(c, s[i]))
		{
			tab[y] = fill_word((char *)&s[i], c);
			if (!tab[y++])
				return (NULL);
			i = i + countwletters((char *)&s[i], c);
		}
		else
			i++;
	}
	return (tab);
}
