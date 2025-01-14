CC = cc
CFLAGS = -Wall -Wextra -Werror -g
MLXFLAGS = -lmlx -lX11 -lXext 

LIBFT_DIR = libft
GNL_DIR = GNL

SRCS = main.c map_validation.c map_checking.c map_utils.c
OBJS = $(SRCS:.c=.o)


LIBFT = $(LIBFT_DIR)/libft.a

GNL_OBJS = $(GNL_DIR)/get_next_line.o $(GNL_DIR)/get_next_line_utils.o

NAME = so_long

$(NAME): $(OBJS) $(LIBFT) $(GNL_OBJS) 
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(GNL_OBJS) $(MLXFLAGS)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(GNL_DIR)
	

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(MAKE) fclean -C $(GNL_DIR)
	


re: fclean $(NAME)

.PHONY: all clean fclean re