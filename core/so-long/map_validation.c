/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabutale <sabutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:12:04 by sabutale          #+#    #+#             */
/*   Updated: 2025/01/15 15:12:05 by sabutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_line_boundaries(char *line, t_map *game)
{
	if (line[0] != '1' || line[game->line_len - 1] != '1')
	{
		ft_printf("Boundary error at line: %s\n", line);
		return (1);
	}
	return (0);
}

int	check_first_last_lines(char *line, t_map *game)
{
	size_t	i;

	i = 0;
	while (i < game->line_len)
	{
		if (line[i] != '1')
		{
			ft_printf("Boundry error at line: %s\n", line);
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_map_boundaries(t_map *game)
{
	size_t	i;

	if (check_first_last_lines(game->grid[0], game)
		|| check_first_last_lines(game->grid[game->line_count - 1], game))
		return (1);
	i = 1;
	while (i < game->line_count - 1)
	{
		if (check_line_boundaries(game->grid[i], game))
			return (1);
		i++;
	}
	return (0);
}

int	is_valid_char(char c)
{
	return (!(c == '1' || c == '0' || c == 'P' || c == 'E' || c == 'C'));
}

int	check_line_chars(char *line, t_map *game)
{
	size_t	i;

	i = 0;
	while (i < game->line_len)
	{
		if (is_valid_char(line[i]))
			return (1);
		i++;
	}
	return (0);
}
