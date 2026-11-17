/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: login1 <login1@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 12:00:00 by login1            #+#    #+#             */
/*   Updated: 2026/11/07 12:00:00 by login1           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	set_positions(t_list *lst)
{
	t_node	*cur;
	int		i;

	if (!lst)
		return ;
	cur = lst->head;
	i = 0;
	while (cur)
	{
		cur->index = i;
		i++;
		cur = cur->next;
	}
}

static int	total_of(int ca, int cb)
{
	if ((ca >= 0 && cb >= 0) || (ca <= 0 && cb <= 0))
		return (ft_max(ft_abs(ca), ft_abs(cb)));
	return (ft_abs(ca) + ft_abs(cb));
}

void	assign_index(t_list *a, t_list *b)
{
	set_positions(a);
	set_positions(b);
}

void	calculate_cost(t_list *a, t_list *b)
{
	t_node	*cur;

	cur = a->head;
	while (cur)
	{
		cur->cost_a = rotation_cost(cur->index, a->size);
		cur->cost_b = rotation_cost(cur->target_index, b->size);
		cur->total_cost = total_of(cur->cost_a, cur->cost_b);
		cur = cur->next;
	}
}

void	calculate_cost_b(t_list *a, t_list *b)
{
	t_node	*cur;

	cur = b->head;
	while (cur)
	{
		cur->cost_b = rotation_cost(cur->index, b->size);
		cur->cost_a = rotation_cost(cur->target_index, a->size);
		cur->total_cost = total_of(cur->cost_a, cur->cost_b);
		cur = cur->next;
	}
}
