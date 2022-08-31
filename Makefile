# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bchabot <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/06 15:01:56 by bchabot           #+#    #+#              #
#    Updated: 2022/08/31 17:52:11 by bchabot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = push_swap.c \
		push_swap_utils.c \
		list_utils.c \
		parse_data.c \
		check_errors.c \
		instructions/swap.c \
		instructions/rotate.c \
		instructions/reverse.c \
		instructions/push.c

CC = gcc

LIBFT = libft/libft.a

CFLAGS = -g -Wall -Wextra -Werror

NAME = push_swap

OBJS = $(SRCS:.c=.o)

all : $(NAME)
	
$(LIBFT) :
	make -sC libft
	@echo "\033[92mLibft Compiled."

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(OBJS) $(CFLAGS) $(LIBFT) -o $(NAME)
	@echo "\033[100m\033[1m\033[92mProgram Compiled."

clean :
	rm -f $(OBJS)
	make -sC libft fclean
	@echo "\033[91mObjects cleaned."

fclean : clean
	rm -rf $(NAME)
	@echo "\033[91mObjects and program cleaned."

re : fclean all

.PHONY : all re clean fclean
.SILENT :
