NAME = pipex
BONUS_NAME = pipex_bonus

CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g3
INCLUDE = -I include

# Dossier source pour pipex
SRC_DIR = src
OBJ_DIR = obj

# Fichiers sources classiques et objets
SRC_FILES = $(SRC_DIR)/pipex.c $(SRC_DIR)/utils.c
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

# Fichiers sources bonus et objets bonus
SRC_BONUS_FILES = $(SRC_DIR)/pipex_bonus.c $(SRC_DIR)/utils_bonus.c
OBJ_BONUS_FILES = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_BONUS_FILES))

# Dossier libft
LIBFT_DIR = Libft+
LIBFT_MAKEFILE = $(LIBFT_DIR)/Makefile
LIBFT = $(LIBFT_DIR)/libft.a

# Règle principale
all: libft $(NAME)

# Compilation de la libft
libft:
	@$(MAKE) -C $(LIBFT_DIR) -s
	@echo "\033[1;32mLibft compiled !\033[0m"

# Compilation de pipex
$(NAME): $(OBJ_FILES) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJ_FILES) $(LIBFT) -o $(NAME)
	@echo "\033[1;32mPipex compiled !\033[0m"

# Compilation bonus
bonus: libft $(BONUS_NAME)

$(BONUS_NAME): $(OBJ_BONUS_FILES) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJ_BONUS_FILES) $(LIBFT) -o $(BONUS_NAME)
	@echo "\033[1;32mPipex compiled !\033[0m"

# Compilation des fichiers objets
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

# Nettoyage des fichiers objets
clean:
	@$(RM) -r $(OBJ_DIR)
	@echo "\033[1;33mObject files deleted !\033[0m"

# Nettoyage complet
fclean: clean
	@$(RM) $(NAME) $(BONUS_NAME)
	@echo "\033[1;31m$(NAME) deleted !\033[0m"
	@$(MAKE) -C $(LIBFT_DIR) fclean -s

# Recompilation complète
re: fclean all

.PHONY: all clean fclean re libft bonus
