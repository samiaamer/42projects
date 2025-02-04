/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabutale <sabutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:55:27 by sabutale          #+#    #+#             */
/*   Updated: 2025/02/04 13:19:31 by sabutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     sa(t_push *head)
{
    t_push  *next;
    int     t_val;
    int     t_ind;
    
    next = head->next->data;
    if (!head || !next)
        exit_free(head, 1);
    t_val = head->data;
    t_ind = head->index;
    head->data = next->data;
    head->index = next->index;
    next->data = t_val;
    next->index = t_ind;
    write (1, "sa\n", 3);
    return (0);
}
int     sb(t_push *head)
{
    t_push  *next;
    int     t_val;
    int     t_ind;
    
    next = head->next->data;
    if (!head || !next)
        exit_free(head, 1);
    t_val = head->data;
    t_ind = head->index;
    head->data = next->data;
    head->index = next->index;
    next->data = t_val;
    next->index = t_ind;
    write (1, "sb\n", 3);
    return (0);
}
int     ss(t_push *head)
{
    sa(head);
    sb(head);
}