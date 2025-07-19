/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ext_isvalid.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bann <oel-bann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 01:43:02 by oel-bann          #+#    #+#             */
/*   Updated: 2025/07/05 00:56:48 by oel-bann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

int	check_ext_isvalid(char *file_name)
{
	char	*ext;
	char	**splited;

	int (i) = 0;
	if (ft_strrchr(file_name, '/'))
	{
		splited = ft_split(file_name, "/");
		while (splited[i + 1])
			i++;
		ext = ft_strrchr(splited[i], '.');
		file_name = splited[i];
	}
	else
		ext = ft_strrchr(file_name, '.');
	if (ext && ft_strncmp(ext, ".cub", ft_strlen(ext)) == 0 && \
		ft_strlen(file_name) >= 5)
		return (1);
	return (0);
}
