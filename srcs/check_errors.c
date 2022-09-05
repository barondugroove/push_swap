/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 13:15:08 by bchabot           #+#    #+#             */
/*   Updated: 2022/09/05 18:30:10 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(void)
{
	write(2, "Error\n", 6);
	exit (0);
}

int	is_int(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		if (atoi_ps(tab[i]) > INT_MAX || atoi_ps(tab[i]) < INT_MIN)
		{
			free_tab(tab);
			print_error();
			return (1);
		}
		i++;
	}
	return (0);
}


int	has_number(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 48 && str[i] <= 57)
			return (0);
		i++;
	}
	free(str);
	return (1);
}

int	search_duplicate(t_stack *stack)
{
	t_element	*tmp;
	t_element	*tmp2;

	tmp = stack->head;
	tmp2 = stack->head->next;
	while (tmp->next)
	{
		while (tmp2)
		{
			if (tmp2->content == tmp->content)
				return (1);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
		tmp2 = tmp->next;
	}
	return (0);
}

int	check_params(char *tab)
{
	int	i;

	i = 0;
	if (tab[i] == '\0')
		return (1);
	while (tab[i])
	{
		if (tab[i] == ' ' && tab[i + 1] == ' ')
			i++;
		else if (tab[i] == ' ' && tab[i + 1] == '\0')
			return (1);
		else if ((tab[i] == '-' || tab[i] == '+') && (tab[i + 1] < 48 || tab[i + 1] > 57))
			return (1);
		else if ((tab[i] < 48 || tab[i] > 57) && (tab[i] != '-' && tab[i] != '+') && tab[i] != ' ')
			return (1);
		else if ((tab[i] >= 48 && tab[i] <= 57) && (tab[i + 1] == '-' || tab[i + 1] == '+'))
			return (1);
		else
			i++;
	}
	return (0);
}
