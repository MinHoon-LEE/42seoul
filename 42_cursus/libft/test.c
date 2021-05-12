#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *c;
    char a[29] = "abc";
    char b[] = "b";
    c = strjoin(0,0);
    printf("%p",c);
    return 0;
}
