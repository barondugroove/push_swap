/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 13:15:08 by bchabot           #+#    #+#             */
/*   Updated: 2022/08/09 13:48:53 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void check_params_char(char **tab)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (tab[i])
	{
		while (tab[i][j])
		{
			if (tab[i][j] < 48 || tab[i][j] > 57)
			{
				ft_printf("Wrong arguments, please try again.");
				exit (0);
			}
			j++;
		}
		i++;
		j = 0;
	}
}
