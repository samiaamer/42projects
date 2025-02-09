/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabutale <sabutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:28:21 by sabutale          #+#    #+#             */
/*   Updated: 2025/02/09 18:13:14 by sabutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_push	*create_node(int nbr)
{
	t_push	*node;

	node = malloc(sizeof(t_push));
	if (!node)
		return (NULL);
	node->data = nbr;
	node->index = -1;
	node->next = NULL;
	return (node);
}

int	check_dup(int nbr, t_push *head)
{
	t_push	*temp;

	temp = head;
	while (temp)
	{
		if (nbr == temp->data)
			exit_free(head, 1);
		temp = temp->next;
	}
	return (nbr);
}

int	push_swap_atoi(const char *nbr, t_push *head)
{
	long	res;
	int		i;
	int		sign;

	res = 0;
	i = 0;
	sign = 1;
	if ((nbr[i] == '-' || nbr[i] == '+') && ft_strlen(nbr) > 1)
	{
		if (nbr[i] == '-')
			sign = -1;
		i++;
	}
	while (nbr[i])
	{
		if ('0' > nbr[i] || nbr[i] > '9')
			exit_free(head, 1);
		res = res * 10 + nbr[i] - '0';
		if ((res * sign) > INT_MAX || (res * sign) < INT_MIN)
			exit_free(head, 1);
		i++;
	}
	return (sign * res);
}

t_push	*create_stack(int argc, char **argv)
{
	int		i;
	t_push	*node;
	t_push	*head;
	t_push	*cur;

	head = NULL;
	i = 1;
	while (i < argc)
	{
		node = create_node(check_dup(push_swap_atoi(argv[i], head), head));
		if (!node)
			exit_free(head, 1);
		if (!head)
			head = node;
		else
		{
			cur = head;
			while (cur->next)
				cur = cur->next;
			cur->next = node;
		}
		i++;
	}
	return (head);
}
