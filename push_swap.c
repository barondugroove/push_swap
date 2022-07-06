/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:03:59 by bchabot           #+#    #+#             */
/*   Updated: 2022/07/06 16:59:19 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_push_swap(int argc, char **argv)
{
	t_list **a;
	t_list *b;
	void *c;
	int i;

	i = 1;
	(void)b;
	a = malloc(sizeof(t_list));
	while (i <= argc)
	{
		c = ft_lstnew(argv[i]);
		ft_lstadd_back(a, c); 
		i++;
	}
	i = 0;
	while (a != NULL)
	{
		ft_printf("%d", a[0]->content);
		a[0] = a[0]->next;
		i++;
	}
}

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		ft_printf("Missing arguments.\n");
		return (1);
	}
	else
		ft_push_swap(argc, argv);
	return (0);
}
