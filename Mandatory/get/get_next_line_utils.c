/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bann <oel-bann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 07:09:52 by oel-bann          #+#    #+#             */
/*   Updated: 2025/07/05 02:10:46 by oel-bann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// char	*ft_strdup(char *s1)
// {
// 	char	*dupli;
// 	int		i;

// 	i = 0;
// 	if (!s1)
// 		return (NULL);
// 	dupli = (char *)ft_calloc(1, (size_t)(ft_strlen(s1) + 1));
// 	if (dupli == NULL)
// 		return (NULL);
// 	while (s1[i])
// 	{
// 		dupli[i] = s1[i];
// 		i++;
// 	}
// 	dupli[i] = '\0';
// 	return (dupli);
// }

int	ft_line_verifier(char *buf)
{
	int	i;

	i = 0;
	if (!buf)
		return (0);
	while (buf[i])
	{
		if (buf[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}


