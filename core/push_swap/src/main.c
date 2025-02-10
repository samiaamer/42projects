/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabutale <sabutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:54:32 by sabutale          #+#    #+#             */
/*   Updated: 2025/02/09 17:31:38 by sabutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
<<<<<<< HEAD
=======
/*
void	print_list(t_push *head)
{
	t_push	*current;

	current = head;
	while (current != NULL)
	{
		printf("Data: %d, Index: %d\n", current->data, current->index);
		current = current->next;
	}
}*/
>>>>>>> 500be3a0338fac03a7b6a64086f2b42f75d903c6

int	main(int argc, char **argv)
{
	t_push	*stack_a;
	t_push	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		exit(0);
	stack_a = create_stack(argc, argv);
	indexing(stack_a);
	if (is_sorted(stack_a))
		exit_free(stack_a, 0);
	if (stack_len(stack_a) == 2)
		swap(&stack_a, 'a');
	else if (stack_len(stack_a) == 3)
		sort_three(&stack_a);
	else if (stack_len(stack_a) == 4)
		sort_four(&stack_a, &stack_b);
	else if (stack_len(stack_a) == 5)
		sort_five(&stack_a, &stack_b);
	else
		radix_sort(&stack_a, &stack_b, num_iter(max_index(stack_a)));
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
