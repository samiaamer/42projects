/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabutale <sabutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 19:10:29 by sabutale          #+#    #+#             */
/*   Updated: 2025/02/09 18:26:39 by sabutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_push	*find_smallest(t_push *head)
{
	t_push	*tmp;
	t_push	*small;

	small = NULL;
	tmp = head;
	while (tmp->next)
	{
		if (tmp->index == 0)
			small = tmp;
		tmp = tmp->next;
	}
	return (small);
}

int	stack_len(t_push *head)
{
	t_push	*tmp;
	int		i;

	i = 0;
	tmp = head;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}
