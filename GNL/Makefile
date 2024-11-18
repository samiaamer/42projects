SRCS = get_next_line.c get_next_line_utils.c 

OBJS = $(SRCS:.c=.o)

NAME = gnl.a

CC = cc

RM = ar rcs

CFLAGS = -WALL -WEXTRA -WERROR

all: $(NAME)

$(NAME): ${OBJS}
	${AR} ${NAME} ${OBJS}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
