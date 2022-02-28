NAME            =       so_long

CFLAGS          =       -Wall -Wextra -Werror

MLX_FLAGS               =       -lm -lXext -lX11

CC              =	gcc

FILES            =       main.c gnl_romain/get_next_line.c gnl_romain/get_next_line_utils.c utils_libft.c\
						errors_check.c parsing.c display.c move_player.c
SRCS			= $(addprefix sources/,$(FILES))
OBJS            = $(SRCS:.c=.o)

all             :	$(NAME)

$(NAME) :       $(OBJS)
			     make -C minilibx-linux
				$(CC) $(CFLAGS) -o $(NAME) $(OBJS) minilibx-linux/libmlx.a $(MLX_FLAGS)

%.c.o           :
		$(CC) $(CFLAGS) -c -I minilibx-linux/ $< -o $(<:.c=.o)


clean   :	
		make clean -C minilibx-linux
		rm -rf $(OBJS)

fclean  :       clean
		rm -f $(NAME)

re      :	fclean all

.PHONY  :	all re clean fclean





