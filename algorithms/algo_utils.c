/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: login1 <login1@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 12:00:00 by login1            #+#    #+#             */
/*   Updated: 2026/11/07 12:00:00 by login1           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_sorted(t_list *a)
{
	t_node	*cur;

	cur = a->head;
	while (cur && cur->next)
	{
		if (cur->num > cur->next->num)
			return (0);
		cur = cur->next;
	}
	return (1);
}

t_node	*find_min_node(t_list *a)
{
	t_node	*cur;
	t_node	*min;

	min = a->head;
	cur = a->head;
	while (cur)
	{
		if (cur->num < min->num)
			min = cur;
		cur = cur->next;
	}
	return (min);
}

t_node	*find_max_node(t_list *a)
{
	t_node	*cur;
	t_node	*max;

	max = a->head;
	cur = a->head;
	while (cur)
	{
		if (cur->num > max->num)
			max = cur;
		cur = cur->next;
	}
	return (max);
}

int	rotation_cost(int pos, int size)
{
	if (pos <= size / 2)
		return (pos);
	return (pos - size);
}

void	rotate_num(int count, t_list *stack, char which, size_t ops[RRR + 1])
{
	while (count > 0)
	{
		if (which == 'a')
			rotate_ra(stack, ops);
		else
			rotate_rb(stack, ops);
		count--;
	}
	while (count < 0)
	{
		if (which == 'a')
			rotate_rra(stack, ops);
		else
			rotate_rrb(stack, ops);
		count++;
	}
}
