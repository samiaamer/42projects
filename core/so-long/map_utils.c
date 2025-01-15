/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabutale <sabutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:24:25 by sabutale          #+#    #+#             */
/*   Updated: 2025/01/15 15:24:26 by sabutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//read map file and allocate memory for it
int read_map_file(t_map *game, char *map_name)
{
    int fd;

    fd = open(map_name, O_RDONLY);
    if (fd == -1) 
    {
        perror("Error opening file");
        return 1;
    }
    if (count_lines(fd, game)) 
        return 1;
    fd = open(map_name, O_RDONLY);
    if(add_line_to_map(game, fd))
        return 1;
    if (validate_map(game)) 
    {
        close(fd);
        return 1;
    }
    close(fd);
    return 0;
}

//count lines from the map file
int     count_lines(int fd, t_map *game)
{
    char *line;
    game->line_count = 0;

    line = get_next_line(fd);
    while (line != NULL) 
    {
        game->line_count++;
        free(line);
        line = get_next_line(fd);
    }
    close(fd);
    if (game->line_count == 0) 
    {
       ft_printf("Error: Map file is empty.\n");
        return 1;
    }
    return 0;
}

//adds the line to the map
int     add_line_to_map(t_map *game, int fd)
{
    char **temp_map;
    char *line;
    int     i;

    temp_map = malloc(sizeof(temp_map) * game->line_count);
    line = get_next_line(fd);
    i = 0;
    while (line != NULL) 
    {
        temp_map[i] = line;
        i++;
        line = get_next_line(fd);
    }
    if (!temp_map) 
    {
        perror("Memory allocation failed");
        free_map_sl(game->grid, game->line_count);
        return 1;
    }
    game->grid = temp_map;
    return 0;
}

//validate map boundaries and characters
int     validate_map(t_map *game)
{
    if(check_rectangle_map(game))
    {
       ft_printf("Error: map is not rectangle.");
        return(1);
    }
    if (check_map_boundaries(game)|| validate_map_char(game)) 
    {
        return (1);
    }
    return check_player_exit_collect(game);
}

//check player, exit, and collectable counts
int check_player_exit_collect(t_map *game) 
{
    game->player_count = count_plyers(game);

    if (game->player_count != 1) 
    {
       ft_printf("Error: There must be only one player 'P'.\n");
        return 1;
    }
    game->exit_count = count_exits(game);

    if (game->exit_count != 1)
    {
       ft_printf("Error: There must be exactly one exit 'E'.\n");
        return 1;
    }
    game->collectible_count = count_collect(game);

    if (game->collectible_count == 0)
    {
       ft_printf("Error: There must be at least one collectible 'C'.\n");
        return 1;
    }
    return 0;
}