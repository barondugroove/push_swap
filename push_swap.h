/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:16:30 by bchabot           #+#    #+#             */
/*   Updated: 2022/08/30 18:45:27 by bchabot          ###   ########.fr       */
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
	int nb_max;
}	t_stack;

t_stack *lstnew_ps();
t_element *lstnew_element(int content);
void	lstadd_back_ps(t_stack *stack, t_element *node);
void	parse_data(char **argv, t_stack *stack);
void	check_params(char *argv);
void	search_duplicate(t_stack *stack);
char	*strjoin_ps(char *s1, char *s2);
void	print_error();
int		atoi_ps(const char *nptr);
void	sa(t_stack *stack);
void	ra(t_stack *stack);
void	rra(t_stack *stack);
void	print_stack(t_stack *stack);

#endif
