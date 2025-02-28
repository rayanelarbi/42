NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRCS = main.c \
    #    src/utils.c src/draw.c \
    #    src/map_parser.c src/path_checker.c \
    #    src/game_utils.c src/map_parser_utils.c \
    #    src/free.c

LIBFT_DIR = Libft+
LIBFT_SRCS = $(LIBFT_DIR)/src/ft_atoi.c $(LIBFT_DIR)/src/ft_bzero.c $(LIBFT_DIR)/src/ft_calloc.c \
             $(LIBFT_DIR)/src/ft_isalnum.c $(LIBFT_DIR)/src/ft_isalpha.c $(LIBFT_DIR)/src/ft_isascii.c \
             $(LIBFT_DIR)/src/ft_isdigit.c $(LIBFT_DIR)/src/ft_isprint.c $(LIBFT_DIR)/src/ft_itoa.c \
             $(LIBFT_DIR)/src/ft_memchr.c $(LIBFT_DIR)/src/ft_memcmp.c $(LIBFT_DIR)/src/ft_memcpy.c \
             $(LIBFT_DIR)/src/ft_memmove.c $(LIBFT_DIR)/src/ft_memset.c $(LIBFT_DIR)/src/ft_putchar_fd.c \
             $(LIBFT_DIR)/src/ft_putendl_fd.c $(LIBFT_DIR)/src/ft_putnbr_fd.c $(LIBFT_DIR)/src/ft_putstr_fd.c \
             $(LIBFT_DIR)/src/ft_split.c $(LIBFT_DIR)/src/ft_strchr.c $(LIBFT_DIR)/src/ft_strdup.c \
             $(LIBFT_DIR)/src/ft_striteri.c $(LIBFT_DIR)/src/ft_strjoin.c $(LIBFT_DIR)/src/ft_strlcat.c \
             $(LIBFT_DIR)/src/ft_strlcpy.c $(LIBFT_DIR)/src/ft_strlen.c $(LIBFT_DIR)/src/ft_strmapi.c \
             $(LIBFT_DIR)/src/ft_strncmp.c $(LIBFT_DIR)/src/ft_strnstr.c $(LIBFT_DIR)/src/ft_strrchr.c \
             $(LIBFT_DIR)/src/ft_strtrim.c $(LIBFT_DIR)/src/ft_substr.c $(LIBFT_DIR)/src/ft_tolower.c \
             $(LIBFT_DIR)/src/ft_toupper.c $(LIBFT_DIR)/gnl/get_next_line_bonus.c \
             $(LIBFT_DIR)/printf/ft_printf.c $(LIBFT_DIR)/printf/ft_utils.c $(LIBFT_DIR)/printf/ft_utils_2.c

OBJS = $(SRCS:.c=.o)
LIBFT_OBJS = $(LIBFT_SRCS:.c=.o)

INCLUDES = -Iincludes -I$(LIBFT_DIR)/include -Iminilibx_opengl

MLX_DIR = minilibx_opengl
MLX_LIB = $(MLX_DIR)/libmlx.a

all: $(MLX_LIB) $(NAME)

$(MLX_LIB):
	@echo "🔧 Compiling MiniLibX..."
	@make -C $(MLX_DIR)

$(NAME): $(OBJS) $(LIBFT_OBJS) $(MLX_LIB)
	@echo "🔗 Linking executable..."
	$(CC) $(CFLAGS) $^ -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	$(RM) $(OBJS) $(LIBFT_OBJS)
	@make clean -C $(MLX_DIR)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(MLX_LIB) # Supprime libmlx.a manuellement
	@make clean -C $(MLX_DIR) # Remplace fclean par clean

re: fclean all

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
