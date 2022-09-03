/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 16:01:52 by bchabot           #+#    #+#             */
/*   Updated: 2022/09/03 20:57:36 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*void	add_instruction(t_stack *t_sort *insts, char *str)
{
	insts = lstnew_instruction(str);
	if (!!insts->head)
		insts->head = insts;
	lstadd_back_ps((t_stack *)insts, insts);
	while (insts->next)
		ft_printf("%s\n", insts->instruction);
}
*/	

int	is_sorted(t_stack *stack)
{
	t_element	*tmp;

	tmp = stack->head;
	while (tmp->next)
	{
		if (tmp->index >= tmp->next->index)
			return (1);
		tmp = tmp->next;
	}
	return (0);
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
		if (!is_sorted(stack))
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
