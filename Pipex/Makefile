NAME = pipex

CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g3
INCLUDE = -I include

SRC_DIRS = src printf
OBJ_DIR = obj

SRC_FILES = $(foreach dir, $(SRC_DIRS), $(wildcard $(dir)/*.c))
OBJ_FILES = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

# Create obj/ with subdirs if needed
DIRS_TO_MAKE = $(sort $(dir $(OBJ_FILES)))

all: $(NAME)

$(NAME): $(OBJ_FILES)
	@$(CC) $(CFLAGS) $(OBJ_FILES) -o $(NAME)
	@echo "\033[1;32mCompilation done !\033[0m"

# Compile .c into obj/ keeping folder structure
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	@$(RM) -r $(OBJ_DIR)
	@echo "\033[1;33mObject files deleted !\033[0m"

fclean: clean
	@$(RM) $(NAME)
	@echo "\033[1;31m$(NAME) deleted !\033[0m"

re: fclean all

.PHONY: all clean fclean re
