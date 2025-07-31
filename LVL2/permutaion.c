#include <unistd.h>
#include <stdio.h>
#include <string.h>

void swap(char *a, char *b)
{
    char tmp = *a;
    *a = *b;
    *b = tmp;
}
char *sort(char *str)
{
    int i = 0;
    int j ;
    while(str[i])
    {
        j = i + 1;
        while(str[j])
        {
            if(str[i] > str[j])
            {
                swap(&str[i], &str[j]);
            }
            j++;
        }
        i++;
    }
    return str;
}

void permut(char *str, int start, int end)
{
    if(start == end)
    {
        puts(str);
        return;
    }
    for (int i = start; i <= end; i++)
    {
        sort(str + start);
        swap(&str[start], &str[i]);
        sort(str + start + 1);
        permut(str, start + 1, end);
        swap(&str[start], &str[i]);
    }
}


int main(int ac , char **av)
{
    char *str = sort(av[1]);
    permut(str, 0 , strlen(str) - 1);
    return 0;
}
