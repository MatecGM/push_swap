NAME = push_swap
NAME_BONUS = checker

CC = cc
FLAGS = -Wall -Wextra -Werror
SRC_DIR = src
OBJ_DIR = obj
BONUS_DIR = bonus

SRC = 	main.c \
		parsing.c \
		instruction.c \
		stack/ft_stacknew.c \
		stack/ft_stackpush.c \
		stack/ft_stackrev_rotate.c \
		stack/ft_stackrotate.c \
		stack/ft_stackswap.c \
		stack/ft_stackadd_back.c \
		stack/ft_stacklen.c \
		stack/ft_stackclear.c \
		ft_presort.c \
		stock.c \
		insertion.c \
		count_cost.c \
		lilsort.c \
		ft_strisint.c

BONUS_SRC = stack/ft_stackadd_back_bonus.c \
		stack/ft_stackclear_bonus.c \
		stack/ft_stacklen_bonus.c \
		stack/ft_stacknew_bonus.c \
		stack/ft_stackpush_bonus.c \
		stack/ft_stackrev_rotate_bonus.c \
		stack/ft_stackrotate_bonus.c \
		stack/ft_stackswap_bonus.c \
		instruction_bonus.c \
		main_bonus.c

OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

BONUS_OBJ = $(BONUS_SRC:%.c=$(OBJ_DIR)/%.o)

RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[1;33m
PURPLE = \033[0;35m
NC = \033[0m

LIBFT = libft/libft.a

all : $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME) $(LIBFT)
	@echo "$(GREEN)$(NAME) compilation successful !$(NC)"

bonus : $(NAME_BONUS)

$(NAME_BONUS): $(LIBFT) $(BONUS_OBJ)
	@$(CC) $(FLAGS) $(BONUS_OBJ) -o $(NAME_BONUS) $(LIBFT)
	@echo "$(GREEN)$(NAME_BONUS) compilation successful !$(NC)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@echo "$(YELLOW)Compiling $(notdir $<)...$(NC)"
	@$(CC) $(FLAGS) -I include -I libft -o $@ -c $<

$(OBJ_DIR)/%.o: $(BONUS_DIR)/%.c 
	@mkdir -p $(@D)
	@echo "$(YELLOW)Compiling $(notdir $<)...$(NC)"
	@$(CC) $(FLAGS) -I include -I libft -o $@ -c $<

$(LIBFT):
	@echo "$(PURPLE)Compiling LIBFT...$(NC)"
	@make -C libft -j -s

clean:
	@echo "$(RED)Removing object...$(NC)"
	@rm -rf $(OBJ_DIR)
	@echo "$(RED)Removing libft...$(NC)"
	@make -C libft clean -s

fclean: clean
	@echo "$(RED)Removing $(NAME)...$(NC)"
	@rm -f $(NAME)
	@make -C libft fclean -s

re: fclean all

.PHONY: all clean fclean re bonus