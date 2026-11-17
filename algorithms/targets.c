/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   targets.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: login1 <login1@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 12:00:00 by login1            #+#    #+#             */
/*   Updated: 2026/11/07 12:00:00 by login1           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
/*return the best cost of element*/
t_node	*find_cheapest(t_list *list)
{
	t_node	*cur;
	t_node	*best;

	best = list->head;
	cur = list->head;
	while (cur)
	{
		if (cur->total_cost < best->total_cost)
			best = cur;
		cur = cur->next;
	}
	return (best);
}

t_node	*find_next_bigger(t_list *a, int num)
{
	t_node	*cur;
	t_node	*best;

	best = NULL;
	cur = a->head;
	while (cur)
	{
		if (cur->num > num && (!best || cur->num < best->num))
			best = cur;
		cur = cur->next;
	}
	return (best);
}

t_node	*find_next_smaller(t_list *b, int num)
{
	t_node	*cur;
	t_node	*best;

	best = NULL;
	cur = b->head;
	while (cur)
	{
		if (cur->num < num && (!best || cur->num > best->num))
			best = cur;
		cur = cur->next;
	}
	return (best);
}
/*tat9aleb fi asgaar ra9m fi stack*/
void	find_target(t_list *a, t_list *b)
{
	t_node	*cur;
	t_node	*target;

	cur = a->head;
	while (cur)
	{
		target = find_next_smaller(b, cur->num);
		if (!target)
			target = find_max_node(b);
		cur->target_index = target->index;
		cur = cur->next;
	}
}

void	find_target_b_to_a(t_list *b, t_list *a)
{
	t_node	*cur;
	t_node	*target;

	cur = b->head;
	while (cur)
	{
		target = find_next_bigger(a, cur->num);
		if (!target)
			target = find_min_node(a);
		cur->target_index = target->index;
		cur = cur->next;
	}
}
