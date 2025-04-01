NAME = push_swap
CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g3
INCLUDE = -I include

SRC_DIR = src
SRCS = $(SRC_DIR)/ft_split.c \
       $(SRC_DIR)/init_stack_a.c \
       $(SRC_DIR)/parsing.c \
       $(SRC_DIR)/main.c \
       $(SRC_DIR)/push.c \
       $(SRC_DIR)/reverse_rotate.c \
       $(SRC_DIR)/rotate.c \
       $(SRC_DIR)/swap.c \
       $(SRC_DIR)/utils.c \
	   $(SRC_DIR)/turk_algorithm.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "\033[1;32mCompilation done !\033[0m"

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	@$(RM) $(OBJS)
	@echo "\033[1;33mObject files deleted !\033[0m"

fclean: clean
	@$(RM) $(NAME)
	@echo "\033[1;31m$(NAME) deleted !\033[0m"

re: fclean all

.PHONY: all clean fclean re
