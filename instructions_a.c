/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 12:19:22 by bchabot           #+#    #+#             */
/*   Updated: 2022/08/30 18:07:50 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack)
{
	t_element *tmp;

	if (!stack->head || !stack->head->next)
		return ;
	tmp = stack->head;
	stack->head = stack->head->next;
	tmp->next = stack->head->next;
	stack->head->next = tmp;
	write(1, "sa\n", 3);
}

void	ra(t_stack *stack)
{
	t_element *tmp;
	t_element *tmp2;
	if (!stack->head || !stack->head->next)
		return ;
	tmp2 = stack->head;
	stack->head = stack->head->next;
	tmp2->next = NULL;
	tmp = stack->head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = tmp2;
	write(1, "ra\n", 3);
}

void	rra(t_stack *stack)
{
	t_element *tmp;
	t_element *tmp2;

	if (!stack->head || !stack->head->next)
		return ;
	tmp = stack->head;
	tmp2 = stack->head;
	while (tmp->next)
		tmp = tmp->next;
	while (tmp2->next->next)
		tmp2 = tmp2->next;
	tmp->next = stack->head;
	stack->head = tmp;
	tmp2->next = NULL;
	write(1, "rra\n", 4);
}

void	pa(t_stack *stack, t_stack *stackb)
{
	t_element *tmp;

	if (!stack->head || !stack->head->next)
		return ;
	if (!stackb->head || !stackb->head->next)
		return ;	
	tmp = stackb->head;
	tmp->next = stack->head;
	stack->head = tmp;
	write(1, "pa\n", 3);
}
