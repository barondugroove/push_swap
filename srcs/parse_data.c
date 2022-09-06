/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 13:51:21 by bchabot           #+#    #+#             */
/*   Updated: 2022/09/06 17:18:15 by bchabot          ###   ########.fr       */
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

void	get_index(t_stack	*stack)
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

int	parse_data(char **argv, t_stack *stack)
{
	t_element	*node;
	int			i;
	char		*str;
	char		**tab;

	i = 1;
	str = ft_calloc(sizeof(char), 1);
	while (argv[i])
	{
		if (has_number(argv[i]))
		{
			free(str);
			return (1);
		}
		str = strjoin_ps(str, argv[i]);
		i++;
	}
	if (has_number(str) || check_params(str))
	{
		free(str);
		return (1);
	}
	tab = ft_split(str, ' ');
	free(str);
	i = 0;
	if (is_int(tab))
	{
		free_tab(tab);
		return (1);
	}
	while (tab[i])
	{
		node = lstnew_element(atoi_ps(tab[i]));
		lstadd_back_ps(stack, node);
		i++;
	}
	free_tab(tab);
	if (search_duplicate(stack))
	{
		free_stack(stack);
		print_error();
	}
	get_index(stack);
	stack->nb_max = nb_max(stack);
	return (0);
}
