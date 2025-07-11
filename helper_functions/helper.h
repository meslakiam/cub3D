/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 01:42:47 by imeslaki          #+#    #+#             */
/*   Updated: 2025/07/11 16:28:40 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPER_H
# define HELPER_H


#include "unistd.h"
#include "stdio.h"
#include "stdlib.h"
# include "../garbage_collector/garbage_collector.h"

char	*ft_strjoin(char *s1, char *s2);
int		ft_strcmp(char *s1, char *s2);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strchr(char *str, int c);
char	*join_str_char(char *str, char c);
size_t	ft_strlen(char *str);
char	*ft_itoa(int n);
char	*ft_strdup(char *s1);
int		is_alpha(int c);
int		is_digit(int n);
char	**ft_split(char *s, char c);
char	*ft_substr(char *s, unsigned int start, size_t len);
int		ft_isdigit(int c);
int	ft_atoi(const char *str);
#endif