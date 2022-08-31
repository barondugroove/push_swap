/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:16:30 by bchabot           #+#    #+#             */
/*   Updated: 2022/08/31 17:25:24 by bchabot          ###   ########.fr       */
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
	struct s_element	*next;
	int					content;
	int					index;
}	t_element;

typedef struct s_stack {
	struct s_element	*head;
	int					nb_max;
}	t_stack;

t_stack		*lstnew_ps(void);
t_element	*lstnew_element(int content);
void		lstadd_back_ps(t_stack *stack, t_element *node);
int			lstsize_ps(t_stack *stack);
void		parse_data(char **argv, t_stack *stack);
void		check_params(char *argv);
void		search_duplicate(t_stack *stack);
char		*strjoin_ps(char *s1, char *s2);
void		print_error(void);
int			atoi_ps(const char *nptr);
void		print_stack(t_stack *stack);

// INSTRUCTIONS
int			swap(t_stack *stack);
void		sa(t_stack *stack);
void		sb(t_stack *stack);
void		ss(t_stack *stack, t_stack *stackb);
int			rotate(t_stack *stack);
void		ra(t_stack *stack);
void		rb(t_stack *stack);
void		rr(t_stack *stack, t_stack *stackb);
int			reverse(t_stack	*stack);
void		rra(t_stack *stack);
void		rrb(t_stack *stack);
void		rrr(t_stack *stack, t_stack	*stackb);
void		pa(t_stack *stack, t_stack *stackb);
void		pb(t_stack *stack, t_stack *stackb);

#endif
