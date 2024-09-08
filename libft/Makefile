<<<<<<< HEAD
SRC			= ft_strlen ft_isalpha ft_isdigit ft_isalnum ft_isascii ft_isprint ft_toupper ft_tolower ft_strchr ft_strrchr ft_strncmp ft_strlcpy ft_strlcat ft_atoi ft_memset ft_bzero ft_memcpy ft_memchr ft_memcmp ft_memmove ft_substr
=======
SRC			= ft_strlen ft_isalpha ft_isdigit ft_isalnum ft_isascii ft_isprint ft_toupper ft_tolower ft_strchr ft_strrchr ft_strncmp ft_strlcpy ft_strlcat ft_atoi ft_memset ft_bzero ft_memcpy ft_memchr ft_memcmp ft_strnstr ft_calloc ft_strdup
>>>>>>> 7cbf63ff6b831ea18cee0c71b1b8928a6428f87b
SRCS		= $(addsuffix .c, ${SRC})
OBJS		= ${SRCS:.c=.o}
NAME		= libft.a
CC			= cc
RM			= rm -f
AR			= ar rcs
CFLAGS		= -Wall -Wextra -Werror
all: $(NAME)
%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@
$(NAME): ${OBJS}
	${AR} ${NAME} ${OBJS}
clean:
	${RM} ${OBJS}
fclean: clean
	${RM} ${NAME}
re: fclean all
.PHONY:	all clean fclean re
