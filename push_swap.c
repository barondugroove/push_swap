/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:03:59 by bchabot           #+#    #+#             */
/*   Updated: 2022/08/29 19:33:15 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(int *tableau, t_stack *a)
{
	t_element *node;
	int i;

	i = 0;
	search_duplicate(tableau, a->nb_max);
	while (i < a->nb_max)
	{
		node = lstnew_element(tableau[i]);
		lstadd_front_ps(a, node); 
		i++;
	}
	a->tail = node;
	ft_printf("----------------------\n");
	ft_printf("| STACK A || STACK B |\n");
	ft_printf("----------------------\n");
	while (i--)
	{
		ft_printf("|    %d    ||         |\n", node->content);
		node = node->next;
	}
	ft_printf("----------------------\n");
	while (a->head)
	{
		node = a->head;
		a->head = a->head->next;
		free(node);
		node = NULL;
	}
}

int main(int argc, char **argv)
{
	int		*tableau;
	t_stack	*a;

	a = lstnew_ps();
	tableau = parse_data(argc, argv, a);
	if (argc < 2)
		print_error();
	else
		push_swap(tableau, a);
	free(a);
	free(tableau);
	return (0);
}
