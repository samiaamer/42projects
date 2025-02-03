/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabutale <sabutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:54:32 by sabutale          #+#    #+#             */
/*   Updated: 2025/02/03 19:53:02 by sabutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    exit_free(t_push *head, int flag)
{
    t_push  *temp;
    
    if (flag)
        ft_putstr_fd("Error\n", 2);
    if (head)
    {
        while (head)
        {
            temp = head;
            head = head->next;
            free(temp);
        }
    }
    exit(flag);
}

void    print_list(t_push *head)
{
    t_push *current = head;

    while (current != NULL)
    {
        printf("Data: %d, Index: %d\n", current->data , current->index);
        current = current->next;
    }
}

int     main(int argc, char **argv)
{
    t_push  *stack_a;
    t_push  *stack_b;

    stack_a = NULL;
    stack_b = NULL;
    if (argc < 2)
        exit(0);
    stack_a = create_stack(argc, argv);
    print_list(stack_a);
    indexing (stack_a);
    print_list(stack_a);
    if (is_sorted (stack_a))
         exit_free (stack_a, 0);
    // (void)stack_a;
    (void)stack_b;
    return (0);
}
