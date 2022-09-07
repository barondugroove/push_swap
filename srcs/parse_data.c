/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 13:51:21 by bchabot           #+#    #+#             */
/*   Updated: 2022/09/07 13:10:24 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	nb_max(t_stack	*a)
{
	t_element	*tmp;
	int			i;

	i = 0;
	tmp = a->head;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

void	get_index(t_stack *stack)
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

void	reset_index(t_stack *stack)
{
	t_element	*tmp;

	tmp = stack->head;
	while (tmp)
	{
		tmp->index = 0;
		tmp = tmp->next;
	}
}

int	parse_data(char **argv, t_stack *stack)
{
	char		*str;
	char		**tab;

	str = get_args(argv);
	if (!str)
		return (1);
	if (!has_number(str) || check_params(str))
	{
		free(str);
		return (1);
	}
	tab = ft_split(str, ' ');
	free(str);
	if (is_int(tab))
		return (1);
	fill_stack(stack, tab);
	if (search_duplicate(stack))
		return (1);
	get_index(stack);
	stack->nb_max = nb_max(stack);
	return (0);
}
