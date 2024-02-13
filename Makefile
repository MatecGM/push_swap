CC = cc

#FLAGS = -Wall -Wextra -Werror

NAME = push_swap

SRCS = main.c \
		parsing.c \
		instruction.c \
		stack/ft_stacknew.c \
		stack/ft_stackpush.c \
		stack/ft_stackrev_rotate.c \
		stack/ft_stackrotate.c \
		stack/ft_stackswap.c \
		stack/ft_stackadd_back.c \
		stack/ft_stacklen.c \
		ft_presort.c \
		stock.c \

OBJS = $(SRCS:.c=.o)

LIBFT = libft/libft.a

all : $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(FLAGS) -g  $(OBJS) -o $(NAME) $(LIBFT) -lSDL2

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