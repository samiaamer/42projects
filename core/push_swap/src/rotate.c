/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabutale <sabutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:29:00 by sabutale          #+#    #+#             */
/*   Updated: 2025/02/09 18:26:29 by sabutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_push **head, char c)
{
	t_push	*last;
	t_push	*first;

	if (!(*head) || !(*head)->next)
		return ;
	first = *head;
	last = *head;
	while (last->next)
		last = last->next;
	last->next = first;
	*head = (*head)->next;
	first->next = NULL;
	if (c == 'a')
		write(1, "ra\n", 3);
	else if (c == 'b')
		write(1, "rb\n", 3);
}

void	rr(t_push **stack_a, t_push **stack_b)
{
	rotate(stack_a, 'x');
	rotate(stack_b, 'x');
	write(1, "rr\n", 3);
}
