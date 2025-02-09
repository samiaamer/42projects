/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabutale <sabutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 14:22:28 by sabutale          #+#    #+#             */
/*   Updated: 2025/02/09 17:13:50 by sabutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_index(t_push *head)
{
	int		max;
	t_push	*tmp;

	max = head->index;
	tmp = head;
	while (tmp)
	{
		if (max < tmp->index)
			max = tmp->index;
		tmp = tmp->next;
	}
	return (max);
}

int	num_iter(int max)
{
	int	counter;

	counter = 0;
	while (max != 0)
	{
		max >>= 1;
		counter++;
	}
	return (counter);
}

void	radix_sort(t_push **stack_a, t_push **stack_b, int num_iteration)
{
	int	i;
	int	j;
	int	a_len;

	i = 0;
	a_len = stack_len(*stack_a);
	while (i < num_iteration)
	{
		j = 0;
		while (j < a_len)
		{
			if ((((*stack_a)->index >> i) & 1) == 1)
				rotate(stack_a, 'a');
			else
				pb(stack_a, stack_b);
			j++;
		}
		while (stack_len(*stack_b))
			pa(stack_a, stack_b);
		i++;
	}
}
