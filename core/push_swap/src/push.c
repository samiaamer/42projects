/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabutale <sabutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:29:03 by sabutale          #+#    #+#             */
/*   Updated: 2025/02/04 13:38:20 by sabutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     pa(t_push *stack_a, t_push *stack_b)
{
    t_push  *head_a;
    t_push  *head_b;
    int     tmp;
    
    head_a = stack_a;
    head_a = stack_b;
    tmp = head_a; 
    head_a = head_a->next;
    head_a = tmp;
    write (1, "pa\n", 3);
    return (0);
}
int     pb(t_push *stack_a, t_push *stack_b)
{
    t_push  *head_a;
    t_push  *head_b;
    int     tmp;
    
    head_a = stack_a;
    head_a = stack_b;
    tmp = head_a; 
    head_a = head_a->next;
    head_a = tmp;
    write (1, "pb\n", 3);
    return (0);
}
