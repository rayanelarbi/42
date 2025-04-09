NAME = pipex
CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g3
INCLUDE = -I include

SRC_DIR = src
SRCS = $(SRC_DIR)/main.c \

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
