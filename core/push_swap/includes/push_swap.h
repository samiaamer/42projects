/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabutale <sabutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:24:30 by sabutale          #+#    #+#             */
/*   Updated: 2025/02/09 17:32:26 by sabutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"
# include <limits.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_push
{
	int				data;
	int				index;
	struct s_push	*next;
}					t_push;

t_push				*create_stack(int argc, char **argv);
t_push				*create_node(int nbr);
t_push				*find_smallest_undindexed(t_push *head);
t_push				*find_smallest(t_push *head);
int					check_dup(int nbr, t_push *head);
int					push_swap_atoi(const char *nbr, t_push *head);
int					main(int argc, char **argv);
int					is_sorted(t_push *head);
int					stack_len(t_push *head);
int					max_index(t_push *head);
int					num_iter(int max);
void				radix_sort(t_push **stack_a, t_push **stack_b,
						int num_iteration);
void				swap(t_push **head, char c);
void				ss(t_push **stack_a, t_push **stack_b);
void				pa(t_push **stack_a, t_push **stack_b);
void				pb(t_push **stack_a, t_push **stack_b);
void				rotate(t_push **head, char c);
void				rr(t_push **stack_a, t_push **stack_b);
void				rev_rot(t_push **head, char c);
void				rrr(t_push **stack_a, t_push **stack_b);
void				sort_three(t_push **head);
void				sort_four(t_push **stack_a, t_push **stack_b);
void				sort_five(t_push **stack_a, t_push **stack_b);
void				exit_free(t_push *head, int flag);
void				print_list(t_push *head);
void				indexing(t_push *head);
void				free_stack(t_push *head);

#endif
