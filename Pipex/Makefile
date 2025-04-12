NAME = pipex

CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g3
INCLUDE = -I include

# Dossier source pour pipex
SRC_DIR = src
OBJ_DIR = obj

# Liste des fichiers sources et objets de pipex
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

# Dossier libft
LIBFT_DIR = Libft+
LIBFT_MAKEFILE = $(LIBFT_DIR)/Makefile

# Ajouter libft.a dans les fichiers à lier
LIBFT = $(LIBFT_DIR)/libft.a

# Règle principale qui compile pipex et la libft
all: libft $(NAME)

# Règle pour compiler la libft
libft:
	@$(MAKE) -C $(LIBFT_DIR) -s  # Appelle make dans le dossier Libft+ en mode silencieux
	@echo "\033[1;32mLibft compiled !\033[0m"

# Compilation de pipex avec la libft
$(NAME): $(OBJ_FILES) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJ_FILES) $(LIBFT) -o $(NAME)  # Lier la libft à pipex
	@echo "\033[1;32mPipex compiled !\033[0m"

# Compilation des fichiers sources en objets
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

# Nettoyage des fichiers objets
clean:
	@$(RM) -r $(OBJ_DIR)
	@echo "\033[1;33mObject files deleted !\033[0m"

# Nettoyage complet : objets et exécutable
fclean: clean
	@$(RM) $(NAME)
	@echo "\033[1;31m$(NAME) deleted !\033[0m"
	@$(MAKE) -C $(LIBFT_DIR) fclean -s

# Recompilation complète
re: fclean all

.PHONY: all clean fclean re libft
