#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int		g_fd;

int		g_line_zero;

char    **insert(int line, int row, char *arr);

char    **map(char *arr);

void    write_map(void);

int     **make_c_map(char **map, char obs, int line, int row);

int     find_min(int n1, int n2, int n3);

void    make_max(int **c, int line, int row);

int     find_max_index(int **c_map, int *n);

void    free_cmap(int **cmap, int line);

void    fill_map(char **m, int **cm, int n[], char f_c);

void    ft_strcpy(char *s1, char *s2);

void    write_map(void);

char    g_buf[100];
