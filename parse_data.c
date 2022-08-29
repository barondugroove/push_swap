/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 13:51:21 by bchabot           #+#    #+#             */
/*   Updated: 2022/08/29 19:20:28 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int nb_max(char *str, t_stack	*a)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (str[i])
	{
		if ((str[i] >= 48 && str[i] <= 57) && (str[i + 1] < 48 || str[i + 1] > 57)) 
			x++;
		i++;
	}
	a->nb_max = x;
	return (x);
}

int *parse_data(int argc, char **argv, t_stack *a)
{
	int i;
	char *str;
	char **tab;
	int	*tableau;

	i = 1;
	(void)argc;
	str = ft_calloc(sizeof(char), 1);
	while (argv[i])
	{
		if (argv[i][0] == '\0')
			print_error();
		check_params(argv[i]);
		str = strjoin_ps(str, argv[i]);
		i++;
	}
	tableau = malloc(sizeof(int) * nb_max(str, a));
	tab = ft_split(str, ' ');
	free(str);
	i = 0;
	while (tab[i])
	{
		if (ft_strlen(tab[i]) > 10)
			print_error();
		tableau[i] = atoi_ps(tab[i]);
		i++;
	}
	search_duplicate(tableau, i);
	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	return (tableau);
}
