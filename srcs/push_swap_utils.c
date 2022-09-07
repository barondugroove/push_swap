/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 21:36:26 by bchabot           #+#    #+#             */
/*   Updated: 2022/09/07 13:09:48 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*get_args(char **argv)
{
	char		*str;
	int			i;

	i = 1;
	str = malloc(sizeof(char) * 1);
	while (argv[i])
	{
		if (!has_number(argv[i]))
		{
			free(str);
			return (NULL);
		}
		str = strjoin_ps(str, argv[i]);
		i++;
	}
	return (str);
}

void	free_stack(t_stack *stack)
{
	t_element	*tmp;

	while (stack->head)
	{
		tmp = stack->head;
		stack->head = stack->head->next;
		free(tmp);
		tmp = NULL;
	}
	free(stack);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

char	*strjoin_ps(char *s1, char *s2)
{
	char	*tab;
	int		longueur;

	if (!s1 || !s2)
		return (NULL);
	longueur = ft_strlen(s1) + ft_strlen(s2) + 2;
	tab = malloc(sizeof(char) * longueur);
	if (!tab)
		return (NULL);
	ft_strlcpy(tab, s1, longueur);
	if (s1[0] != '\0')
		ft_strlcat(tab, " ", longueur);
	ft_strlcat(tab, s2, longueur);
	free(s1);
	return (tab);
}

long	int	atoi_ps(const char *nptr)
{
	long int	nbr;
	int			neg;
	int			i;

	i = 0;
	neg = 1;
	nbr = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-')
	{
		neg *= -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] && (nptr[i] >= '0' && nptr[i] <= '9'))
	{
		nbr = nbr * 10 + (nptr[i] - 48);
		i++;
	}
	return (nbr * neg);
}
