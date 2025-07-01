NAME = cub3d

CC = cc

# CFLAGS = -Wall -Wextra -Werror

MLX_FLAGS = -lmlx -lX11 -lXext -lm -lz


MAIN =  global.c main_test.c # main.c

GARBAGE_COLLECTOR = garbage_collector/ft_calloc.c garbage_collector/ft_exit.c garbage_collector/ft_free.c \
	garbage_collector/ft_save_mem.c garbage_collector/mem_list.c

HELPER_FUNCTIONS = helper_functions/delete_char_from_str.c helper_functions/delete_str_from_str.c helper_functions/delete_str_len.c \
	helper_functions/ft_atoi.c helper_functions/ft_is_digit.c helper_functions/ft_itoa.c helper_functions/ft_putstr_fd.c \
	helper_functions/ft_split.c helper_functions/ft_str_join.c helper_functions/ft_strchr.c helper_functions/ft_strdup.c \
	helper_functions/ft_strlen.c helper_functions/ft_substr.c helper_functions/insert_char_in_str.c helper_functions/insert_str_in_str.c \
	helper_functions/is_alpha.c helper_functions/is_digit.c helper_functions/join_str_char.c helper_functions/separate_with_one_space.c \
	helper_functions/strcmp.c helper_functions/strlen_2d_array.c helper_functions/strncmp.c helper_functions/strnstr_index.c

PLAYER_MOVEMENT = player_movement/player_movement.c

SRC = $(MAIN) $(GARBAGE_COLLECTOR) $(HELPER_FUNCTIONS) $(PLAYER_MOVEMENT)

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
