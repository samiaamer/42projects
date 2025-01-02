#include "get_next_line.h"

int main(void)
{
    int fd1 = open("text.txt", O_RDONLY);
    int fd2 = open("test2.txt", O_RDONLY);
    char *line;

    if (fd1 == -1 || fd2 == -1) {
        printf("%s\n","Error opening file");
        return (1);
    }
    while (1)
    {
        line = get_next_line(fd1);
        if (line)
        {
             printf("this is file1: %s", line);
             free(line);
        }
        line = get_next_line(fd2);
        if (line)
        {
             printf("this is file1: %s", line);
             free(line);
        }
    }
    
    close(fd1);
    close(fd2);
    return (0);
}