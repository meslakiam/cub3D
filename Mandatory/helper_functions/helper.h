/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bann <oel-bann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 03:25:53 by oel-bann          #+#    #+#             */
/*   Updated: 2025/09/25 16:47:10 by oel-bann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPER_H
# define HELPER_H

# include "../garbage_collector/garbage_collector.h"
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_point
{
	double				x;
	double				y;
}						t_point;

typedef struct s_map
{
	char				*map_line;
	struct s_map		*prev;
	struct s_map		*next;
}						t_map;

typedef struct s_rays_data
{
	int					ray_distance;
	int					ray_angle;
	double				end_x_y;
	struct s_rays_data	*next;
}						t_rays_data;

typedef struct t_img
{
	char				*path_img;
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
	struct s_data_list	*next;
	struct s_data_list	*prev;
}						t_data_list;

typedef struct s_global
{
	void				*mlx;
	void				*mlx_win;
	t_data				*win_img;
}						t_global;

typedef struct s_mouse
{
	double				mouse_speed_anlge;
	int					mouse_direction;
	t_point				mouse_pos;
	int					use_mouse;
}						t_mouse;

typedef enum e_texture
{
	TEX_WEST = 1,
	TEX_EAST = 2,
	TEX_NORTH = 3,
	TEX_SOUTH = 4,
	TEX_DOOR = 5
}						t_tex;

char					*ft_strchr(const char *s, int c);
char					*ft_strdup(const char *s1);
char					*ft_strldup(const char *s1, size_t len);
char					*ft_strjoin(const char *s1, const char *s2);
char					**ft_split(char const *s, char *c);
char					*ft_strrchr(char *s, int c);
int						ft_strlen(const char *s);
int						ft_strslen(char **strs);
int						ft_atoi(const char *str);
int						ft_open(char *file_name, int flag, int perm);
int						ft_strncmp(char *s1, char *s2, int n);
void					ft_lstadd_back(t_map **lst, t_map *new);
void					ft_lstremove(t_map **map, t_map *node);
void					*ft_memset(void *b, int c, size_t len);
void					ft_lstadd_img(t_img **lst, t_img *new);
void					ft_lstadd_back_imgs(t_data_list **lst,
							t_data_list *new);
t_map					*ft_lstnew(void *content);
t_img					*ft_lstnew_img(char *content);
t_global				*v_global(void);
t_mouse					*v_mouse(void);
int						my_mlx_get_pixel_color(t_data *data, int x, int y);
void					my_mlx_pixel_put(t_data *data, int x, int y, int color);
unsigned int			blend_colors(unsigned int bg, unsigned int fg,
							float alpha);
t_data_list				*create_image(t_img *path_lst, int width, int height);

#endif
