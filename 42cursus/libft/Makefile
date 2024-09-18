NAME = libft.a
SRCS = $(wildcard *.c)
# SRCSB = $(wildcard *.o)
OBJS = ${SRCS:.c=.o}
# OBJSB = ${SRCSB:.c=.o}
CC = cc
CFLAGS = -Wall -Wextra -Werror
SLIB = ar -rcs
RM = rm -f

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	${SLIB} ${NAME} ${OBJS}

all: ${NAME}

# bonus: ${NAME} ${OBJSB}
# 	${SLIB} ${NAME} ${OBJSB}
clean:
	${RM} ${OBJS} ${OBJSB}

fclean: clean
	${RM} ${NAME} ${bonus} 

re: fclean all

.PHONY : all bonus clean fclean re