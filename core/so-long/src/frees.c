/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samia <samia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:20:00 by sabutale          #+#    #+#             */
/*   Updated: 2025/01/25 23:58:05 by samia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_map_sl(char **game, int line_count)
{
	int	i;

	i = 0;
	while (i < line_count)
	{
		free(game[i]);
		i++;
	}
	free(game);
}

void	destroy_img(t_map *game)
{
	if (game->floor)
		mlx_destroy_image(game->mlx_ptr, game->floor);
	if (game->collect)
		mlx_destroy_image(game->mlx_ptr, game->collect);
	if (game->exit_open)
		mlx_destroy_image(game->mlx_ptr, game->exit_open);
	if (game->wall)
		mlx_destroy_image(game->mlx_ptr, game->wall);
	if (game->player)
		mlx_destroy_image(game->mlx_ptr, game->player);
	if (game->up)
		mlx_destroy_image(game->mlx_ptr, game->up);
	if (game->left)
		mlx_destroy_image(game->mlx_ptr, game->left);
	if (game->right)
		mlx_destroy_image(game->mlx_ptr, game->right);
}

int	free_all(t_map *game, int flag, char *message)
{
	free_map_sl(game->grid, game->line_count);
	free_map_sl(game->o_grid, game->line_count);
	if (game->itoa_ptr)
		free(game->itoa_ptr);
	destroy_img(game);
	if (game->mlx_win)
		mlx_destroy_window(game->mlx_ptr, game->mlx_win);
	if (game->mlx_ptr)
	{
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
	}
	if (flag == 1)
		ft_putstr_fd(message, 2);
	else if (flag == 0)
		ft_putstr_fd(message, 1);
	exit(flag);
	return (0);
}
