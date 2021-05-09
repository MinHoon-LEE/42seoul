#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*ptr;

	i  = 0;
	ptr = malloc(sizeof(char) * (len + 1));
	if (ptr == 0 || s == 0)
		return (0);
	if (start >= ft_strlen(s))
	{
		ptr[0] = 0;
		return (ptr);
	}
	while (i < len && *(s + i + (size_t)start) != 0)
	{
		*(ptr + i) = *(char *)(s + (size_t)start + i);
		i++;
	}
	*(ptr + i) = 0;
	return (ptr);
}

