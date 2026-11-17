/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: login1 <login1@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 12:00:00 by login1            #+#    #+#             */
/*   Updated: 2026/11/07 12:00:00 by login1           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_three(t_list *a, size_t ops[RRR + 1])
{
	t_node	*max;

	if (a->size == 3)
	{
		max = find_max_node(a);
		if (max == a->head)
			rotate_ra(a, ops);
		else if (max == a->head->next)
			rotate_rra(a, ops);
	}
	if (a->size > 1 && a->head->num > a->head->next->num)
		swap_sa(a->head, a->head->next, ops);
}

void	sort_a_to_b(t_list *a, t_list *b, size_t ops[RRR + 1])
{
	t_node	*cheapest;

	assign_index(a, b);
	find_target(a, b);
	calculate_cost(a, b);
	cheapest = find_cheapest(a);
	execute_moves(a, b, cheapest, ops);
}

void	sort_b_to_a(t_list *a, t_list *b, size_t ops[RRR + 1])
{
	t_node	*cheapest;

	assign_index(a, b);
	find_target_b_to_a(b, a);
	calculate_cost_b(a, b);
	cheapest = find_cheapest(b);
	execute_moves_b(a, b, cheapest, ops);
}

void	final_rotate(t_list *a, size_t ops[RRR + 1])
{
	t_node	*min;

	assign_index(a, NULL);
	min = find_min_node(a);
	rotate_num(rotation_cost(min->index, a->size), a, 'a', ops);
}

void	complex(t_list *a, t_list *b, size_t ops[RRR + 1])
{
	if (is_sorted(a))
		return ;
	if (a->size > 3)
		push_pb(b, a, ops);
	if (a->size > 3)
		push_pb(b, a, ops);
	while (a->size > 3)
		sort_a_to_b(a, b, ops);
	sort_three(a, ops);
	while (b->size > 0)
		sort_b_to_a(a, b, ops);
	final_rotate(a, ops);
}
