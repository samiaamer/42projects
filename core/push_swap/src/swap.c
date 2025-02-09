/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabutale <sabutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:55:27 by sabutale          #+#    #+#             */
/*   Updated: 2025/02/09 18:26:36 by sabutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_push **head, char c)
{
	t_push	*next;

	if (!(*head) || !(*head)->next)
		return ;
	next = (*head)->next;
	(*head)->next = next->next;
	next->next = (*head);
	(*head) = next;
	if (c == 'a')
		write(1, "sa\n", 3);
	else if (c == 'b')
		write(1, "sb\n", 3);
}

void	ss(t_push **stack_a, t_push **stack_b)
{
	swap(stack_a, 'x');
	swap(stack_b, 'x');
	write(1, "ss\n", 3);
}
