CC = cc

#FLAGS = -Wall -Wextra -Werror

NAME = push_swap

SRCS = intruction01.c \
		intruction02.c \
		stack.c \

OBJS = $(SRCS:.c=.o)

LIBFT = libft/libft.a

all : $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(FLAGS) -g  $(OBJS) -o $(NAME) $(LIBFT) -lSDL2 -lm

$(LIBFT):
	make -C libft -j

.c.o:
	$(CC) $(FLAGS) -g $(FLAGS) -I/usr/include -I./libft -O3 -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re