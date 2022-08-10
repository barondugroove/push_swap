/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 15:56:52 by bchabot           #+#    #+#             */
/*   Updated: 2022/08/10 15:35:57 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_element *lstnew_ps(int content)
{
	t_element *element;

	element = malloc(sizeof(t_element));
	if (element)
	{
		element->content = content;
		element->next = NULL;
		element->prev = NULL;
	}
	return (element);
}

void	lstadd_back_ps(t_element **lst, t_element *new)
{
	t_element *tmp;

	if (!lst || !*lst)
	{
		*lst = new;
		return	;
	}
	tmp = *lst;
	while (tmp->next != NULL)
	{
		tmp->prev = tmp;
		tmp = tmp->next;
	}
	tmp->next = new;
	new->prev = tmp;
}
