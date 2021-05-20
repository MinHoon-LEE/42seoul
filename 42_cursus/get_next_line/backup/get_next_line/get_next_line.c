#include "get_next_line.h"

int		check_newline(char *storage)
{
	int		n;

	n = 0;
	while (storage[n])
	{
		if (storage[n] == '\n')
			return (n);
		n++;
	}
	return (-1);
}

int     cut_line(char **storage, int index, char **line)
{
	char	*tmp;
	
	(*storage)[index] = '\0';
	*line = ft_strdup(*storage);
	if ((*storage)[index + 1] == '\0')
	{
		free(*storage);
		*storage = 0;
		return (1);
	}
	tmp = ft_strdup((*storage) + index + 1);
	free(*storage);
	*storage = tmp;
	return (1);
}

int     check_storage(char **storage, int read_size, char **line)
{
	int		index;

	if (read_size < 0)
		return (-1);
	if (*storage && ((index = check_newline(*storage)) >= 0))
		return (cut_line(storage, index, line));
	else if (*storage)
	{
		*line = *storage;
		*storage = 0;
		return (0);
	}
	*line = ft_strdup("");
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char *storage[OPEN_MAX];
	char		buf[BUFFER_SIZE + 1];
	int			read_size;
	int			index;

	if (fd < 0 || line == 0 || BUFFER_SIZE <= 0)
		return (-1);
	while ((read_size = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[read_size] = 0;
		storage[fd] = ft_strjoin(storage[fd], buf);
		if ((index = check_newline(storage[fd])) >= 0)
			return (cut_line(&storage[fd], index, line));
	}
	return (check_storage(&storage[fd], read_size, line));
}
