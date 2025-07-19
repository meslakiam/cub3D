/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bann <oel-bann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 18:13:43 by oel-bann          #+#    #+#             */
/*   Updated: 2025/04/10 18:42:14 by oel-bann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GARBAGE_COLLECTOR_H
# define GARBAGE_COLLECTOR_H
# include <errno.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_mem_list
{
	void				*mem;
	struct s_mem_list	*next;
}						t_mem_list;

t_mem_list				**ft_mem_list(void);
void					*ft_calloc_without_save(size_t n, size_t type_size);
void					*ft_calloc(size_t n, size_t type_size);
void					ft_exit(int status);
void					*current_working_mem(void *mem, int set_to_null);
void					ft_free_all(void);
void					find_to_free(void *mem);
void					ft_free(void *mem);
void					add_mem(t_mem_list *node);
void					save_mem(void *mem);
void					ft_bzero(void *mem, size_t size);
void					save_img(void *mem);
t_mem_list				**ft_img_list(void);
void					ft_destroy_all(void);

#endif