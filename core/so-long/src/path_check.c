/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samia <samia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:12:22 by sabutale          #+#    #+#             */
/*   Updated: 2025/01/25 23:57:39 by samia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	find_player_pos(t_map *game)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < game->line_count)
	{
		j = 0;
		while (j < game->line_len)
		{
			if (game->grid[i][j] == 'P')
			{
				game->player_x = j;
				game->player_y = i;
				break ;
			}
			j++;
		}
		i++;
	}
}

void	flood_fill(t_map *game, int x, int y)
{
	if (game->o_grid[y][x] == '1')
		return ;
	if (game->o_grid[y][x] == 'C')
		game->flood_collect--;
	if (game->o_grid[y][x] == 'E')
		game->exit_flag = 1;
	game->o_grid[y][x] = '1';
	flood_fill(game, x - 1, y);
	flood_fill(game, x + 1, y);
	flood_fill(game, x, y - 1);
	flood_fill(game, x, y + 1);
}

int	player_img(t_map *game, int i, int j)
{
	game->player = mlx_xpm_file_to_image(game->mlx_ptr, "img/player.xpm", &i,
			&j);
	if (!game->player)
		return (img_handle(game));
	game->up = mlx_xpm_file_to_image(game->mlx_ptr, "img/up.xpm", &i, &j);
	if (!game->up)
		return (img_handle(game));
	game->left = mlx_xpm_file_to_image(game->mlx_ptr, "img/left.xpm", &i, &j);
	if (!game->left)
		return (img_handle(game));
	game->right = mlx_xpm_file_to_image(game->mlx_ptr, "img/right.xpm", &i, &j);
	if (!game->right)
		return (img_handle(game));
	return (1);
}
