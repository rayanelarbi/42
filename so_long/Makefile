NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRCS = main.c \
       src/utils.c src/draw.c \
       src/map_parser.c src/path_checker.c \
       src/game_utils.c src/map_parser_utils.c \
       src/free.c

LIBFT = libft/ft_atoi.c libft/ft_bzero.c libft/ft_calloc.c \
        libft/ft_isalnum.c libft/ft_isalpha.c libft/ft_isascii.c \
        libft/ft_isdigit.c libft/ft_isprint.c libft/ft_itoa.c \
        libft/ft_memchr.c libft/ft_memcmp.c libft/ft_memcpy.c \
        libft/ft_memmove.c libft/ft_memset.c libft/ft_putchar_fd.c \
        libft/ft_putendl_fd.c libft/ft_putnbr_fd.c libft/ft_putstr_fd.c \
        libft/ft_split.c libft/ft_strchr.c libft/ft_strdup.c \
        libft/ft_striteri.c libft/ft_strjoin.c libft/ft_strlcat.c \
        libft/ft_strlcpy.c libft/ft_strlen.c libft/ft_strmapi.c \
        libft/ft_strncmp.c libft/ft_strnstr.c libft/ft_strrchr.c \
        libft/ft_strtrim.c libft/ft_substr.c libft/ft_tolower.c \
        libft/ft_toupper.c gnl/get_next_line_bonus.c \
        printf/ft_printf.c printf/ft_utils.c printf/ft_utils_2.c

OBJS = $(SRCS:.c=.o)
LIBFT_OBJ = $(LIBFT:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_OBJ)
	@echo "🔗 Linking executable..."
	$(CC) $(CFLAGS) $^ -Lminilibx-linux -lmlx -lX11 -lXext -lm -o $(NAME)


clean:
	$(RM) $(OBJS) $(LIBFT_OBJ)

fclean: clean
	make clean -C minilibx-linux/
	$(RM) $(NAME)

re: fclean all

%.o: %.c
	$(CC) $(CFLAGS) -Iminilibx-linux -Iincludes -c $< -o $@
