/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 13:15:08 by bchabot           #+#    #+#             */
/*   Updated: 2022/08/24 16:34:45 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error()
{
	write(2, "Error\n", 6);
	exit (0);
}
void search_duplicate(int *tab, int nb_max)
{
	int i;
	int j;

	i = 0;
	j = 1;
	while (i < nb_max)
	{
		while (j < nb_max)
		{
			if (tab[i] == tab[j])
				print_error();
			j++;
		}
		i++;
		j = 1 + i;
	}
}

void check_params(char *tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if ((tab[i] == '-' || tab[i] == '+') && (tab[i + 1] < 48 || tab[i + 1] > 57))
			print_error();
		else if ((tab[i] < 48 || tab[i] > 57) && (tab[i] != '-' && tab[i] != '+'))
			print_error();
		else if ((tab[i] >= 48 && tab[i] <= 57) && (tab[i + 1] == '-' || tab[i + 1] == '+'))
			print_error();
		else
			i++;
	}
}
