/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 13:15:08 by bchabot           #+#    #+#             */
/*   Updated: 2022/08/10 15:54:11 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			{
				ft_printf("Duplicate numbers found, please try again.\n");
				exit (0);
			}
			j++;
		}
		i++;
		j = 1 + i;
	}
}

void check_params(char **tab, int i)
{
	int j;

	j = 0;
	while (tab[i])
	{
		while (tab[i][j])
		{
			if ((tab[i][j] < 48 || tab[i][j] > 57) && tab[i][j] != '-')
			{
				ft_printf("Wrong arguments, please try again.\n");
				exit (0);
			}
			j++;
		}
		i++;
		j = 0;
	}
}
