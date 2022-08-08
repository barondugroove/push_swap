/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:16:30 by bchabot           #+#    #+#             */
/*   Updated: 2022/08/08 16:30:20 by bchabot          ###   ########.fr       */
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
	struct s_element	*next;
}	t_element;

t_element *lstnew_ps(int content);
void	lstadd_back_ps(t_element **lst, t_element *new);

#endif
