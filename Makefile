NAME = push_swap

CCFLAGS = -Wall -Wextra -Werror -g3

SRCS_PATH = ./sources
OPERATIONS_PATH = ./sources/operations
OBJS_PATH = .
INCS_PATH = ./includes

LIBFT = ./libft/libft.a

SRCS = $(addprefix $(SRCS_PATH)/, main.c \
	   argv_to_stack.c \
	   list_utils.c    \
	   sort.c          \
	   sort_threes.c   \
	   validate_input.c)

OPERATIONS_SRCS = $(addprefix $(OPERATIONS_PATH)/, swap.c \
				  push.c           \
				  reverse_rotate.c \
				  rotate.c)

OBJS = $(patsubst $(SRCS_PATH)/%.c, $(OBJS_PATH)/%.o, $(SRCS))
OPERATIONS_OBJS = $(patsubst $(OPERATIONS_PATH)/%.c, $(OBJS_PATH)/%.o, $(OPERATIONS_SRCS))

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

$(LIBFT):
	@echo -e "CREATING LIBFT"
	@make --no-print-directory -C libft

clean:
	@echo -e "REMOVING OBJS..."
	@make --no-print-directory -C libft clean
	@rm -rf $(OBJS) $(OPERATIONS_OBJS)

fclean: clean
	@echo -e "FULL CLEAN"
	@make --no-print-directory -C libft fclean
	@rm -rf $(NAME)

re: fclean all

incendio: fclean
	git add .
	git commit -m "Emergency commit"
	git push

.PHONY: all clean fclean re incendio
