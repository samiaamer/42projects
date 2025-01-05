#include "so-long.h"

//make sure all characters int the map are valid using check_line_chars function (after checking the boundaries)
int    validate_map_char(t_map *map)
{
    size_t    i;

    i = 0;
    while (i < map->line_count)
    {
        if (!check_line_chars(map->grid[i]))
        {
            printf("Invalid characters at line %ld:  %s\n", i, map->grid[i]);
            return (0);
        }
        i++;
    }
    return (1);
}

//count number of plyers
int    count_plyers(t_map *map)
{
    size_t     i;
    int     j;
    int     num_ply;

    i = 0;
    num_ply = 0;
    while (i < map->line_count)
    {
        j = 0;
        while (map->grid[i][j] != '\0')
        {
            if (map->grid[i][j] == 'P')
                num_ply++;
            j++;
        }
        i++;
    }
    return (num_ply);
}

int    count_exits(t_map *map)
{
    size_t     i;
    int     j;
    int     num_exits;

    i = 0;
    num_exits = 0;
    while (i < map->line_count)
    {
        j = 0;
        while (map->grid[i][j] != '\0')
        {
            if (map->grid[i][j] == 'E')
                num_exits++;
            j++;
        }
        i++;
    }
    return (num_exits);
}

int    count_collect(t_map *map)
{
    size_t     i;
    int     j;
    int     num_coll;

    i = 0;
    num_coll = 0;
    while (i < map->line_count)
    {
        j = 0;
        while (map->grid[i][j] != '\0')
        {
            if (map->grid[i][j] == 'E')
                num_coll++;
            j++;
        }
        i++;
    }
    return (num_coll);
}

int    check_rectangle_map(t_map *map)
{
    size_t   i;
    size_t   first_row_length;
    size_t   line_length;

    if (map->line_count == 0)
        return (1);
    first_row_length = ft_strlen(map->grid[0]);
    if (first_row_length > 0 && map->grid[0][first_row_length - 1] == '\n')
        first_row_length--;
    i = 1;
    while (i < map->line_count)
    {
        line_length = ft_strlen(map->grid[i]);
        if (line_length > 0 && map->grid[i][line_length - 1] == '\n')
            line_length--;
        if (line_length != first_row_length)
            return(1);
        i++;
    }
    return (0);
}
