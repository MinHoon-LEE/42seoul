find . -name "*.c" -exec gcc -Wall -Werror -Wextra -c {} \;
ar crv libft.a *.o
