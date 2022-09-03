/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 13:51:21 by bchabot           #+#    #+#             */
/*   Updated: 2022/09/02 16:06:48 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	nb_max(t_stack	*a)
{
	t_element	*tmp;
	int	i;

	i = 0;
	tmp = a->head;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

void get_index(t_stack	*stack)
{
	t_element	*tmp;
	t_element	*tmp2;

	tmp = stack->head;
	tmp2 = stack->head->next;
	while (tmp)
	{
		while (tmp2)
		{
			if (tmp->content > tmp2->content)
				tmp->index += 1;
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
		tmp2 = stack->head;
	}
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
	has_number(str);
	tab = ft_split(str, ' ');
	free(str);
	i = 0;
	while (tab[i])
	{
		node = lstnew_element(atoi_ps(tab[i]));
		lstadd_back_ps(stack, node);
		free(tab[i]);
		i++;
	}
	free(tab);
	search_duplicate(stack);
	get_index(stack);
}
