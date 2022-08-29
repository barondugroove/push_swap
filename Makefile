# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bchabot <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/06 15:01:56 by bchabot           #+#    #+#              #
#    Updated: 2022/08/29 14:45:57 by bchabot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = push_swap.c \
		push_swap_utils.c \
		list_utils.c \
		parse_data.c \
		check_errors.c

CC = gcc

LIBFT = libft/libft.a

CFLAGS = -g -Wall -Wextra -Werror

NAME = push_swap

OBJS = $(SRCS:.c=.o)

all : $(NAME)
	
$(LIBFT) :
	make -C libft

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(OBJS) $(CFLAGS) $(LIBFT) -o $(NAME)

clean :
	rm -f $(OBJS)
	make -C libft fclean

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all re clean fclean
