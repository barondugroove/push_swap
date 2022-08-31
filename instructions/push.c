/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 17:34:51 by bchabot           #+#    #+#             */
/*   Updated: 2022/08/31 17:53:10 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	push(t_stack *stack_snd, t_stack *stack_rcv)
{
	t_element	*tmp;

	if (!stack_snd->head)
		return (-1);
	tmp = stack_snd->head;
	if (!stack_rcv->head)
	{
		tmp->next = NULL;
		stack_rcv->head = tmp;
		stack_snd->head = stack_snd->head->next;
	}
	else
	{
		tmp->next = stack_rcv->head;
		stack_snd->head = stack_snd->head->next;
		stack_rcv->head = tmp;
	}
	return (0);
}

void	pa(t_stack	*stack_snd, t_stack	*stack_rcv)
{
	if (push(stack_snd, stack_rcv) == -1)
		return ;
	write(1, "pa\n", 3);
}

void	pb(t_stack	*stack_snd, t_stack	*stack_rcv)
{
	if (push(stack_snd, stack_rcv) == -1)
		return ;
	write(1, "pb\n", 3);
}
