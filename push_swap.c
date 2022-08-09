/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:03:59 by bchabot           #+#    #+#             */
/*   Updated: 2022/08/09 12:48:11 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_swap(int argc, char **argv)
{
	t_element *a;
	t_element *b;
	void *c;
	int i;
	int x;

	i = 1;
	(void)b;
	a = malloc(sizeof(t_element));
	x = 0;
	while (i < argc)
	{
		x = ft_atoi(argv[i]);
		c = lstnew_ps(x);
		lstadd_back_ps(&a, c); 
		i++;
	}
	x = 0;
	/*
	while (x < i)
	{
		ft_printf("%d\n", a->content);
		a = a->next;
		x++;
	}
	*/
}

int main(int argc, char **argv)
{
	parse_data(argc, argv);
	if (argc == 1)
	{
		ft_printf("Missing arguments.\n");
		return (1);
	}
	else
		push_swap(argc, argv);
	return (0);
}
