NAME = push_swap

CCFLAGS = -Wall -Wextra -Werror

SRCS_PATH = ./sources
OBJS_PATH = .
INCS_PATH = ./includes

LIBFT = ./libft/libft.a

SRCS = $(addprefix $(SRCS_PATH)/, main.c \
	   validate_input.c)

OBJS = $(patsubst $(SRCS_PATH)/%.c, $(OBJS_PATH)/%.o, $(SRCS))

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) Makefile
	@$(CC) $(CCFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo -e "PUSH_SWAP CREATED!!"

$(OBJS): $(SRCS)
	@echo -e "COMPILING PUSH_SWAP OBJS..."
	@mkdir -p $(OBJS_PATH)
	@$(CC) $(CCFLAGS) -I$(INCS_PATH) -c $(SRCS)

$(LIBFT):
	@echo -e "CREATING LIBFT"
	@make --no-print-directory -C libft

clean:
	@echo -e "REMOVING OBJS..."
	@rm -rf $(OBJS)

fclean: clean
	@echo -e "FULL CLEAN"
	@make --no-print-directory -C libft fclean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
