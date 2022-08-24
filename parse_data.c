/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 13:51:21 by bchabot           #+#    #+#             */
/*   Updated: 2022/08/24 16:43:46 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int *parse_data(int argc, char **argv, t_element *a)
{
	int i;
	char *str;
	char **tab;
	int	*tableau;

	i = 1;
	tableau = malloc(sizeof(int) * 1000);
	(void)argc;
	str = ft_calloc(sizeof(char), 100);
	while (argv[i])
	{
		if (argv[i][0] == '\0')
			print_error();
		check_params(argv[i]);
		str = strjoin_ps(str, argv[i]);
		i++;
	}
	tab = ft_split(str, ' ');
	i = 0;
	while (tab[i])
	{
		if (ft_strlen(tab[i]) > 10)
			print_error();
		tableau[i] = ft_atoi(tab[i]);
		i++;
	}
	search_duplicate(tableau, i);
	a->nb_max = i;
	while (i)
		free(tab[i--]);
	return (tableau);
}
