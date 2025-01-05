CC = cc
CFLAGS = -Wall -Wextra -Werror

GNL_SRCS = get_next_line.c get_next_line_utils.c
GNL_OBJS = $(GNL_SRCS:.c=.o)

NAME = libgnl.a  

$(NAME): $(GNL_OBJS)
	ar rcs $(NAME) $(GNL_OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(GNL_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
