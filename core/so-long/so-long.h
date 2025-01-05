#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "libft/libft.h"
#include "GNL/get_next_line.h"

#ifndef SO_LONG_H
# define SO_LONG_H

typedef struct s_map
{
    char **grid;
    size_t line_count;
    int player_count;
    int exit_count;
    int collectible_count;
}       t_map;

void   free_map(char **map, int line_count);
int    check_line_boundaries(char *line);
int    check_first_last_lines(char *line, int line_number, int line_count);
int    check_map_boundaries(t_map *map);
int    is_valid_char(char c);
int    check_line_chars(char *line);
int    validate_map_char(t_map *map);
int    count_plyers(t_map *map);
int    count_exits(t_map *map);
int    count_collect(t_map *map);
int    check_rectangle_map(t_map *map);
int    read_map_file(t_map *map);
int    read_lines(int fd, t_map *map);
int    add_line_to_map(t_map *map, char *line);
int    validate_map(t_map *map);
int    check_player_exit_collect(t_map *map);
int    main();

#endif