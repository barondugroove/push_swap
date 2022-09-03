/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:03:59 by bchabot           #+#    #+#             */
/*   Updated: 2022/09/03 22:22:35 by bchabot          ###   ########.fr       */
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
//	print_stack(a, 'A');	
//	print_stack(b, 'B');	
	sorting_big(a, b);
//	print_stack(a, 'A');	
//	print_stack(b, 'B');	
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = lstnew_ps();
	b = lstnew_ps();
	if (parse_data(argv, a))
	{
		ft_free(a);
		ft_free(b);
		print_error();
	}
	if (argc < 2)
	{	
		free(a);
		free(b);
		print_error();
	}
	else
		push_swap(a, b);
	ft_free(a);
	ft_free(b);
	return (0);
}
