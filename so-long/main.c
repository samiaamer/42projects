/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabutale <sabutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:11:36 by sabutale          #+#    #+#             */
/*   Updated: 2025/01/20 19:24:03 by sabutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int check_ext(char *map_name)
{
    int  str_len;
    char * tmp;
    int     i;

    i = 0;
    tmp = ".ber";
    str_len = ft_strlen(map_name) - 1;
    while (map_name[str_len] != '.')
    {
        i++;
        str_len--;   
    }
    if (i != 3)
        return (1);
    i = 0;
    while (map_name[str_len])
    {
        if (!(map_name[str_len] == tmp[i]))
            return (1);
        str_len++;
        i++;
    }
    return (0);
}

int     parse_map(t_map *game, char *map_name)
{
    if (read_map_file(game, map_name) || check_ext(map_name)) 
    {
        free_map_sl(game->grid, game->line_count);
        ft_printf("Error reading map file.\n");
        return (1);
    }
    copy_grid(game);
    find_player_pos(game);
    flood_fill(game, game->player_x, game->player_y);
    if (!(game->exit_flag && game->flood_collect == 0))
    {
        ft_printf("Error: map not solvable.\n");
        return (1);
    }
    return (0);
}

int main(int argc, char **argv)
{
    t_map  game;
    if (argc == 2)
    {
        init_values(&game);
        if(parse_map(&game, argv[1]))
            return (1);
        if(init_mlx(&game))
            return (1);
        mlx_hook(game.mlx_win, 17, 0, free_all, &game);
        mlx_hook(game.mlx_win, 2, 1L<<0, key_hook, &game);
        mlx_loop(game.mlx_ptr);
    }
    return (0);
}


