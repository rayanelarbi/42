NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRC_DIR = src
SRCS = $(SRC_DIR)/main.c \
	# $(SRC_DIR)/utils.c \
	# $(SRC_DIR)/draw.c \
	# $(SRC_DIR)/map_parser.c \
	# $(SRC_DIR)/path_checker.c \
	# $(SRC_DIR)/game_utils.c \
	# $(SRC_DIR)/map_parser_utils.c \
	# $(SRC_DIR)/free.c

OBJS = $(SRCS:.c=.o)

LIBFT_DIR = Libft+
LIBFT = $(LIBFT_DIR)/libft.a

INCLUDES = -Iincludes -I$(LIBFT_DIR)/include -Iminilibx-linux

MLX_DIR = minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx_Linux.a

all: libft $(MLX_LIB) $(NAME)

# Compilation silencieuse de libft avec message personnalisé
libft:
	@$(MAKE) -C $(LIBFT_DIR) -s
	@echo "\033[1;32mLibft compiled !\033[0m"

$(MLX_LIB):
	@echo "\033[1;35mCompiling MiniLibX for Linux...\033[0m"
	@make -s -C $(MLX_DIR) > /dev/null 2>&1

$(NAME): $(OBJS) $(LIBFT_OBJS) $(MLX_LIB)
	@echo "\033[1;38;5;214mLinking executable...\033[0m"
	@$(CC) $(CFLAGS) $^ -L$(MLX_DIR) -lmlx_Linux -lbsd -lX11 -lXext -o $(NAME)
	@echo "\033[1;32m$(NAME) compiled !\033[0m"

clean:
	@$(RM) $(OBJS)
	@make -s clean -C $(MLX_DIR) > /dev/null 2>&1
	@$(MAKE) -C $(LIBFT_DIR) clean -s
	@echo "\033[1;33mObject files deleted !\033[0m"

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(MLX_LIB)
	@echo "\033[1;31mLibft, so_long and MLX deleted !\033[0m"
	@$(MAKE) -C $(LIBFT_DIR) fclean -s

re: fclean all

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

.PHONY: all clean fclean re libft
