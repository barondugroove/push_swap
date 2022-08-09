/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 13:51:21 by bchabot           #+#    #+#             */
/*   Updated: 2022/08/09 13:53:08 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void parse_data(int argc, char **argv)
{
	char **tab;
	int	*tableau;
	int i;
	int x;

	i = 0;
	x = 0;
	tableau = malloc(sizeof(int) * argc);
	if (argc == 2)
	{
		tab = ft_split(argv[1], ' ');
		check_params_char(tab);
		while (tab[i])
		{
			tableau[i] = ft_atoi(tab[i]);
			i++;
			x++;
		}
	}
	else
	{
		i = 1;
		while (i < argc)
		{
			tableau[x] = ft_atoi(argv[i]);
			ft_printf("tableau = %d\n", tableau[x]);
			ft_printf("atoi = %d\n", ft_atoi(argv[i]));
			if (tableau[x] != ft_atoi(argv[i]))
			{
				ft_printf("Wrong arguments, please try again.");
				exit (0);
			}
			i++;
			x++;
		}
	}
	i = 0;
	while (i < x)
	{
		ft_printf("number %d = %d\n", i, tableau[i]);
		i++;
	}
}
