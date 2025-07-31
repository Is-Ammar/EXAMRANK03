#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n;
int size;
int *res;

void print()
{
    int i = 0;
    for (i = 0; i < size -1; i++)
    {
        printf("%d ",res[i]);
    }
    printf("%d\n", res[i]);
}

int valid(int x)
{
    for(int y = 0; y < size ;y++)
    {
        if(res[y] == x || res[y] - x == size -y || res[y] - x == y -size)
            return 0;
    }
    return 1;
}

void queen(void)
{
    if(size == n)
        print();
    for(int x = 0; x < n ; x++)
    {
        if(valid(x))
        {
            res[size++] = x;
            queen();
            size--;
        }
    }
}

int main(int ac , char **av)
{
    if(ac != 2)
        return 1;
    n = atoi(av[1]);
    int tmp[n];
    res = tmp;
    queen();
}
