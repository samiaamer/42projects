/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samia <samia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 13:10:05 by sabutale          #+#    #+#             */
/*   Updated: 2025/01/25 23:58:02 by samia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_values(t_map *game)
{
	game->exit_y = 0;
	game->exit_x = 0;
	game->player_y = 0;
	game->player_x = 0;
	game->move_count = 0;
	game->collectible_count = 0;
	game->exit_count = 0;
	game->player_count = 0;
	game->line_len = 0;
	game->line_count = 0;
	game->flood_collect = 0;
	game->exit_flag = 0;
	init_values2(game);
}

void	init_values2(t_map *game)
{
	game->exit_open = NULL;
	game->collect = NULL;
	game->player = NULL;
	game->wall = NULL;
	game->floor = NULL;
	game->map = NULL;
	game->mlx_win = NULL;
	game->mlx_ptr = NULL;
	game->o_grid = NULL;
	game->grid = NULL;
	game->up = NULL;
	game->left = NULL;
	game->right = NULL;
	game->itoa_ptr = NULL;
}
