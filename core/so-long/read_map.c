#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

//checks if the first and last characters in a line are '1' (top and botton lines)
int    check_line_boundaries(char *line)
{
    int line_length;

    line_length = ft_strlen(line);
    if (line[line_length - 1] == '\n')
        line_length--;
    if (line[0] != '1' || line[line_length - 1] != '1')
        return (0);
    return (1);
}

//checks the entire map's first and last lines are valid (used after reading teh full map in to memory)
int    check_map_boundaries(char **map, int line_count)
{
    int     i;

    i = 0;
    while (i < line_count)
    {
        if (i == 0 || i == line_count - 1)
        {
            if (!check_line_boundaries(map[i]))
                return (0);
        }
        else
            check_line_boundaries(map[i]);
        i++;
    }
    return (1);
}

//checks if the cahracter is valid
int    is_valid_char(char c)
{
    return (c == '1' || c == '0' || c =='P' || c == 'E' || c == 'C');
}

//loop through a the line to check every character with the is_valid_char function
int    check_line_chars(char *line)
{
    int    i;

    i = 0;
    while (line[i] != '\0')
    {
        if (!is_valid_char(line[i]))
            return (0);
    }
    return (1);
}

//make sure all characters int the map are valid using check_line_chars function (after checking the boundaries)
int    validate_map_char(char **map, int line_count)
{
    int    i;

    i = 0;
    while (i < line_count)
    {
        if (!check_line_chars(map[i]))
            return (0);
        i++;
    }
    return (1);
}



int    read_map_file()
{
    int     fd;
    char    *line;
    int     line_count;
    char    **map;
    char **temp_map;

    line_count = 0;
    map = NULL;
    line = NULL;
    fd = open("map.ber", O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return (1);
    }
    
    while ((line = get_next_line(fd)) != NULL)
    {
        temp_map = realloc(map, sizeof(char *)*(line_count + 1));
        if (!temp_map)
        {
            perror("Memory allocation faild");
            free(map);
            return (1);
        }
        map = temp_map;
        map[line_count] = line;
        line_count++;
        printf("%s\n", map[line_count - 1]);
    }
   if (check_map_boundaries(map, line_count) == 0) {
    printf("Invalid boundary\n");
    return (1);  // Return early if boundaries are invalid
}

if (validate_map_char(map, line_count) == 0) {
    printf("Invalid characters in map\n");
    return (1);  // Return early if characters are invalid
} 
    
    close(fd);
    return (0);
}

int     free_map(char **map, int line_count)
{
    int i;
    
    i = 0;
    while (i < line_count)
    {
        free(map[i]);
        i++;
    }
    free(map);
    return (0);
    
}


int main() {
    if (read_map_file() != 0) {
        fprintf(stderr, "Error reading map file.\n");
        return 1;
    }
    return 0;
}