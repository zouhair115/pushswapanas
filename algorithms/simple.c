/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: login1 <login1@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 12:00:00 by login1            #+#    #+#             */
/*   Updated: 2026/11/07 12:00:00 by login1           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	simple(t_list *a, t_list *b, size_t ops[RRR + 1])
{
	t_node	*min;

	while (a->size > 3 && !is_sorted(a))
	{
		assign_index(a, b);
		min = find_min_node(a);
		rotate_num(rotation_cost(min->index, a->size), a, 'a', ops);
		push_pb(b, a, ops);
	}
	sort_three(a, ops);
	while (b->size > 0)
		push_pa(b, a, ops);
}
