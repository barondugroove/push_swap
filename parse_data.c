/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 13:51:21 by bchabot           #+#    #+#             */
/*   Updated: 2022/08/16 14:05:34 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int *parse_data(int argc, char **argv, t_element *a)
{
	int i;
	int x;
	char **tab;
	int	*tableau;

	i = 1;
	x = 0;
	tableau = malloc(sizeof(int) * argc);
	if (argc == 2)
	{
		i = 0;
		tab = ft_split(argv[1], ' ');
		check_params(tab, i);
		while (tab[i])
		{
			tableau[i] = ft_atoi(tab[i]);
			i++;
		}
		a->nb_max = i;
	}
	else
	{
		while (i < argc)
		{
			check_params(argv, 1);
			tableau[x] = ft_atoi(argv[i]);
			i++;
			x++;
		}
		a->nb_max = x;
	}
	return (tableau);
}
