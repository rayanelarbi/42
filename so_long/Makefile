NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRCS = $(addprefix src/,
       main.c
       utils.c draw.c
       map_parser.c
       path_checker.c
       game_utils.c
       map_parser_utils.c
       free.c)

LIBFT = $(addprefix libft/,
ft_atoi.c
ft_bzero.c
ft_calloc.c
ft_isalnum.c
ft_isalpha.c
ft_isascii.c
ft_isdigit.c
ft_isprint.c
ft_itoa.c
ft_memchr.c
ft_memcmp.c
ft_memcpy.c
ft_memmove.c
ft_memset.c
ft_putchar_fd.c
ft_putendl_fd.c
ft_putnbr_fd.c
ft_putstr_fd.c
ft_split.c
ft_strchr.c
ft_strdup.c
ft_striteri.c
ft_strjoin.c
ft_strlcat.c
ft_strlcpy.c
ft_strlen.c
ft_strmapi.c
ft_strncmp.c
ft_strnstr.c
ft_strrchr.c
ft_strtrim.c
ft_substr.c
ft_tolower.c
ft_toupper.c
gnl/get_next_line_bonus.c \
printf/ft_printf.c \
printf/ft_utils.c \
printf/ft_utils_2.c)

OBJS = $(SRCS:.c=.o)
LIBFT_OBJ = $(LIBFT:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_OBJ)
	$(CC) $(CFLAGS) $^ -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	$(RM) $(OBJS) $(LIBFT_OBJ)

fclean: clean
	make clean -C mlx/
	$(RM) $(NAME)

re: fclean all

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -Iincludes -c $< -o $@
