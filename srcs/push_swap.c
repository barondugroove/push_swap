/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:03:59 by bchabot           #+#    #+#             */
/*   Updated: 2022/09/05 18:33:00 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack, char name)
{
	t_element	*tmp;

	tmp = stack->head;
	ft_printf("------------\n");
	ft_printf("| STACK  %c |\n", name);
	ft_printf("------------\n");
	while (tmp)
	{
		ft_printf("|    %d     |\n", tmp->content);
		tmp = tmp->next;
	}
	ft_printf("------------\n");
}

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

void	push_swap(t_stack *a, t_stack *b)
{
	print_stack(a, 'A');
	sorting_big(a, b);
	print_stack(a, 'A');
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		print_error();
	a = lstnew_ps();
	if (parse_data(argv, a))
	{
		free_stack(a);
		print_error();
	}
	b = lstnew_ps();
	push_swap(a, b);
	if (a->head)
		free_stack(a);
	if (b->head)
		free_stack(b);
	return (0);
}
