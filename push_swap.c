/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:03:59 by bchabot           #+#    #+#             */
/*   Updated: 2022/08/24 16:45:54 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_swap(int *tableau, t_element *a)
{
	t_element *b;
	int i;

	i = 1;
	a->content = tableau[0];
	search_duplicate(tableau, a->nb_max);
	while (i <= a->nb_max)
	{
		b = lstnew_ps(tableau[i]);
		lstadd_back_ps(&a, b); 
		i++;
	}
	ft_printf("----------------------\n", a->content);
	ft_printf("| STACK A || STACK B |\n", a->content);
	ft_printf("----------------------\n", a->content);
	while (a->next)
	{
		ft_printf("|    %d    ||         |\n", a->content);
		a = a->next;
	}
	ft_printf("----------------------\n", a->content);
}

int main(int argc, char **argv)
{
	int	*tableau;
	t_element *a;

	a = lstnew_ps(0);
	tableau = parse_data(argc, argv, a);
	if (argc == 1)
	{
		ft_printf("Missing arguments.\n");
		return (1);
	}
	else
		push_swap(tableau, a);
	free(a);
	free(tableau);
	return (0);
}
