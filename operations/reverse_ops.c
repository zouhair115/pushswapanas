/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_ops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: login1 <login1@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 12:00:00 by login1            #+#    #+#             */
/*   Updated: 2026/11/07 12:00:00 by login1           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_rra(t_list *stack_a, size_t ops[RRR + 1])
{
	if (stack_a->size < 2)
		return ;
	stack_rrotate(stack_a);
	ops[RRA]++;
	ft_putstr_fd(1, "rra\n");
}

void	rotate_rrb(t_list *stack_b, size_t ops[RRR + 1])
{
	if (stack_b->size < 2)
		return ;
	stack_rrotate(stack_b);
	ops[RRB]++;
	ft_putstr_fd(1, "rrb\n");
}

void	rotate_rrr(t_list *stack_a, t_list *stack_b, size_t ops[RRR + 1])
{
	if (stack_a->size < 2 || stack_b->size < 2)
		return ;
	stack_rrotate(stack_a);
	stack_rrotate(stack_b);
	ops[RRR]++;
	ft_putstr_fd(1, "rrr\n");
}
