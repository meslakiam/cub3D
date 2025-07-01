/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 01:42:47 by imeslaki          #+#    #+#             */
/*   Updated: 2025/07/01 16:13:59 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPER_H
# define HELPER_H


#include "unistd.h"
#include "stdio.h"
#include "stdlib.h"
# include "../garbage_collector/garbage_collector.h"

int		ft_strnstr(char *haystack, char *needle);
int		ft_strncmp(char *s1, char *s2, size_t n);
char	*insert_str_str(char *str, char *insert, int index);
char	*del_str_len(char *str, size_t start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
char	*insert_char_str(char *str, char ch, int i);
int		ft_strcmp(char *s1, char *s2);
char	*del_char_str_index(char *str, int i);
char	*del_str_str(char *str, char *del);
void	ft_putstr_fd(char *s, int fd);
int		strlen_2d_array(char **ptr);
char	*separat_with_one_space(char *str);
char	*ft_strchr(char *str, int c);
char	*join_str_char(char *str, char c);
size_t	ft_strlen(char *str);
char	*ft_itoa(int n);
char	*ft_strdup(char *s1);
int		is_alpha(int c);
int		is_digit(int n);
char	**ft_split(char *s, char c);
void	skip_space(char *str, int *i);
char	*ft_substr(char *s, unsigned int start, size_t len);
int		ft_isdigit(int c);
int	ft_atoi(const char *str);
#endif