/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 16:01:52 by bchabot           #+#    #+#             */
/*   Updated: 2022/09/07 14:03:16 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_element	*tmp;

	tmp = stack->head;
	while (tmp->next)
	{
		if (tmp->index >= tmp->next->index)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	sorting_three(t_stack *stack)
{
	t_element	*tmp;

	tmp = stack->head;
	while (!is_sorted(stack))
	{
		if (tmp->index == 1 && tmp->next->index == 0)
			sa(stack);
		else if (tmp->index == 2 && tmp->next->index == 1)
		{
			sa(stack);
			rra(stack);
		}
		else if (tmp->index == 2 && tmp->next->index == 0)
			ra(stack);
		else if (tmp->index == 1 && tmp->next->index == 2)
			rra(stack);
		else if (tmp->index == 0 && tmp->next->index == 2)
		{
			sa(stack);
			ra(stack);
		}
	}
}

void	sorting_five(t_stack *stack, t_stack *stackb)
{
	if (is_sorted(stack))
		return ;
	while (lstsize_ps(stack) > 3)
	{
		if (stack->head->index == 0 || stack->head->index == 1)
			pb(stack, stackb);
		else
			ra(stack);
	}
	reset_index(stack);
	get_index(stack);
	sorting_three(stack);
	pa(stackb, stack);
	pa(stackb, stack);
	if (stack->head->index > stack->head->next->index)
		sa(stack);
}

void	sorting_four(t_stack *stack, t_stack *stackb)
{
	if (is_sorted(stack))
		return ;
	while (lstsize_ps(stack) > 3)
	{
		if (stack->head->index == 0)
			pb(stack, stackb);
		else
			ra(stack);
	}
	reset_index(stack);
	get_index(stack);
	sorting_three(stack);
	pa(stackb, stack);
}

void	sorting_big(t_stack	*stack, t_stack	*stackb)
{
	int			x;
	int			i;
	int			stack_len;

	x = 0;
	while (x <= 10)
	{
		i = 0;
		stack_len = nb_max(stack);
		if (is_sorted(stack))
			return ;
		while (i < stack_len)
		{
			if ((stack->head->index >> x) & 1)
				ra(stack);
			else
				pb(stack, stackb);
			i++;
		}	
		x++;
		while (stackb->head)
			pa(stackb, stack);
	}
}
