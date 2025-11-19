NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
INCLUDES = -I./minilibx-linux -I. -I./printf
LDFLAGS = -L./minilibx-linux -lmlx -lXext -lX11 -lm
LIBFT = libft/libft.a
PRINTF = printf/libftprintf.a

SRCS = so_long.c move.c get_next_line.c get_next_line_utils.c wall.c map.c img.c move_my_man.c free_all.c 
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) $(LDFLAGS) $(LIBFT) $(PRINTF) -o $(NAME)

$(PRINTF):
	make -C printf
$(LIBFT):
	make -C libft

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C libft clean
	make -C printf clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean
	make -C printf fclean

re: fclean all

.PHONY: all clean fclean re
