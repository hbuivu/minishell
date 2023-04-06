NAME = tinyshell

SRCS = main.c env_var.c utils.c testers.c \
	builtin/builtin.c builtin/cd.c builtin/echo.c builtin/env.c builtin/export.c builtin/pwd.c builtin/unset.c

# CFLAGS = -Wall -Wextra -Werror -lreadline
CFLAGS = -I. -g -fsanitize=address -Wall -Wextra

CC = cc

LIBFT_DIR = ./libft

LIBS = ./libft/libft.a 

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(OBJS) $(LIBS) $(CFLAGS) -o $(NAME)

all: $(NAME)

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	rm -rf *.o

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re