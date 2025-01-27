CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes
MLXFLAGS = -lmlx -lX11 -lXext 

LIBFT_DIR = libft

SRCDIR = src
INCLDIR = includes
OBJDIR = obj

SRC_FILES = main.c map_validation.c map_checking.c map_utils.c utils.c move.c frees.c path_check.c init.c

SRCS = $(addprefix $(SRCDIR)/, $(SRC_FILES))
OBJ		= $(addprefix $(OBJDIR)/, $(SRC_FILES:.c=.o))


LIBFT = $(LIBFT_DIR)/libft.a


NAME = so_long

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(MLXFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -f $(OBJ)
	$(MAKE) clean -C $(LIBFT_DIR)
	
fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean $(NAME)

.PHONY: all clean fclean re
