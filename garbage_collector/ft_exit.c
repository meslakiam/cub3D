/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bann <oel-bann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 18:13:22 by oel-bann          #+#    #+#             */
/*   Updated: 2025/07/19 11:14:54 by oel-bann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"
#include "garbage_collector.h"

void	ft_exit(int status)
{
	ft_destroy_all();
	if (*g_window())
		mlx_destroy_window(*g_mlx(), *g_window());
	mlx_destroy_display(*g_mlx());
	free(*g_mlx());
	ft_free_all();
	exit(status);
}

void	*current_working_mem(void *mem, int set_to_null)
{
	static void	*working_mem;

	if (set_to_null)
		working_mem = NULL;
	if (mem)
		working_mem = mem;
	return (working_mem);
}
