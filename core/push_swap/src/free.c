/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabutale <sabutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 11:47:39 by sabutale          #+#    #+#             */
/*   Updated: 2025/02/09 18:26:10 by sabutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_free(t_push *head, int flag)
{
	if (flag)
		ft_putstr_fd("Error\n", 2);
	free_stack(head);
	exit(flag);
}

void	free_stack(t_push *head)
{
	t_push	*temp;

	if (head)
	{
		while (head)
		{
			temp = head;
			head = head->next;
			free(temp);
		}
	}
}
