SRCS = ft_printf.c ft_print_char.c ft_print_string.c ft_print_hex.c ft_print_integer.c ft_print_pointer.c ft_print_unsigned.c

OBJS = $(SRCS:.c=.o)

NAME = libftprintf.a

CC = cc

RM = rm -rf

AR = ar rcs

CFLAGS = -Wall -Wextra -Werror

LIBFT_PATH = libft
LIBFT = $(LIBFT_PATH)/libft.a

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(AR)  $(NAME) $(OBJS) $(LIBFT)

$(LIBFT):
	make -C $(LIBFT_PATH) all

clean:
	make -C $(LIBFT_PATH) clean
	$(RM) $(OBJS)

fclean_ft:
	make -C $(LIBFT_PATH) fclean

fclean: fclean_ft clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

