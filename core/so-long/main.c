/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabutale <sabutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:11:36 by sabutale          #+#    #+#             */
/*   Updated: 2025/01/15 19:59:02 by sabutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void     free_map_sl(char **game, int line_count)
{
    int i;
    
    i = 0;
    while (i < line_count)
    {
        free(game[i]);
        i++;
    }
    free(game);
}

int     parse_map(t_map *game, char *map_name)
{
    size_t  i;
    size_t  j;

    i = 0;
    j = 0;
    if (read_map_file(game, map_name)) 
    {
       ft_printf("Error reading map file.\n");
        return (1);
    }
    while (i < game->line_count)
    {
        j  = 0;
        while (j < game->line_len)
        {
           ft_printf("%c", game->grid[i][j]);
            j++;
        }
        i++;
       ft_printf("\n");
    }
    return (0);
}

int main(int argc, char **argv)
{
    t_map  game;
    if (argc == 2)
    {
        parse_map(&game, argv[1]);
        // free_map_sl(game.grid, game.line_count);
        if(init_mlx(&game))
            return (1);
        //mlx_hook(game.mlx_win, 17, 0, my_exit_function, &game);//to exit the window through the X
        mlx_hook(game.mlx_win, 2, 1L<<0, key_hook, &game);
        mlx_loop(game.mlx_ptr);
    }
    return (0);
}
