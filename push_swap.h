/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:16:30 by bchabot           #+#    #+#             */
/*   Updated: 2022/08/29 18:15:43 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct s_element {
	struct	s_element	*next;
	int	content;
	int index;
}	t_element;

typedef struct s_stack {
	struct	s_element	*head;
	struct	s_element	*tail;
	int nb_max;
}	t_stack;

t_stack *lstnew_ps();
t_element *lstnew_element(int content);
void	lstadd_front_ps(t_stack *stack, t_element *node);
int		*parse_data(int argc, char **argv, t_stack *a);
void	check_params(char *argv);
void	search_duplicate(int *tab, int nb_max);
char	*strjoin_ps(char *s1, char *s2);
void	print_error();
int		atoi_ps(const char *nptr);

#endif
