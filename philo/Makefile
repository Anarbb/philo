NAME        := philo
CC        := gcc
FLAGS    := -Wall -Wextra -Werror -I inc
################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

SRCS        :=      main.c \
					src/init.c \
					src/routine.c \
					src/utils/custom.c \
					src/utils/rout_utils.o \
                          
OBJS        := $(SRCS:.c=.o)

%.o: %.c
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

################################################################################
#                                  Makefile  objs                              #
################################################################################


CLR_RMV		:= \033[0m
RED		    := \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
CYAN 		:= \033[1;36m
RM		    := rm -f

${NAME}:	${OBJS}
			@ ${CC} ${FLAGS} ${OBJS} -o ${NAME}
			@ echo "$(GREEN)$(NAME) $(CYAN)compiled ✔️"

all:		${NAME}


clean:
			@ ${RM} *.o */*.o */*/*.o
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"

fclean:		clean
			@ ${RM} ${NAME}
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"

re:			fclean all

################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

SRCS        :=      main.c \
                          
OBJS        := $(SRCS:.c=.o)

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}
