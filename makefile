NAME = tinyshell

SRCS = main.c env.c test_utils.c error.c print.c ./builtin/export.c 

CFLAGS = -Wall -Wextra -Werror -lreadline

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