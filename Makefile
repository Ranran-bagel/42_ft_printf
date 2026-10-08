NAME = libftprintf.a
SRCS = ft_printf.c ft_putchar.c ft_putnbr.c ft_putaddr.c
OBJS = $(SRCS:.c=.o)
HEADER = ft_printf.h
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	ar	rcs	$(NAME)	$(OBJS)

%.o: %.c $(HEADER)
	$(CC)	$(CFLAGS)	-c	$<	-o	$@

clean:
	rm	-f	$(OBJS)

fclean:
	rm	-f	$(NAME)	$(OBJS)

re: fclean all

.PHONY: all clean fclean re