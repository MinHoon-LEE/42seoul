#include <libft.h>

void *ft_memset(void * ptr, int value, size_t num)
{
	int		n;

	n = -1;
	while (++n < num)
		*(unsigned char*)(ptr + n) = value;
	return ptr;
}
