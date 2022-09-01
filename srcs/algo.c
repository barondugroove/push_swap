/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 16:01:52 by bchabot           #+#    #+#             */
/*   Updated: 2022/09/01 17:34:12 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_digits(t_stack	*stack)
{
	t_element	*tmp;
	int	buf;
	int x;
	
	tmp = stack->head;
	buf = 0;
	x = 1;
	while (tmp->next)
	{
		if (tmp->content > buf)
			buf = tmp->content;
		tmp = tmp->next;
	}
	if (tmp->content > buf)
		buf = tmp->content;
	while (buf / 10 != 0)
	{
		buf /= 10;
		x++;
	}
	return (x);
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
			
