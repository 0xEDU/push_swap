NAME = push_swap

CCFLAGS = -Wall -Wextra -Werror

SRCS_PATH = ./sources
OBJS_PATH = ./objects
INCS_PATH = ./includes

SRCS = $(addprefix $(SRCS_PATH)/, main.c)
OBJS = $(SRCS:$(SRCS_PATH)/%.c=$(OBJS_PATH)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CCFLAGS) $(OBJS) -o $(NAME)

$(OBJS): $(SRCS)
	@mkdir -p $(OBJS_PATH)
	$(CC) $(CCFLAGS) -I$(INCS_PATH) -c $(SRCS) -o $(OBJS)

clean:
	rm -rf $(OBJS_PATH)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
