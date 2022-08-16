/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 13:51:21 by bchabot           #+#    #+#             */
/*   Updated: 2022/08/16 19:17:28 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_multiple_args(char *argv)
{
	int i;

	i = 0;
	while (argv[i])
	{
		if (argv[i] == ' ' && ft_isdigit(argv[i + 1]))
			return (1);
		i++;
	}
	return (0);
}

int *parse_data(int argc, char **argv, t_element *a)
{
	int i;
	char **tab;
	int x;
	int y;
	int	*tableau;

	i = 1;
	x = 0;
	tableau = malloc(sizeof(int) * 1000);
	while (i < argc)
	{	
		if (is_multiple_args(argv[i]))
		{
			//check_params(argv[i]);
			tab = ft_split(argv[i], ' ');
			y = 0;
			while (tab[y])
			{
				tableau[x] = ft_atoi(tab[x]);
				ft_printf("tableau[%d] = %d\n", x, tableau[x]);
				ft_printf("tab[%d] = %s\n", x, tab[x]);
				if (ft_strncmp(ft_itoa(tableau[x]), tab[x], ft_strlen(tab[x])) || argv[i][0] == '\0')
					write(2, "Error\n", 6);
				x++;
				y++;
			}
		}
		else
		{
				check_params(argv[i]);
				tableau[x] = ft_atoi(argv[i]);
				if (ft_strncmp(ft_itoa(tableau[x]), argv[i], ft_strlen(argv[i])) || argv[i][0] == '\0')
					write(2, "Error\n", 6);
				x++;
		}
		i++;
	}
	a->nb_max = x;
	return (tableau);
}
