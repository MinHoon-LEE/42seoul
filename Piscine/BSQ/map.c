#include "bsq.h"
#include <unistd.h>
#include <stdio.h>

int		ft_map_line(char *arr, int fd)
{
	int		line;
	int		count; 
	int		curr_count;
	int		m;
	int		n;

	curr_count = 0;
	count = 0;
	line = 0;
	while ((n =  read(fd, g_buf, sizeof(g_buf))) > 0)
	{
		m = -1;
		while (++m < n)
		{  
			curr_count++;
			if (g_buf[m] == '\n')
			{
				if (line >= 2 && curr_count != count)
					return (-1);
				curr_count = 0;
				line++;
			}
			if (line == 1)
				count++;
			if (line == 0)
				g_line_zero++;
		}
	}
	close(fd);
	return (line -1);
}

int		ft_map_row(char *arr, int fd)
{
	int     line;
    int     count; 
    int     m;  
    int     n;  

    count = 0;
    line = 0;
	g_fd = open(arr, O_RDONLY);
    while ((n =  read(g_fd, g_buf, sizeof(g_buf))) > 0)
    {   
        m = -1; 
        while (++m < n)
        {   
			if (line == 0 )
            if (g_buf[m] == '\n')
                line++;
            if (line == 1)
                count++;
			if (line > 1)
			{
				close(fd);
				return (count - 1);
			}
        }   
    }   
    close(g_fd);
	return (count - 1);
}

void	put_map(char **ptr, int line, int row, char *arr)
{
	int		n;
	int		m;
	int		i;
	int		j;

	n = 0;
	m = 0;
	while (n < line)
	{
		ptr[n][row] = '\0';
		n++;
	}
	ptr[n] = 0;
	i = 0;
	j = 0;
	g_fd = open(arr, O_RDONLY);
	while ((n =  read(g_fd, g_buf, 1)) > 0)
	{
		if (g_buf[0] == '\n')
			break ;
	}
	while ((n =  read(g_fd, g_buf, sizeof(g_buf))) > 0)
	{
		m = -1;
		while (++m < n)
		{
			ptr[i][j] = g_buf[m];
			j++;
			if (j == row)
			{
				i++;
				j = 0;
			}
		}
	}
	close(g_fd);
}

char	**insert(int line, int row, char *arr)
{
	int		n;
	char	**ptr; 

	n = 0;
	ptr = (char **)malloc(sizeof(char *) * line + 2);
	while (n < line + 2)
	{
		ptr[n] = (char *)malloc(sizeof(char) * row + 1);
		n++;
	}
	put_map(ptr, line, row + 1, arr);
	int i = 0;
	int j = 0;
	while (ptr[i] != 0)
	{
		j = 0;
		while (ptr[i][j] != 0)
		{
			write(1, &ptr[i][j], 1);
			j++;
		}
		i++;
	}
	return (ptr);
}

char	**map(char *arr)
{
	int		line;
	int		row;
	
	g_fd = open(arr, O_RDONLY);
	if (g_fd == -1)
		write(1, "map error\n", 10);
	else
	{
		if ((line = ft_map_line(arr, g_fd)) != -1)
		{
			return (insert(line, ft_map_row(arr, g_fd), arr));
		}
		write(1, "map error\n", 10);
	}
	return (NULL);
}
