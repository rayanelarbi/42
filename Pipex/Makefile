NAME = pipex

CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g3
INCLUDE = -I include

SRC_DIR = src
OBJ_DIR = obj

SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

all: $(NAME)

$(NAME): $(OBJ_FILES)
	@$(CC) $(CFLAGS) $(OBJ_FILES) -o $(NAME)
	@echo "\033[1;32mCompilation done !\033[0m"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	@$(RM) -r $(OBJ_DIR)
	@echo "\033[1;33mObject files deleted !\033[0m"

fclean: clean
	@$(RM) $(NAME)
	@echo "\033[1;31m$(NAME) deleted !\033[0m"

re: fclean all

.PHONY: all clean fclean re
