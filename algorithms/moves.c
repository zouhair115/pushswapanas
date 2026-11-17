/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: login1 <login1@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 12:00:00 by login1            #+#    #+#             */
/*   Updated: 2026/11/07 12:00:00 by login1           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	execute_rotations(t_list *a, t_list *b, t_node *cheapest,
			size_t ops[RRR + 1])
{
	while (cheapest->cost_a > 0 && cheapest->cost_b > 0)
	{
		rotate_rr(a, b, ops);
		cheapest->cost_a--;
		cheapest->cost_b--;
	}
	while (cheapest->cost_a < 0 && cheapest->cost_b < 0)
	{
		rotate_rrr(a, b, ops);
		cheapest->cost_a++;
		cheapest->cost_b++;
	}
}

void	execute_moves(t_list *a, t_list *b, t_node *cheapest,
			size_t ops[RRR + 1])
{
	execute_rotations(a, b, cheapest, ops);
	rotate_num(cheapest->cost_a, a, 'a', ops);
	rotate_num(cheapest->cost_b, b, 'b', ops);
	push_pb(b, a, ops);
}

void	execute_moves_b(t_list *a, t_list *b, t_node *cheapest,
			size_t ops[RRR + 1])
{
	execute_rotations(a, b, cheapest, ops);
	rotate_num(cheapest->cost_a, a, 'a', ops);
	rotate_num(cheapest->cost_b, b, 'b', ops);
	push_pa(b, a, ops);
}
