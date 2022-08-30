/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 13:51:21 by bchabot           #+#    #+#             */
/*   Updated: 2022/08/30 18:45:31 by bchabot          ###   ########.fr       */
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

void	parse_data(char **argv, t_stack *stack)
{
	t_element	*node;
	int			i;
	char		*str;
	char		**tab;

	i = 1;
	str = ft_calloc(sizeof(char), 1);
	while (argv[i])
	{
		if (argv[i][0] == '\0')
			print_error();
		check_params(argv[i]);
		str = strjoin_ps(str, argv[i]);
		i++;
	}
	tab = ft_split(str, ' ');
	free(str);
	i = 0;
	while (tab[i])
	{
		node = lstnew_element(atoi_ps(tab[i]));
		lstadd_back_ps(stack, node);
		i++;
	}
	search_duplicate(stack);
	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}
