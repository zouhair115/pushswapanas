/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: login1 <login1@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 12:00:00 by login1            #+#    #+#             */
/*   Updated: 2026/11/07 12:00:00 by login1           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_ra(t_list *stack_a, size_t ops[RRR + 1])
{
	if (stack_a->size < 2)
		return ;
	stack_rotate(stack_a);
	ops[RA]++;
	ft_putstr_fd(1, "ra\n");
}

void	rotate_rb(t_list *stack_b, size_t ops[RRR + 1])
{
	if (stack_b->size < 2)
		return ;
	stack_rotate(stack_b);
	ops[RB]++;
	ft_putstr_fd(1, "rb\n");
}

void	rotate_rr(t_list *stack_a, t_list *stack_b, size_t ops[RRR + 1])
{
	if (stack_a->size < 2 || stack_b->size < 2)
		return ;
	stack_rotate(stack_a);
	stack_rotate(stack_b);
	ops[RR]++;
	ft_putstr_fd(1, "rr\n");
}
