/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 13:15:08 by bchabot           #+#    #+#             */
/*   Updated: 2022/08/31 15:50:44 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(void)
{
	write(2, "Error\n", 6);
	exit (0);
}

void	search_duplicate(t_stack *stack)
{
	t_element	*tmp;
	t_element	*tmp2;

	tmp = stack->head;
	tmp2 = stack->head->next;
	while (tmp->next)
	{
		while (tmp2)
		{
			if (tmp2->content == tmp->content)
				print_error();
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
		tmp2 = tmp->next;
	}
}

void	check_params(char *tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if ((tab[i] == '-' || tab[i] == '+') && (tab[i + 1] < 48 || tab[i + 1] > 57))
			print_error();
		else if ((tab[i] < 48 || tab[i] > 57) && (tab[i] != '-' && tab[i] != '+') && tab[i] != ' ')
			print_error();
		else if ((tab[i] >= 48 && tab[i] <= 57) && (tab[i + 1] == '-' || tab[i + 1] == '+'))
			print_error();
		else if (tab[i] == ' ' && (tab[i + 1] < 48 || tab[i + 1] > 57))
			print_error();
		else
			i++;
	}
}
