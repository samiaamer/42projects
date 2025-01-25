/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabutale <sabutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:24:25 by sabutale          #+#    #+#             */
/*   Updated: 2025/01/25 12:57:15 by sabutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	copy_grid(t_map *game)
{
	size_t	i;

	i = 0;
	game->o_grid = malloc(sizeof(game->o_grid) * game->line_count);
	while (i < game->line_count)
	{
		game->o_grid[i] = ft_strdup(game->grid[i]);
		i++;
	}
}

// count lines from the map file
int	count_lines(int fd, t_map *game)
{
	char	*line;

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
		return (1);
	}
	return (0);
}

// adds the line to the map
int	add_line_to_map(t_map *game, int fd)
{
	char	**temp_map;
	char	*line;
	int		i;

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
		return (1);
	}
	game->grid = temp_map;
	return (0);
}

// validate map boundaries and characters
int	validate_map(t_map *game)
{
	if (check_rectangle_map(game))
	{
		ft_printf("Error: map is not rectangle.");
		return (1);
	}
	if (check_map_boundaries(game) || validate_map_char(game))
	{
		return (1);
	}
	return (check_player_exit_collect(game));
}

// check player, exit, and collectable counts
int	check_player_exit_collect(t_map *game)
{
	game->player_count = count_plyers(game);
	if (game->player_count != 1)
	{
		ft_printf("Error: There must be only one player 'P'.\n");
		return (1);
	}
	game->exit_count = count_exits(game);
	if (game->exit_count != 1)
	{
		ft_printf("Error: There must be exactly one exit 'E'.\n");
		return (1);
	}
	game->collectible_count = count_collect(game);
	game->flood_collect = game->collectible_count;
	if (game->collectible_count == 0)
	{
		ft_printf("Error: There must be at least one collectible 'C'.\n");
		return (1);
	}
	return (0);
}
