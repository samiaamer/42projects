#include "so-long.h"

//checks if the first and last characters in a line are '1' (top and botton lines)
int    check_line_boundaries(char *line)
{
    int line_length;

    line_length = ft_strlen(line);
    if (line[line_length - 1] == '\n')
        line_length--;
    if (line[0] != '1' || line[line_length - 1] != '1')
    {
        printf("Boundary error at line: %s\n", line);
        return (0);
    }
    return (1);
}

//check the first and last lines
int     check_first_last_lines(char *line, int line_number, int line_count)
{
    int     line_length;
    int     i;

    i = 0;
    line_length = ft_strlen(line);
    if (line_number == 0 || line_number == line_count - 1)
    {
        if (line[line_length - 1] == '\n')
            line_length--;
        while (i < line_length)
        {
            if (line[i] != '1')
            {
                printf("Boundry error at line %d: %s\n", line_number, line);
                return (0);
            }
            i++;
        }
    }
    return (1);
}

//checks the entire map bounderies
int    check_map_boundaries(t_map *map)
{
    size_t     i;

    if (!check_first_last_lines(map->grid[0], 0, map->line_count) ||
        !check_first_last_lines(map->grid[map->line_count - 1], map->line_count - 1, map->line_count))
        return (0);
    i = 1;
    while (i < map->line_count)
    {
        if (!check_line_boundaries(map->grid[i]))
            return (0);
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
        if (line[i] == '\n')
        {
            i++;
            continue;
        }
        if (!is_valid_char(line[i]))
            return (0);
        i++;
    }
    return (1);
}
