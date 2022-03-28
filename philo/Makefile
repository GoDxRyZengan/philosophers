SRCS =	./srcs/main.c \
		./srcs/init_struct.c \
		./srcs/utils.c \

OBJS	= ${SRCS:.c=.o}

NAME	= philo

INC		= ./include/

CC		= gcc -Wall -Werror -Wextra -g

RM		= rm -f

all:		${NAME}

.c.o:
		${CC} -I${INC} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
		${CC} ${OBJS} -I${INC} -o${NAME} -D_REENTRANT -DLinux

clean:		
		${RM} ${OBJS}

fclean:		clean
		${RM} ${NAME}

re:		fclean all