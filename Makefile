NAME = cube3d

CC = cc

#-Wall -Wextra -Werror 

CFLAGS = -I/usr/include -Imlx_linux -O3 -g

SRC = ./cube3d.c garbage_collector/ft_calloc.c garbage_collector/ft_exit.c garbage_collector/ft_free.c garbage_collector/ft_save_mem.c  garbage_collector/mem_list.c \
./parsing/check_ext_isvalid.c ./parsing/fill_cube_face_texture.c ./parsing/fill_map_infos.c ./parsing/check_texture.c ./parsing/check_map_component.c \
./parsing/parssing_geters.c ./parsing/remove_map_extra.c ./parsing/check_map.c ./ft_func/ft_atoi.c ./ft_func/ft_open.c ./ft_func/ft_strncmp.c\
./ft_func/ft_strchr.c ./ft_func/ft_strrchr.c ./ft_func/ft_strdup.c ./ft_func/ft_strjoin.c ./ft_func/ft_strlcat.c ./ft_func/ft_strlen.c ./get/get_next_line_utils.c\
./ft_func/ft_split.c ./ft_func/ft_lstnew.c ./ft_func/ft_lstadd_back.c ./ft_func/ft_lstremove.c ./ft_func/ft_memset.c  ./get/get_next_line.c \
./window_tools.c ./create_map_imgs.c ./create_imgs_tools.c ft_func/ft_lstadd_img.c ft_func/ft_lstnew_img.c ft_func/ft_strnstr.c ft_func/ft_lstadd_back_pos_img.c\
./draw_map.c
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY:  all clean fclean re
