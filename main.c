/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: login1 <login1@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 12:00:00 by login1            #+#    #+#             */
/*   Updated: 2026/11/07 12:00:00 by login1           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	a;
	t_list	b;
	int		flags[BENCH_IDX + 1];

	if (ac < 2)
		return (0);
	ft_bzero(&a, sizeof(t_list));
	ft_bzero(&b, sizeof(t_list));
	ft_bzero(flags, sizeof(flags));
	if (parse_input(ac, av, &a, flags) < 0)
	{
		ft_lstclear(&a);
		ft_putstr_fd(2, "Error\n");
		return (1);
	}
	if (a.size > 0)
		print_algorithm(&a, &b, flags);
	ft_lstclear(&a);
	ft_lstclear(&b);
	return (0);
}
