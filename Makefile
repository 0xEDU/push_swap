NAME = push_swap
BONUS_NAME = checker

CCFLAGS = -Wall -Wextra -Werror -g3

SRCS_PATH = ./sources
OPERATIONS_PATH = ./sources/operations
OBJS_PATH = .
INCS_PATH = ./includes

BONUS_PATH = ./bonus
BONUS_OPERATIONS_PATH = ./bonus/operations
BONUS_INCLUDES = ./bonus/includes

LIBFT = ./libft/libft.a

SRCS = $(addprefix $(SRCS_PATH)/, main.c \
	   arrange.c          \
	   argv_to_stack.c    \
	   calculate_moves.c  \
	   calculate_target.c \
	   execute.c          \
	   instructions.c     \
	   list_utils.c       \
	   sort.c             \
	   sort_big.c         \
	   sort_threes.c      \
	   validate_input.c)

OPERATIONS_SRCS = $(addprefix $(OPERATIONS_PATH)/, swap.c \
				  push.c           \
				  reverse_rotate.c \
				  rotate.c)

BONUS_SRCS = $(addprefix $(BONUS_PATH)/, main_bonus.c \
			 apply_move_from_stdin.c \
			 argv_to_stack_bonus.c   \
			 list_utils_bonus.c      \
			 validate_input_bonus.c)

BONUS_OPERATIONS_SRCS = $(addprefix $(BONUS_OPERATIONS_PATH)/, swap_bonus.c \
				  push_bonus.c           \
				  reverse_rotate_bonus.c \
				  rotate_bonus.c)

OBJS = $(patsubst $(SRCS_PATH)/%.c, $(OBJS_PATH)/%.o, $(SRCS))
OPERATIONS_OBJS = $(patsubst $(OPERATIONS_PATH)/%.c, $(OBJS_PATH)/%.o, $(OPERATIONS_SRCS))

BONUS_OBJS = $(patsubst $(BONUS_PATH)/%.c, $(OBJS_PATH)/%.o, $(BONUS_SRCS))
BONUS_OPERATIONS_OBJS = $(patsubst $(BONUS_OPERATIONS_PATH)/%.c, $(OBJS_PATH)/%.o, $(BONUS_OPERATIONS_SRCS))

all: $(NAME)

$(NAME): $(OBJS) $(OPERATIONS_OBJS) $(LIBFT) Makefile
	@$(CC) $(CCFLAGS) $(OBJS) $(OPERATIONS_OBJS) $(LIBFT) -o $(NAME)
	@echo -e "PUSH_SWAP CREATED!!"

$(OBJS): $(SRCS)
	@echo -e "COMPILING PUSH_SWAP OBJS..."
	@$(CC) $(CCFLAGS) -I$(INCS_PATH) -c $(SRCS)

$(OPERATIONS_OBJS): $(OPERATIONS_SRCS)
	@echo -e "COMPILING PUSH_SWAP OPERATIONS OBJS..."
	@$(CC) $(CCFLAGS) -I$(INCS_PATH) -c $(OPERATIONS_SRCS)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS) $(BONUS_OPERATIONS_OBJS) $(LIBFT)
	@$(CC) $(CCFLAGS) $(BONUS_OBJS) $(BONUS_OPERATIONS_OBJS) $(LIBFT) -o $(BONUS_NAME)
	@echo -e "BONUS CREATED!!"

$(BONUS_OBJS): $(BONUS_SRCS)
	@echo -e "COMPILING BONUS OBJS..."
	@$(CC) $(CCFLAGS) -I$(BONUS_INCLUDES) -c $(BONUS_SRCS)

$(BONUS_OPERATIONS_OBJS): $(BONUS_OPERATIONS_SRCS)
	@echo -e "COMPILING PUSH_SWAP BONUS OPERATIONS OBJS..."
	@$(CC) $(CCFLAGS) -I$(BONUS_INCLUDES) -c $(BONUS_OPERATIONS_SRCS)

$(LIBFT):
	@echo -e "CREATING LIBFT"
	@make --no-print-directory -C libft

clean:
	@echo -e "REMOVING OBJS..."
	@make --no-print-directory -C libft clean
	@rm -rf $(OBJS) $(OPERATIONS_OBJS) $(BONUS_OBJS) $(BONUS_OPERATIONS_OBJS)

fclean: clean
	@echo -e "FULL CLEAN"
	@make --no-print-directory -C libft fclean
	@rm -rf $(NAME) $(BONUS_NAME)

re: fclean all

incendio: fclean
	git add .
	git commit -m "Emergency commit"
	git push

.PHONY: all clean fclean re incendio
