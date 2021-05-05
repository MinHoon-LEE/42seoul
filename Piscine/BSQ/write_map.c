#include "bsq.h"

void	write_map(void)
{
	char	buf[30];
	int		fd;
	int		m;

	fd = open("new_map", O_CREAT | O_TRUNC | O_WRONLY, 0600);
	while ((m = read(0, buf, sizeof(buf))) > 0)
		write(fd , buf, m);
	close(fd);
}
