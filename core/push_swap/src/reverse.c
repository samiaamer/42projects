/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabutale <sabutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 18:07:42 by sabutale          #+#    #+#             */
/*   Updated: 2025/02/04 18:40:31 by sabutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rot(t_push **head, char c)
{
	t_push	*last;
	t_push	*tmp;

	if (!(*head) || (*head)->next == NULL)
		return ;
	last = *head;
	tmp = *head;
	while (last->next)
		last = last->next;
	while (tmp->next->next)
		tmp = tmp->next;
	last->next = *head;
	tmp->next = NULL;
	*head = last;
	if (c == 'a')
		write(1, "rra\n", 4);
	else if (c == 'b')
		write(1, "rrb\n", 4);
}

void	rrr(t_push **stack_a, t_push **stack_b)
{
	rev_rot(stack_a, 'x');
	rev_rot(stack_b, 'x');
	write(1, "rrr\n", 4);
}
