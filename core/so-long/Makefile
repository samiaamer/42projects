CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = read_map.c get_next_line.c ft_strdup.c ft_strjoin.c ft_strchr.c  ft_strlcpy.c ft_memcpy.c
OBJ = $(SRC:.c=.o)
NAME = so_long

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)
