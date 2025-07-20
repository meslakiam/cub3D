/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 03:25:53 by oel-bann          #+#    #+#             */
/*   Updated: 2025/07/19 19:43:20 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPER_H
# define HELPER_H

# include "../garbage_collector/garbage_collector.h"
# include <fcntl.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_map
{
	char				*map_line;
	struct s_map		*prev;
	struct s_map		*next;
}						t_map;

typedef struct t_img
{
	char				*path_img;
	char				dir;
	struct t_img		*next;
}						t_img;

typedef struct s_data
{
	void				*img;
	char				*addr;
	int					bits_per_pixel;
	int					line_length;
	int					endian;
	int					img_width;
	int					img_height;
}						t_data;

typedef struct s_data_list
{
	t_data				content;
	char				dir;
	struct s_data_list	*next;
	struct s_data_list	*prev;
}						t_data_list;

char					*ft_strchr(const char *s, int c);
char					*ft_strdup(const char *s1);
char					*ft_strldup(const char *s1, size_t len);
char					*ft_strjoin(const char *s1, const char *s2);
char					**ft_split(char const *s, char *c);
char					*ft_strrchr(char *s, int c);
char					*ft_strnstr(char *haystack, char *needle, int len);
int						ft_strlen(const char *s);
int						ft_strslen(char **strs);
int						ft_atoi(const char *str);
int						ft_open(char *file_name, int flag, int perm);
int						ft_strncmp(char *s1, char *s2, int n);
void					ft_lstadd_back(t_map **lst, t_map *new);
void					ft_lstremove(t_map **map, t_map *node);
void					*ft_memset(void *b, int c, size_t len);
void					ft_lstadd_img(t_img **lst, t_img *new);
void					ft_lstadd_back_pos(t_data_list **lst, t_data_list *new);
size_t					ft_strlcat(char *dst, const char *src, size_t dstsize);
t_map					*ft_lstnew(void *content);
t_img					*ft_lstnew_img(char *content, char dir);

#endif