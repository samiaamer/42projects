/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabutale <sabutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:24:30 by sabutale          #+#    #+#             */
/*   Updated: 2025/02/03 19:54:29 by sabutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/includes/libft.h"
#include <limits.h>
#include <stdlib.h>
#include <stddef.h>//

typedef struct s_push
{
    int     data;
    int     index;
    struct s_push   *next;
}       t_push;

t_push    *create_stack(int argc, char **argv);
t_push    *create_node(int nbr);
t_push    *find_smallest(t_push *head);
int     check_dup(int nbr, t_push *head);
int     push_swap_atoi(const char *nbr, t_push *head);
int     main(int argc, char **argv);
int     is_sorted (t_push *head);
void    exit_free(t_push *head, int flag);
void    print_list(t_push *head);
void    indexing (t_push *head);

#endif