/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: login1 <login1@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 12:00:00 by login1            #+#    #+#             */
/*   Updated: 2026/11/07 12:00:00 by login1           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_pa(t_list *stack_b, t_list *stack_a, size_t ops[RRR + 1])
{
	if (stack_b->size == 0)
		return ;
	stack_push(stack_a, stack_pop(stack_b));
	ops[PA]++;
	ft_putstr_fd(1, "pa\n");
}

void	push_pb(t_list *stack_b, t_list *stack_a, size_t ops[RRR + 1])
{
	if (stack_a->size == 0)
		return ;
	stack_push(stack_b, stack_pop(stack_a));
	ops[PB]++;
	ft_putstr_fd(1, "pb\n");
}
