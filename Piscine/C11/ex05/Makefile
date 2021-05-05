SRCS = $(wildcard ./*.c)
OBJS	= ${SRCS:.c=.o}
TARGET	= do-op
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

all: ${TARGET}

${TARGET}: ob
	${CC} ${CFLAGS}$  -o ${TARGET} *.o

ob :
	${CC} ${CFLAGS} -c *.c

clean:
	${RM} ${OBJS}

fclean: clean
	rm ${TARGET}

re: fclean all

norm :
	norminette -R CheckForbiddenSourceHeader */*.[ch]
