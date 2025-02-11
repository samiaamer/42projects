CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes

LIBFT_DIR = libft

SRCDIR = srcs
INCLDIR = includes
OBJDIR = obj

SRC_FILES_CLIENT = client.c
SRC_FILES_SERVER = server.c
 
SRCS_CLIENT = $(addprefix $(SRCDIR)/, $(SRC_FILES_CLIENT))
SRCS_SERVER = $(addprefix $(SRCDIR)/, $(SRC_FILES_SERVER))

OBJ_CLIENT = $(addprefix $(OBJDIR)/, $(SRC_FILES_CLIENT:.c=.o))
OBJ_SERVER = $(addprefix $(OBJDIR)/, $(SRC_FILES_SERVER:.c=.o))

LIBFT = $(LIBFT_DIR)/libft.a


NAME_CLIENT = client
NAME_SERVER = server

all: $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT): $(OBJ_CLIENT) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME_CLIENT) $(OBJ_CLIENT) $(LIBFT)

$(NAME_SERVER): $(OBJ_SERVER) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME_SERVER) $(OBJ_SERVER) $(LIBFT)

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -rf $(OBJDIR)
	$(MAKE) clean -C $(LIBFT_DIR)
	
fclean: clean
	rm -rf $(NAME_SERVER) $(NAME_CLIENT)
	$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean $(NAME)

.PHONY: all clean fclean re
