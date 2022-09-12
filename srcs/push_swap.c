/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:03:59 by bchabot           #+#    #+#             */
/*   Updated: 2022/09/07 13:50:21 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(t_stack *stack)
{
	t_element	*tmp;

	while (stack->head)
	{
		tmp = stack->head;
		stack->head = stack->head->next;
		free(tmp);
		tmp = NULL;
	}
	free(stack);
}

void	push_swap(t_stack *a)
{
	t_stack	*b;

	b = lstnew_ps();
	if (a->nb_max == 3 || a->nb_max == 2)
		sorting_three(a);
	else if (a->nb_max == 4)
		sorting_four(a, b);
	else if (a->nb_max == 5)
		sorting_five(a, b);
	else
		sorting_big(a, b);
	free_stack(b);
}

int	main(int argc, char **argv)
{
	t_stack	*a;

	if (argc < 2)
		print_error();
	a = lstnew_ps();
	if (parse_data(argv, a))
	{
		free_stack(a);
		print_error();
	}
	push_swap(a);
	free_stack(a);
	return (0);
}
