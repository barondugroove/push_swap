/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:16:30 by bchabot           #+#    #+#             */
/*   Updated: 2022/09/07 13:44:25 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct s_element {
	struct s_element	*next;
	int					content;
	int					index;
}	t_element;

typedef struct s_stack {
	struct s_element	*head;
	int					nb_max;
}	t_stack;

// LIST UTILS 
t_stack				*lstnew_ps(void);
t_element			*lstnew_element(int content);
void				lstadd_back_ps(t_stack *stack, t_element *node);
int					lstsize_ps(t_stack *stack);
void				fill_stack(t_stack *stack, char **tab);

// MAIN UTILS 
char				*strjoin_ps(char *s1, char *s2);
void				free_stack(t_stack *stack);
void				free_tab(char **tab);
char				*get_args(char **argv);
long int			atoi_ps(const char *nptr);

// PARSING 
int					parse_data(char **argv, t_stack *stack);
void				get_index(t_stack *stack);
void				reset_index(t_stack *stack);
int					max_digits(t_stack *stack);
int					nb_max(t_stack *stack);

// ERRORS CHECK 
int					check_params(char *argv);
int					has_number(char *argv);
int					is_int(char **tab);
int					search_duplicate(t_stack *stack);
void				print_error(void);

// ALGO 
void				sorting_big(t_stack *stack, t_stack	*stackb);
void				sorting_three(t_stack *stack);
void				sorting_four(t_stack *stack, t_stack *stackb);
void				sorting_five(t_stack *stack, t_stack *stackb);

// INSTRUCTIONS
int					swap(t_stack *stack);
void				sa(t_stack *stack);
void				sb(t_stack *stack);
void				ss(t_stack *stack, t_stack *stackb);
int					rotate(t_stack *stack);
void				ra(t_stack *stack);
void				rb(t_stack *stack);
void				rr(t_stack *stack, t_stack *stackb);
int					reverse(t_stack	*stack);
void				rra(t_stack *stack);
void				rrb(t_stack *stack);
void				rrr(t_stack *stack, t_stack	*stackb);
int					push(t_stack *stack_snd, t_stack *stack_rcv);
void				pa(t_stack *stack, t_stack *stackb);
void				pb(t_stack *stack, t_stack *stackb);

#endif
