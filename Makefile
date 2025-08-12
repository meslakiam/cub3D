NAME = cub3d

CC = cc

# CFLAGS = -Wall -Wextra -Werror

MLX_FLAGS = -lmlx -lX11 -lXext -lm -lz

MAIN = global.c map/draw_map.c map/draw_functions.c cub3d.c

GARBAGE_COLLECTOR = garbage_collector/ft_calloc.c garbage_collector/ft_exit.c \
	garbage_collector/ft_free.c garbage_collector/ft_save_mem.c \
	garbage_collector/mem_list.c

HELPER_FUNCTIONS = helper_functions/ft_atoi.c helper_functions/ft_lstadd_back.c \
	helper_functions/ft_lstadd_back_imgs.c helper_functions/ft_lstadd_back_rays.c \
	helper_functions/ft_lstadd_img.c helper_functions/ft_lstnew.c \
	helper_functions/ft_lstnew_img.c helper_functions/ft_memset.c \
	helper_functions/ft_split.c helper_functions/ft_strchr.c \
	helper_functions/ft_strdup.c helper_functions/ft_strlen.c \
	helper_functions/ft_strlcat.c helper_functions/ft_strncmp.c \
	helper_functions/ft_strnstr.c helper_functions/ft_strrchr.c \
	helper_functions/blend_colors.c helper_functions/create_image.c \
	helper_functions/mlx_get_pixel_color.c helper_functions/mlx_put_pixel.c \
	helper_functions/mlx_copy_image.c helper_functions/mlx_shrink_image.c \
	helper_functions/ft_open.c helper_functions/ft_lstremove.c helper_functions/ft_strjoin.c

PARSING = parsing/check_ext_isvalid.c parsing/check_map.c \
	parsing/check_map_component.c parsing/check_texture.c \
	parsing/fill_cube_face_texture.c parsing/fill_map_infos.c \
	parsing/parssing_geters.c parsing/remove_map_extra.c

PLAYER = player/init_player.c player/is_wall.c \
	player/key_handling.c player/player_movement.c

RAY_CASTING = ray_casting/cast_ray.c ray_casting/ray_info.c

RENDER3D_MAP = render3d_map/create_imgs_tools.c render3d_map/render.c \
	render3d_map/render_tools.c render3d_map/texture.c

MINI_MAP = mini_map/create_mini_map.c

GET_NEXT_LINE = get/get_next_line.c get/get_next_line_utils.c

SRC = $(MAIN) $(GARBAGE_COLLECTOR) $(HELPER_FUNCTIONS) $(PARSING) \
	$(PLAYER) $(RAY_CASTING) $(RENDER3D_MAP) $(MINI_MAP) $(GET_NEXT_LINE)

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MLX_FLAGS) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re

.SECONDARY : $(OBJ)
