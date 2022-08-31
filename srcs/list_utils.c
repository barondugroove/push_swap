/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 15:56:52 by bchabot           #+#    #+#             */
/*   Updated: 2022/08/31 17:11:11 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*lstnew_ps(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->head = NULL;
	stack->nb_max = 0;
	return (stack);
}

t_element	*lstnew_element(int content)
{
	t_element	*node;

	node = malloc(sizeof(t_element));
	if (!node)
		return (NULL);
	node->next = NULL;
	node->content = content;
	node->index = 0;
	return (node);
}

void	lstadd_back_ps(t_stack *stack, t_element *node)
{
	t_element	*tmp;

	if (stack->head == NULL)
	{
		stack->head = node;
		return ;
	}
	tmp = stack->head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
}

int	lstsize_ps(t_stack *stack)
{
	t_element	*tmp;
	int	i;

	i = 0;
	tmp = stack->head;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
