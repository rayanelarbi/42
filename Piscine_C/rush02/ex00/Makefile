TARGET = rush-02
SRCDIR = srcs
INCDIR = includes

CC = cc
CFLAGS = -Wall -Werror -Wextra -I $(INCDIR)

SOURCES = $(SRCDIR)/main.c \
           $(SRCDIR)/utils.c \
           $(SRCDIR)/parsing.c \
           $(SRCDIR)/conversion.c

OBJECTS = $(SOURCES:%.c=%.o)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@

all: $(TARGET)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re

