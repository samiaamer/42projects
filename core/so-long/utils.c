/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabutale <sabutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:11:29 by sabutale          #+#    #+#             */
/*   Updated: 2025/01/15 17:20:17 by sabutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int     init_mlx(t_map *game)
{
    game->mlx_ptr = mlx_init();
    if (game->mlx_ptr == NULL)
        return (1);
    game->mlx_win = mlx_new_window(game->mlx_ptr, WIDTH * game->line_len, HEIGHT * game->line_count, "Hello World!");
    if(img_init(game))
        return (1);
    return (0);
}

int     img_handle()
{
    ft_printf("Error: faild to open the image.\n");
        return (1);
}

int     img_init(t_map *game)
{
    int i;
    int j;
    
    game->floor = mlx_xpm_file_to_image(game->mlx_ptr, "img/floor.xpm", &i, &j);
    if(!game->floor)
        return (img_handle());
    game->collect = mlx_xpm_file_to_image(game->mlx_ptr, "img/collectables.xpm", &i, &j);
    if(!game->collect)
        return (img_handle());
    game->player = mlx_xpm_file_to_image(game->mlx_ptr, "img/player.xpm", &i, &j);
    if(!game->player)
        return (img_handle());
    game->exit = mlx_xpm_file_to_image(game->mlx_ptr, "img/exit_close.xpm", &i, &j);
    if(!game->exit)
        return (img_handle());
    game->wall = mlx_xpm_file_to_image(game->mlx_ptr, "img/wall.xpm", &i, &j);
    if(!game->wall)
        return (img_handle());
    put_img(game);
    return (0);
}

void     block_img(t_map *game, size_t i, size_t j)
{
    if (game->grid[i][j] == '1')
        mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->wall, j * WIDTH, i * HEIGHT);
    if (game->grid[i][j] == '0')
        mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->floor, j * WIDTH, i * HEIGHT);
    if (game->grid[i][j] == 'P')
    {
        mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->player, j * WIDTH, i * HEIGHT);
        game->player_x = j * WIDTH;
        game->player_y = i * HEIGHT;
    }
    if (game->grid[i][j] == 'E')
        mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->exit, j * WIDTH, i * HEIGHT);
    if (game->grid[i][j] == 'C')
        mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->collect, j * WIDTH, i * HEIGHT);
}

int     put_img(t_map *game)
{
    size_t  i;
    size_t  j;

    i = 0;
    while (i < game->line_count)
    {
        j = 0;
        while (j < game->line_len)
        {
            block_img(game, i, j);
            j++;
        }
        i++;
    }
    return (0);
}
