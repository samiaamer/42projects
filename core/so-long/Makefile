CC = cc
CFLAGS = -Wall -Wextra -Werror -g
MLXFLAGS = -lmlx -lX11 -lXext 

LIBFT_DIR = libft

SRCS = main.c map_validation.c map_checking.c map_utils.c utils.c move.c frees.c path_check.c init.c
OBJS = $(SRCS:.c=.o)


LIBFT = $(LIBFT_DIR)/libft.a


NAME = so_long

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(MLXFLAGS)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) clean -C $(LIBFT_DIR)
	

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean $(NAME)

.PHONY: all clean fclean re
