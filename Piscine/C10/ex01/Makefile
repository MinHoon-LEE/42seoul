SRCS = $(wildcard ./*.c)
TARGET	= ft_cat
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

all: ${TARGET}

${TARGET}: ob
	${CC} ${CFLAGS}$  -o ${TARGET} *.o

ob :
	${CC} ${CFLAGS} -c ./srcs/*.c

clean:
	${RM} ./*.o

fclean: clean
	rm ${TARGET}

re: fclean all

norm :
	norminette -R CheckForbiddenSourceHeader */*.[ch]
