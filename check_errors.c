/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 13:15:08 by bchabot           #+#    #+#             */
/*   Updated: 2022/08/16 18:10:17 by bchabot          ###   ########.fr       */
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
				write(2, "Error\n", 6);
				exit (0);
			}
			j++;
		}
		i++;
		j = 1 + i;
	}
}

void check_params(char *argv)
{
	int i;

	i = 0;
	while (argv[i])
	{
		if ((argv[i] < 48 || argv[i] > 57) || (argv[i] == '-' && (argv[i + 1] >= 48 || argv[i + 1] <= 57)))
		{
			write(2, "Error\n", 6);
			exit (0);
		}
		i++;
	}
}
