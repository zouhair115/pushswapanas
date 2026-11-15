/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: login1 <login1@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 12:00:00 by login1            #+#    #+#             */
/*   Updated: 2026/11/07 12:00:00 by login1           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_stack_size(t_list *a)
{
	return (a->size);
}

t_node	*stack_pop(t_list *l)
{
	t_node	*n;

	n = l->head;
	if (!n)
		return (NULL);
	l->head = n->next;
	if (l->head)
		l->head->prev = NULL;
	else
		l->tail = NULL;
	n->next = NULL;
	n->prev = NULL;
	l->size--;
	return (n);
}

void	stack_push(t_list *l, t_node *n)
{
	n->prev = NULL;
	n->next = l->head;
	if (l->head)
		l->head->prev = n;
	else
		l->tail = n;
	l->head = n;
	l->size++;
}

void	stack_rotate(t_list *l)
{
	t_node	*n;

	if (l->size < 2)
		return ;
	n = stack_pop(l);
	n->prev = l->tail;
	l->tail->next = n;
	l->tail = n;
	l->size++;
}

void	stack_rrotate(t_list *l)
{
	t_node	*n;

	if (l->size < 2)
		return ;
	n = l->tail;
	l->tail = n->prev;
	l->tail->next = NULL;
	l->size--;
	stack_push(l, n);
}
