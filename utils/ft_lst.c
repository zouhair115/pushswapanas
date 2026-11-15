/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: login1 <login1@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 12:00:00 by login1            #+#    #+#             */
/*   Updated: 2026/11/07 12:00:00 by login1           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*ft_lstnew(int num)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	ft_bzero(node, sizeof(t_node));
	node->num = num;
	return (node);
}

void	ft_lstadd_back(t_list *list, t_node *node)
{
	node->next = NULL;
	node->prev = list->tail;
	if (list->tail)
		list->tail->next = node;
	else
		list->head = node;
	list->tail = node;
	list->size++;
}

void	ft_lstclear(t_list *list)
{
	t_node	*cur;
	t_node	*next;

	cur = list->head;
	while (cur)
	{
		next = cur->next;
		free(cur);
		cur = next;
	}
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
}
