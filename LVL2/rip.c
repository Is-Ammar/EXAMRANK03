#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int min;
char *av;


int correct(char *str)
{
    int op = 0;
    int cls = 0;
    int i = 0;
    while(str[i])
    {
        if(str[i] == '(')
            op++;
        else if (str[i] == ')')
        {
            if(op)
                op--;
            else 
                cls++;
        }
        i++;
    }
    return op + cls;
}

void rip(int r, int index)
{
    if(r == min && !correct(av))
    {
        puts(av);
    }
    for (int i = index; av[i]; i++)
    {
        if(av[i] == '(' || av[i] == ')')
        {
            char c = av[i];
            av[i] = '_';
            rip(r + 1, i + 1);
            av[i] = c;
        }
    }
}

int main(int ac , char **arv)
{
    if(ac != 2)
        return 1;
    av = arv[1];
    min = correct(av);
    rip(0,0);
}
