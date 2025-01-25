/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabutale <sabutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:20:38 by sabutale          #+#    #+#             */
/*   Updated: 2025/01/25 13:39:30 by sabutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_dir(t_map *game, char dir)
{
	if (dir == 'D')
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->player,
			game->player_x * WIDTH, game->player_y * HEIGHT);
	if (dir == 'U')
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->up,
			game->player_x * WIDTH, game->player_y * HEIGHT);
	if (dir == 'R')
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->right,
			game->player_x * WIDTH, game->player_y * HEIGHT);
	if (dir == 'L')
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->left,
			game->player_x * WIDTH, game->player_y * HEIGHT);
}

void	move_collect(t_map *game, int new_x, int new_y)
{
	if (game->grid[new_y][new_x] == 'C')
	{
		game->grid[new_y][new_x] = '0';
		game->collectible_count--;
	}
	if (game->collectible_count == 0)
	{
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->exit_open,
			game->exit_x * WIDTH, game->exit_y * HEIGHT);
		if (game->grid[new_y][new_x] == 'E')
			free_all(game, 0, "YOU WON!!\n");
	}
}

void	print_move(t_map *game)
{
	if (game->itoa_ptr)
		free(game->itoa_ptr);
	game->itoa_ptr = ft_itoa(game->move_count);
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->wall, 2 * WIDTH,
		0 * HEIGHT);
	mlx_string_put(game->mlx_ptr, game->mlx_win, 5, 25, 0xFFFFFF,
		"number of moves:");
	mlx_string_put(game->mlx_ptr, game->mlx_win, 5, 26, 0xFFFFFF,
		"number of moves:");
	mlx_string_put(game->mlx_ptr, game->mlx_win, 6, 25, 0xFFFFFF,
		"number of moves:");
	mlx_string_put(game->mlx_ptr, game->mlx_win, 6, 26, 0xFFFFFF,
		"number of moves:");
	mlx_string_put(game->mlx_ptr, game->mlx_win, 105, 25, 0xFFFFFF,
		game->itoa_ptr);
	mlx_string_put(game->mlx_ptr, game->mlx_win, 106, 25, 0xFFFFFF,
		game->itoa_ptr);
	mlx_string_put(game->mlx_ptr, game->mlx_win, 105, 26, 0xFFFFFF,
		game->itoa_ptr);
	mlx_string_put(game->mlx_ptr, game->mlx_win, 106, 26, 0xFFFFFF,
		game->itoa_ptr);
}

void	move_player(t_map *game, size_t i, size_t j, char dir)
{
	int	new_x;
	int	new_y;

	new_x = game->player_x + i;
	new_y = game->player_y + j;
	if (game->grid[new_y][new_x] != '1')
	{
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->floor,
			game->player_x * WIDTH, game->player_y * HEIGHT);
		move_collect(game, new_x, new_y);
		game->player_x += i;
		game->player_y += j;
		game->move_count++;
		print_move(game);
		set_dir(game, dir);
		ft_printf("number of moves: %d\n", game->move_count);
	}
}

int	key_hook(int keycode, t_map *game)
{
	if (keycode == XK_Escape)
		free_all(game, 0, "exiting...");
	if (keycode == XK_w || keycode == XK_Up)
		move_player(game, 0, -1, 'U');
	if (keycode == XK_a || keycode == XK_Left)
		move_player(game, -1, 0, 'L');
	if (keycode == XK_s || keycode == XK_Down)
		move_player(game, 0, 1, 'D');
	if (keycode == XK_d || keycode == XK_Right)
		move_player(game, 1, 0, 'R');
	return (0);
}
