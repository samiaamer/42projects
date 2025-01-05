#include "so-long.h"

//read map file and allocate memory for it
int read_map_file(t_map *map)
{
    int fd;

    fd = open("map.ber", O_RDONLY);
    if (fd == -1) 
    {
        perror("Error opening file");
        return 1;
    }
    if (read_lines(fd, map)) 
    {
        close(fd);
        return 1;
    }
    if (!validate_map(map)) 
    {
        close(fd);
        return 1;
    }
    close(fd);
    return 0;
}

//read lines from the map file into map struct
int     read_lines(int fd, t_map *map)
{
    char *line;
    map->grid = NULL;
    map->line_count = 0;

    while ((line = get_next_line(fd)) != NULL) 
    {
        if (add_line_to_map(map, line))
            return 1;
    }
    if (map->line_count == 0) 
    {
        printf("Error: Map file is empty.\n");
        return 1;
    }
    return 0;
}

//adds the line to the map
int     add_line_to_map(t_map *map, char *line)
{
    char **temp_map;

    temp_map = realloc(map->grid, sizeof(char *) * (map->line_count + 1));
    if (!temp_map) 
    {
        perror("Memory allocation failed");
        free_map(map->grid, map->line_count);
        return 1;
    }
    map->grid = temp_map;
    map->grid[map->line_count++] = line;
    return 0;
}

//validate map boundaries and characters
int     validate_map(t_map *map)
{
    if (!check_map_boundaries(map) || !validate_map_char(map)) 
    {
        return 1;
    }
    return check_player_exit_collect(map);
}

//check player, exit, and collectable counts
int check_player_exit_collect(t_map *map) 
{
    map->player_count = count_plyers(map);

    if (map->player_count != 1) 
    {
        printf("Error: There must be only one player 'P'.\n");
        return 1;
    }
    map->exit_count = count_exits(map);

    if (map->exit_count != 1)
    {
        printf("Error: There must be exactly one exit 'E'.\n");
        return 1;
    }
    map->collectible_count = count_collect(map);

    if (map->collectible_count == 0)
    {
        printf("Error: There must be at least one collectible 'C'.\n");
        return 1;
    }
    return 0;
}