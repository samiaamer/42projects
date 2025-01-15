/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabutale <sabutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:20:38 by sabutale          #+#    #+#             */
/*   Updated: 2025/01/15 17:41:16 by sabutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int     move_player(t_map *game, size_t i, size_t j)
{
    
}

int key_hook(int keycode, t_map *var)
{
    if (keycode == XK_Escape)
        exit_program(var, 0, "exiting...");
    if (keycode == XK_w || keycode == XK_Up)
    {
        move_player(var, 0, -1);
    }
    if (keycode == XK_a || keycode == XK_Left)
        move_player(var, -1, 0);
    if (keycode == XK_s || keycode == XK_Down)
        move_player(var, 0, 1);
    if (keycode == XK_d || keycode == XK_Right)
        move_player(var, 1, 0);
    return (0);
}
