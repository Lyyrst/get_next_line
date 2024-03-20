NAME = gnl

HEADERS = include/get_next_line.h

CFILES = src/main.c \
			src/get_next_line.c \
			src/get_next_line_utils.c

OFILES = $(CFILES:.c=.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c -o $@ $<

all : $(NAME)

$(NAME) : $(OFILES)
	$(CC) $(OFILES) -o $(NAME)

clean :
	rm -rf $(OFILES)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY :
	all clean fclean re
