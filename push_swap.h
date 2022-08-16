/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:16:30 by bchabot           #+#    #+#             */
/*   Updated: 2022/08/16 16:56:08 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include "libft/libft.h"

typedef struct s_element {
	struct s_element	*prev;
	int	content;
	int nb_max;
	struct s_element	*next;
}	t_element;

t_element *lstnew_ps(int content);
void	lstadd_back_ps(t_element **lst, t_element *new);
int		*parse_data(int argc, char **argv, t_element *a);
void	check_params(char *argv);
void	search_duplicate(int *tab, int nb_max);

#endif
