/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabutale <sabutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:12:22 by sabutale          #+#    #+#             */
/*   Updated: 2025/01/20 19:12:39 by sabutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    find_player_pos(t_map *game)
{
    size_t  i;
    size_t  j;

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
                break;
            }
            j++;
        }
        i++;
    }
}

void   flood_fill(t_map *game, int x, int y)
{
    print_map(game);
    printf("\n");
    if (game->o_grid[y][x] == '1')
        return;
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

