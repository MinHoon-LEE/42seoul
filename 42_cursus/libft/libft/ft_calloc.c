#include "libft.h"

void	*ft_calloc(size_t count,size_t size)
{
	void	*ptr;
	size_t	n;

	n = 0;
	ptr = malloc(count * size);
	if (ptr == 0)
		return (0);
	ft_bzero(ptr,count *size);
	return ptr;
}
