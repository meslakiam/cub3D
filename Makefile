NAME = cube3d

BONUS_NAME = cube3d_bonus

CC = cc

CFLAGS = -Wall -Wextra -Werror -g3

MLX_FLAGS = -lmlx -lX11 -lXext -lm -lz

MANDATORY_MAIN = Mandatory/fill_data.c Mandatory/cub3d.c Mandatory/global.c

BONUS_MAIN = Bonus/cub3d_bonus.c Mandatory/global.c Bonus/create_mini_map_bonus.c Bonus/mouse_move_bonus.c \
	Bonus/draw_functions_bonus.c Mandatory/fill_data.c 

GARBAGE_COLLECTOR = Mandatory/garbage_collector/ft_calloc.c Mandatory/garbage_collector/ft_exit.c \
	Mandatory/garbage_collector/ft_free.c Mandatory/garbage_collector/ft_save_mem.c \
	Mandatory/garbage_collector/mem_list.c

HELPER_FUNCTIONS = Mandatory/helper_functions/ft_atoi.c Mandatory/helper_functions/ft_lstadd_back.c \
	Mandatory/helper_functions/ft_lstadd_back_imgs.c Mandatory/helper_functions/ft_open.c \
	Mandatory/helper_functions/ft_lstadd_img.c Mandatory/helper_functions/ft_lstnew.c \
	Mandatory/helper_functions/ft_lstnew_img.c Mandatory/helper_functions/ft_strjoin.c\
	Mandatory/helper_functions/ft_memset.c Mandatory/helper_functions/ft_split.c \
	Mandatory/helper_functions/ft_strchr.c Mandatory/helper_functions/ft_strdup.c \
	Mandatory/helper_functions/ft_strlen.c \
	Mandatory/helper_functions/ft_strncmp.c Mandatory/parsing/check_map_component_tools.c \
	Mandatory/helper_functions/ft_strrchr.c Mandatory/helper_functions/blend_colors.c \
	Mandatory/helper_functions/create_image.c Mandatory/helper_functions/mlx_get_pixel_color.c \
	Mandatory/helper_functions/mlx_put_pixel.c Mandatory/helper_functions/ft_lstremove.c \
	

PARSING = Mandatory/parsing/check_ext_isvalid.c Mandatory/parsing/check_map.c \
	Mandatory/parsing/check_map_component.c Mandatory/parsing/check_texture.c \
	Mandatory/parsing/fill_cube_face_texture.c Mandatory/parsing/fill_map_infos.c \
	Mandatory/parsing/parssing_geters.c Mandatory/parsing/remove_map_extra.c

PARSING_BONUS = $(PARSING) Bonus/parsing_bonus/check_map_component_bonus.c Bonus/parsing_bonus/check_map_bonus.c \
	Bonus/parsing_bonus/check_texture_bonus.c Bonus/parsing_bonus/fill_cube_face_texture_bonus.c \
	Bonus/parsing_bonus/fill_map_infos_bonus.c

PLAYER = Mandatory/player/init_player.c Mandatory/player/is_wall.c \
	Mandatory/player/key_handling.c Mandatory/player/player_movement.c \
	Mandatory/player/rotations_functions.c

PLAYER_BONUS = $(PLAYER) Bonus/player_bonus/player_movement_bonus.c Bonus/player_bonus/key_handling_bonus.c \
	Bonus/player_bonus/door_checkers_bonus.c

RAY_CASTING = Mandatory/ray_casting/cast_ray.c Mandatory/ray_casting/ray_info.c \
	Mandatory/ray_casting/vertical_intersection.c Mandatory/ray_casting/horizontal_intersection.c

RENDER3D_MAP = Mandatory/render3d_map/render.c Mandatory/render3d_map/render_tools.c \
	Mandatory/render3d_map/texture.c

RENDER3D_MAP_BONUS = $(RENDER3D_MAP) Bonus/render3d_map_bonus/create_imgs_tools_bonus.c Bonus/render3d_map_bonus/render_bonus.c \
	Bonus/render3d_map_bonus/texture_bonus.c Bonus/render3d_map_bonus/animation_bonus/create_animation_imgs_bonus.c \
	Bonus/render3d_map_bonus/animation_bonus/draw_animation_bonus.c Bonus/render3d_map_bonus/animation_bonus/get_player_animation_bonus.c



GET_NEXT_LINE = Mandatory/get/get_next_line.c Mandatory/get/get_next_line_utils.c

SRC_MANDATORY = $(MANDATORY_MAIN) $(GARBAGE_COLLECTOR) $(HELPER_FUNCTIONS) $(PARSING) \
	$(PLAYER) $(RAY_CASTING) $(RENDER3D_MAP) $(GET_NEXT_LINE)

SRC_BONUS = $(BONUS_MAIN) $(GARBAGE_COLLECTOR) $(HELPER_FUNCTIONS) $(PARSING_BONUS) $(RAY_CASTING) $(GET_NEXT_LINE) \
	$(PLAYER_BONUS) $(RENDER3D_MAP_BONUS) 

OBJ_MANDATORY = $(SRC_MANDATORY:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

$(NAME): $(OBJ_MANDATORY)
	$(CC) $(CFLAGS) $(OBJ_MANDATORY) $(MLX_FLAGS) -o $(NAME)

clean:
	rm -rf $(OBJ_MANDATORY) $(OBJ_BONUS)

fclean: clean
	rm -rf $(NAME) $(BONUS_NAME)

re: fclean all

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(OBJ_BONUS)
	$(CC) $(CFLAGS) $(OBJ_BONUS) $(MLX_FLAGS) -o $(BONUS_NAME)

.PHONY: all clean fclean re

.SECONDARY : $(OBJ_MANDATORY) $(OBJ_BONUS)
