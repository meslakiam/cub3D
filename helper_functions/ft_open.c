/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 05:52:58 by oel-bann          #+#    #+#             */
/*   Updated: 2025/07/19 18:32:01 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helper.h"

int	ft_open(char *file_name, int flag, int perm)
{
	int	fd;

	fd = -1;
	if (!file_name)
	{
        write(2, "Error:\n --> File can't open\n", 28);
		ft_exit(255);
	}
	fd = open(file_name, flag, perm);
	if (fd == -1)
	{
        write(2, "Error:\n --> File can't open\n", 28);
		ft_exit(255);
	}
	return (fd);
}
