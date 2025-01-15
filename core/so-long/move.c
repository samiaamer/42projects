/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabutale <sabutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:20:38 by sabutale          #+#    #+#             */
/*   Updated: 2025/01/15 19:53:58 by sabutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int     move_player(t_map *game, size_t i, size_t j)
{
    int new_x;
    int new_y;
    
    new_x = game->player_x + i;
    new_y = game->player_y + j;
    if (game->grid[new_y][new_x] != '1')
    {   
        mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->floor, game->player_x * WIDTH, game->player_y * HEIGHT);
        if (game->grid[new_y][new_x] == 'C')
            game->collectible_count--;
        if (game->collectible_count == 0)
        {
            mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->exit_open, game->exit_x * WIDTH, game->exit_y * HEIGHT);
            //exit the program
        }
        game->player_x += i;
        game->player_y += j;
        
    }

    mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->player, game->player_x * WIDTH, game->player_y * HEIGHT);
    return (0);
}

int key_hook(int keycode, t_map *game)
{
    // if (keycode == XK_Escape)
    //     exit_program(game, 0, "exiting...");
    if (keycode == XK_w || keycode == XK_Up)
    {
        move_player(game, 0, -1);
    }
    if (keycode == XK_a || keycode == XK_Left)
        move_player(game, -1, 0);
    if (keycode == XK_s || keycode == XK_Down)
        move_player(game, 0, 1);
    if (keycode == XK_d || keycode == XK_Right)
        move_player(game, 1, 0);
    return (0);
}
