/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:03:59 by bchabot           #+#    #+#             */
/*   Updated: 2022/09/01 17:54:47 by bchabot          ###   ########.fr       */
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

void	push_swap(t_stack *a, t_stack *b)
{
	print_stack(a, 'A');	
	print_stack(b, 'B');	
	sorting_big(a, b);
	print_stack(a, 'A');	
	print_stack(b, 'B');	
	
	/*while (a->head)
	{
		node = a->head;
		a->head = a->head->next;
		free(node);
		node = NULL;
		i++;
	}
	free(a);
	free(b);*/
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = lstnew_ps();
	b = lstnew_ps();
	parse_data(argv, a);
	if (argc < 2)
		print_error();
	else
		push_swap(a, b);
	return (0);
}
