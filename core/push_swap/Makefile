CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes

LIBFT_DIR = libft

SRCDIR = src
INCLDIR = includes
OBJDIR = obj

SRC_FILES = main.c create_stack.c indexing.c free.c swap.c rotate.c push.c simple_sort.c 

SRCS = $(addprefix $(SRCDIR)/, $(SRC_FILES))
OBJ		= $(addprefix $(OBJDIR)/, $(SRC_FILES:.c=.o))


LIBFT = $(LIBFT_DIR)/libft.a


NAME = push_swap

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)

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
