#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

char *gnl(int fd)
{
    static char buffer[40000];
    static int pos;
    static int r;
    char *line = malloc(1000000);
    int i = 0;

    if(!line || fd < 0 || BUFFER_SIZE <= 0)
        return NULL;
    while(1)
    {
        if(pos >= r)
        {
            r = read(fd, buffer, 40000);
            if(r <= 0)
                break;
            pos = 0;
        }
        line[i++] = buffer[pos++];
        if(line[i - 1] == '\n')
            break;
    }
    line[i] = '\0';
    if(i == 0)
    {
        free(line);
        return NULL;
    }
    return line;
}
int ft_strncmp(char *s1, char *s2, int len)
{
    if(!s1 || !s2)
        return 1;
    int i = 0;
    while(s1[i] && s2[i])
    {
        if(s1[i] == s2[i])
            i++;
        else 
            return s1 - s2;
    }
    return 0;
}

int main(int ac , char **av)
{
    char *line;
    if(ac != 2 || av[1] == NULL || av[1][1] == '\0')
        return 1;
    char *str = av[1];
    while ((line = gnl(0)) != NULL)
    {
        while(*line)
        {
            if(ft_strncmp(line, str, strlen(str)) == 0)
            {
                for(int i = 0; i < strlen(str); i++)
                    write(1,"*",1);
                line += strlen(str);
            }
            else 
                write(1,line++, 1);
        }
    }
    
}
