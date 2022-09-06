/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 17:18:45 by bchabot           #+#    #+#             */
/*   Updated: 2022/09/06 15:11:19 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	reverse(t_stack *stack)
{
	t_element	*tmp;
	t_element	*tmp2;

	if (lstsize_ps(stack) < 2)
		return (-1);
	tmp = stack->head;
	tmp2 = stack->head;
	while (tmp->next)
		tmp = tmp->next;
	while (tmp2->next->next)
		tmp2 = tmp2->next;
	tmp2->next = NULL;
	tmp->next = stack->head;
	stack->head = tmp;
	return (0);
}

void	rra(t_stack	*stack)
{
	if (reverse(stack) == -1)
		return ;
	write(1, "rra\n", 4);
}

void	rrb(t_stack	*stack)
{
	if (reverse(stack) == -1)
		return ;
	write(1, "rrb\n", 4);
}

void	rrr(t_stack	*stack, t_stack	*stackb)
{
	reverse(stack);
	reverse(stackb);
	write(1, "rrr\n", 4);
}
