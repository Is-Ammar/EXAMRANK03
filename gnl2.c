#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 42

char *gnl(int fd)
{
    static int pos;
    static int r;
    static char buffer[BUFFER_SIZE];
    char *line = malloc(100000);
    int i =0;

    if(!line || fd < 0 || BUFFER_SIZE <= 0)
        return NULL;
    while(1)
    {
        if(pos >= r)
        {
            r = read(fd, buffer, BUFFER_SIZE);
            pos = 0;
            if(r <= 0)
                break;
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