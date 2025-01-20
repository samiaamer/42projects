/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabutale <sabutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:11:29 by sabutale          #+#    #+#             */
/*   Updated: 2025/01/20 19:08:37 by sabutale         ###   ########.fr       */
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

int     img_handle(t_map *game)
{
    free_all(game, 0, "Error: faild to open the image.\n");
        return (1);
}

int     img_init(t_map *game)
{
    int i;
    int j;
    
    game->floor = mlx_xpm_file_to_image(game->mlx_ptr, "img/floor.xpm", &i, &j);
    if(!game->floor)
        return (img_handle(game));
    game->collect = mlx_xpm_file_to_image(game->mlx_ptr, "img/collectables.xpm", &i, &j);
    if(!game->collect)
        return (img_handle(game));
    game->player = mlx_xpm_file_to_image(game->mlx_ptr, "img/player.xpm", &i, &j);
    if(!game->player)
        return (img_handle(game));
    game->up = mlx_xpm_file_to_image(game->mlx_ptr, "img/up.xpm", &i, &j);
    if(!game->up)
        return (img_handle(game));
    game->left = mlx_xpm_file_to_image(game->mlx_ptr, "img/left.xpm", &i, &j);
    if(!game->left)
        return (img_handle(game));
    game->right = mlx_xpm_file_to_image(game->mlx_ptr, "img/right.xpm", &i, &j);
    if(!game->right)
        return (img_handle(game));
    game->exit_open = mlx_xpm_file_to_image(game->mlx_ptr, "img/exit_open.xpm", &i, &j);
    if(!game->exit_open)
        return (img_handle(game));
    game->wall = mlx_xpm_file_to_image(game->mlx_ptr, "img/wall.xpm", &i, &j);
    if(!game->wall)
        return (img_handle(game));
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
    }
    if (game->grid[i][j] == 'E')
    {
        mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->floor, j * WIDTH, i * HEIGHT);
        game->exit_x = j;
        game->exit_y = i;
    }
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
