/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: login1 <login1@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 12:00:00 by login1            #+#    #+#             */
/*   Updated: 2026/11/07 12:00:00 by login1           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static float	compute_disorder(t_list *a)
{
	t_node	*i;
	t_node	*j;
	long	mistakes;
	long	pairs;

	mistakes = 0;
	pairs = 0;
	i = a->head;
	while (i)
	{
		j = i->next;
		while (j)
		{
			pairs++;
			if (i->num > j->num)
				mistakes++;
			j = j->next;
		}
		i = i->next;
	}
	if (pairs == 0)
		return (0.0f);
	return ((float)mistakes / (float)pairs);
}

int	pick_strategy(int flags[BENCH_IDX + 1], float disorder)
{
	if (flags[SIMPLE_IDX])
		return (SIMPLE_IDX);
	if (flags[MEDIUM_IDX])
		return (MEDIUM_IDX);
	if (flags[COMPLEX_IDX])
		return (COMPLEX_IDX);
	if (disorder < 0.2f)
		return (SIMPLE_IDX);
	if (disorder < 0.5f)
		return (MEDIUM_IDX);
	return (COMPLEX_IDX);
}

void	print_algorithm(t_list *a, t_list *b, int flags[BENCH_IDX + 1])
{
	size_t	ops[RRR + 1];
	float	disorder;
	int		algo;

	ft_bzero(ops, sizeof(ops));
	disorder = compute_disorder(a);
	algo = pick_strategy(flags, disorder);
	if (algo == SIMPLE_IDX)
		simple(a, b, ops);
	else if (algo == MEDIUM_IDX)
		medium(a, b, ops);
	else
		complex(a, b, ops);
	if (flags[BENCH_IDX])
		print_bench(flags, disorder, ops);
}
