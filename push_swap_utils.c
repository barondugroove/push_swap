/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 21:36:26 by bchabot           #+#    #+#             */
/*   Updated: 2022/08/31 15:43:48 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	atoi_ps(const char *nptr)
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
	if (nbr > INT_MAX || nbr < INT_MIN)
		print_error();
	return (nbr * neg);
}
