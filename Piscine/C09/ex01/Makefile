SRCS = srcs/ft_putchar.c \
	   srcs/ft_swap.c \
	   srcs/ft_putstr.c \
	   srcs/ft_strlen.c \
	   srcs/ft_strcmp.c 
OBJS	= ${SRCS:.c=.o}
INCS	= includes/ft.h
TARGET	= libft.a
LIBC	= ar rc
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

all: ${TARGET}

${TARGET}: ${OBJS}
	${LIBC} ${TARGET} ${INCS} ${OBJS}

${OBJS}: ${SRCS}
	${CC} ${CFLAGS} -I ${INCS} -c $< -o $@

clean:
	${RM} ${OBJS}

fclean: clean
	rm libft.a

re: fclean all

norm :
	norminette -R CheckForbiddenSourceHeader */*.[ch]
