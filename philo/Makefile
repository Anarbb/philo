NAME	:=	philo

CC		:=	cc

CFLAGS	:=	-Wall -Wextra -Werror -I inc

SRCS	:=	main.c \
				srcs/utils/ft_calloc.c \
				srcs/utils/ft_atoi.c \
				srcs/actions/eat.c \
				srcs/utils/get_time.c \

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

OBJS	:=	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re