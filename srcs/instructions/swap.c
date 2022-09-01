/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 12:19:22 by bchabot           #+#    #+#             */
/*   Updated: 2022/08/31 17:33:59 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	swap(t_stack *stack)
{
	t_element	*tmp;

	if (lstsize_ps(stack) < 2)
		return (-1);
	tmp = stack->head;
	stack->head = stack->head->next;
	tmp->next = stack->head->next;
	stack->head->next = tmp;
	return (0);
}

void	sa(t_stack *stack)
{
	if (swap(stack) == -1)
		return ;
	write(1, "sa\n", 3);
}

void	sb(t_stack *stack)
{
	if (swap(stack) == -1)
		return ;
	write(1, "sb\n", 3);
}

void	ss(t_stack *stack, t_stack *stackb)
{
	swap(stack);
	swap(stackb);
	write(1, "ss\n", 3);
}
