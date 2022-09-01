/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 16:17:37 by bchabot           #+#    #+#             */
/*   Updated: 2022/08/31 17:33:40 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	rotate(t_stack *stack)
{
    t_element   *tmp;
    t_element   *tmp2;

    if (!stack->head)
        return (-1);
    tmp = stack->head;
    tmp2 = stack->head;
    stack->head = stack->head->next;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = tmp2;
    tmp2->next = NULL;
	return (0);
}

void	ra(t_stack *stack)
{
	if (rotate(stack) == -1)
		return ;
	write(1, "ra\n", 3);
}

void	rb(t_stack *stack)
{
	if (rotate(stack) == -1)
		return ;
	write(1, "rb\n", 3);
}

void	rr(t_stack *stack, t_stack *stackb)
{
	rotate(stack);
	rotate(stackb);
	write(1, "ra\n", 3);
}
