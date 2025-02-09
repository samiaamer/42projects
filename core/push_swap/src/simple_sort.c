/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabutale <sabutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 11:48:36 by sabutale          #+#    #+#             */
/*   Updated: 2025/02/09 18:28:40 by sabutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_push **head)
{
	while (!(is_sorted(*head)))
	{
		if ((*head)->index > (*head)->next->index)
			swap(head, 'a');
		if ((*head)->next->index > (*head)->next->next->index)
			rev_rot(head, 'a');
	}
}

void	sort_four(t_push **stack_a, t_push **stack_b)
{
	while (stack_len(*stack_a) > 3)
	{
		if ((*stack_a)->index == 0)
			pb(stack_a, stack_b);
		else
			rotate(stack_a, 'a');
	}
	sort_three(stack_a);
	pa(stack_a, stack_b);
}

void	sort_five(t_push **stack_a, t_push **stack_b)
{
	while (stack_len(*stack_a) > 3)
	{
		if ((*stack_a)->index == 0 || (*stack_a)->index == 1)
			pb(stack_a, stack_b);
		else
			rotate(stack_a, 'a');
	}
	sort_three(stack_a);
	if (is_sorted(*stack_b))
		swap(stack_b, 'b');
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}
