/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: login1 <login1@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 12:00:00 by login1            #+#    #+#             */
/*   Updated: 2026/11/07 12:00:00 by login1           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

/* tata5od string twal flag checkez m3a flag medifini fil programme twalna*/
static int	flag_index(const char *s)
{
	if (!ft_strcmp(s, SIMPLE_FLAG))
		return (SIMPLE_IDX);
	if (!ft_strcmp(s, MEDIUM_FLAG))
		return (MEDIUM_IDX);
	if (!ft_strcmp(s, COMPLEX_FLAG))
		return (COMPLEX_IDX);
	if (!ft_strcmp(s, ADAPTIVE_FLAG))
		return (ADAPTIVE_IDX);
	if (!ft_strcmp(s, BENCH_FLAG))
		return (BENCH_IDX);
	return (-1);
}

/*vérifier wach tactiver le flag*/
static int	parse_flag(const char *s, int flags[BENCH_IDX + 1])
{
	int	idx;
	int	i;

	idx = flag_index(s);
	if (idx < 0)
		return (-1);
	i = 0;
	while (idx != BENCH_IDX && i < BENCH_IDX)
	{
		if (flags[i] && i != idx)
			return (-1);
		i++;
	}
	flags[idx] = 1;
	return (0);
}

/* chechez overflow ola non valid input and duplicate aoute dd_back */
static int	add_number(t_list *a, const char *s)
{
	int		num;
	t_node	*cur;
	t_node	*node;

	if (!is_valid_arg(s))
		return (-1);
	num = ft_atoi(s);
	cur = a->head;
	while (cur)
	{
		if (cur->num == num)
			return (-1);
		cur = cur->next;
	}
	node = ft_lstnew(num);
	if (!node)
		return (-1);
	ft_lstadd_back(a, node);
	return (0);
}

/*decouper une chaîne de caractères par 'espace' et traiter chaque flague a*/
static int	add_arg(t_list *a, const char *arg)
{
	char	**av;
	int		i;

	av = ft_split(arg, ' ');
	if (!av || !av[0])
	{
		ft_free_split(av);
		return (-1);
	}
	i = 0;
	while (av[i])
	{
		if (add_number(a, av[i]) < 0)
		{
			ft_free_split(av);
			return (-1);
		}
		i++;
	}
	ft_free_split(av);
	return (0);
}

/* ta dour 3la arguments kamlin min 1 tal (ac - 1) */
int	parse_input(int ac, char **av, t_list *a, int flags[BENCH_IDX + 1])
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (av[i][0] == '-' && av[i][1] == '-')
		{
			if (parse_flag(av[i], flags) < 0)
				return (-1);
		}
		else if (add_arg(a, av[i]) < 0)
			return (-1);
		i++;
	}
	return (0);
}
