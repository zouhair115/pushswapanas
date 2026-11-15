/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: login1 <login1@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 12:00:00 by login1            #+#    #+#             */
/*   Updated: 2026/11/07 12:00:00 by login1           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	swap_values(t_node *a, t_node *b)
{
	int	tmp;

	tmp = a->num;
	a->num = b->num;
	b->num = tmp;
	tmp = a->target_index;
	a->target_index = b->target_index;
	b->target_index = tmp;
}

void	swap_sa(t_node *a, t_node *b, size_t ops[RRR + 1])
{
	if (!a || !b)
		return ;
	swap_values(a, b);
	ops[SA]++;
	ft_putstr_fd(1, "sa\n");
}

void	swap_sb(t_node *a, t_node *b, size_t ops[RRR + 1])
{
	if (!a || !b)
		return ;
	swap_values(a, b);
	ops[SB]++;
	ft_putstr_fd(1, "sb\n");
}

void	swap_ss(t_list *stack_a, t_list *stack_b, size_t ops[RRR + 1])
{
	if (stack_a->size < 2 || stack_b->size < 2)
		return ;
	swap_values(stack_a->head, stack_a->head->next);
	swap_values(stack_b->head, stack_b->head->next);
	ops[SS]++;
	ft_putstr_fd(1, "ss\n");
}
