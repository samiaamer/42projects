#include "get_next_line.h"

int main(void)
{
    int fd = open("text.txt", O_RDONLY);
    int fd2 = open("test2.txt", O_RDONLY);
    char *line;

    if (fd == -1) {
        perror("Error opening file");
        return (1);
    }
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("this is file1: %s", line);
        free(line);
    }
    while ((line = get_next_line(fd2)) != NULL)
    {
        printf("this is file2:  %s", line);
        free(line);
    }
    close(fd);
    close(fd2);
    return (0);
}