/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabutale <sabutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:11:54 by sabutale          #+#    #+#             */
/*   Updated: 2025/01/26 13:28:14 by sabutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	validate_map_char(t_map *game)
{
	size_t	i;

	i = 0;
	while (i < game->line_count)
	{
		if (check_line_chars(game->grid[i], game))
		{
			ft_printf("Invalid characters at line %d:  %s\n", i,
				game->grid[i]);
			return (1);
		}
		i++;
	}
	return (0);
}

int	count_plyers(t_map *game)
{
	size_t	i;
	int		j;
	int		num_ply;

	i = 0;
	num_ply = 0;
	while (i < game->line_count)
	{
		j = 0;
		while (game->grid[i][j] != '\0')
		{
			if (game->grid[i][j] == 'P')
				num_ply++;
			j++;
		}
		i++;
	}
	return (num_ply);
}

int	count_exits(t_map *game)
{
	size_t	i;
	int		j;
	int		num_exits;

	i = 0;
	num_exits = 0;
	while (i < game->line_count)
	{
		j = 0;
		while (game->grid[i][j] != '\0')
		{
			if (game->grid[i][j] == 'E')
				num_exits++;
			j++;
		}
		i++;
	}
	return (num_exits);
}

int	count_collect(t_map *game)
{
	size_t	i;
	size_t	j;
	int		num_coll;

	i = 0;
	num_coll = 0;
	while (i < game->line_count)
	{
		j = 0;
		while (j < game->line_len)
		{
			if (game->grid[i][j] == 'C')
				num_coll++;
			j++;
		}
		i++;
	}
	return (num_coll);
}

int	check_rectangle_map(t_map *game)
{
	size_t	i;
	size_t	first_row_length;
	size_t	line_length;

	first_row_length = ft_strlen(game->grid[0]);
	if (first_row_length > 0 && game->grid[0][first_row_length - 1] == '\n')
		first_row_length--;
	i = 1;
	while (i < game->line_count)
	{
		line_length = ft_strlen(game->grid[i]);
		if (line_length > 0 && game->grid[i][line_length - 1] == '\n')
			line_length--;
		if (line_length != first_row_length)
			return (1);
		i++;
	}
	game->line_len = line_length;
	return (0);
}
