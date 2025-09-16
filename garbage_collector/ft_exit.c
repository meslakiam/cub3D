/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 01:47:18 by imeslaki          #+#    #+#             */
/*   Updated: 2025/09/13 18:48:27 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "garbage_collector.h"
#include "../helper_functions/helper.h"
void	ft_exit(int status)
{
	ft_destory_all();
	if (v_global()->mlx && v_global()->mlx_win)
		mlx_destroy_window(v_global()->mlx, v_global()->mlx_win);
	if (v_global()->mlx)
		mlx_destroy_display(v_global()->mlx);
	ft_free_all();
	free(v_global()->mlx);
	exit(status);
	return ;
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
