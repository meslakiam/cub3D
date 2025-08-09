NAME = cub3d

CC = cc

# CFLAGS = -Wall -Wextra -Werror

MLX_FLAGS = -lmlx -lX11 -lXext -lm -lz


MAIN =  global.c draw_map.c 

GARBAGE_COLLECTOR = garbage_collector/ft_calloc.c garbage_collector/ft_exit.c garbage_collector/ft_free.c \
	garbage_collector/ft_save_mem.c garbage_collector/mem_list.c

HELPER_FUNCTIONS = helper_functions/ft_atoi.c helper_functions/ft_is_digit.c helper_functions/ft_itoa.c helper_functions/ft_putstr_fd.c \
	helper_functions/ft_split.c helper_functions/ft_str_join.c helper_functions/ft_strchr.c helper_functions/ft_strdup.c \
	helper_functions/ft_strlen.c helper_functions/ft_substr.c helper_functions/is_alpha.c helper_functions/is_digit.c \

PLAYER = player/key_handling.c player/player_movement.c

SRC = $(MAIN) $(GARBAGE_COLLECTOR) $(HELPER_FUNCTIONS) $(PLAYER)

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
