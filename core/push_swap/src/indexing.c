/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabutale <sabutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:30:16 by sabutale          #+#    #+#             */
/*   Updated: 2025/02/04 19:09:23 by sabutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_push	*find_smallest_undindexed(t_push *head)
{
	t_push	*cur;
	t_push	*smallest;

	smallest = NULL;
	cur = head;
	while (cur)
	{
		if (cur->index == -1 && (!smallest || smallest->data > cur->data))
			smallest = cur;
		cur = cur->next;
	}
	return (smallest);
}

void	indexing(t_push *head)
{
	int		index;
	t_push	*smallest;

	index = 0;
	while (1)
	{
		smallest = find_smallest_undindexed(head);
		if (!smallest)
			break ;
		smallest->index = index++;
	}
}

int	is_sorted(t_push *head)
{
	while (head->next)
	{
		if (head->data > head->next->data)
			return (0);
		head = head->next;
	}
	return (1);
}
