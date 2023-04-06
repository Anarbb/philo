NAME        := philo
CC        := cc
FLAGS    := -Wall -Wextra -Werror -I inc

SRCS        :=      main.c \
					src/init.c \
					src/routine.c \
					src/utils/custom.c \
					src/utils/rout_utils.o \
					src/utils/ft_atoi.c \
					src/utils/ft_calloc.c \
                          
OBJS        := $(SRCS:.c=.o)

%.o: %.c inc/philo.h
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}


CLR_RMV		:= \033[0m
RED		    := \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
CYAN 		:= \033[1;36m
RM		    := rm -f

all:		${NAME}

${NAME}:	${OBJS}
			@ ${CC} ${FLAGS} ${OBJS} -o ${NAME}
			@ echo "$(GREEN)$(NAME) $(CYAN)compiled ✔️"

clean:
			@ ${RM} *.o */*.o */*/*.o
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"

fclean:		clean
			@ ${RM} ${NAME}
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"

re:			fclean all

.PHONY:		all clean fclean re