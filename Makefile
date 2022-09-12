# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bchabot <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/06 15:01:56 by bchabot           #+#    #+#              #
#    Updated: 2022/09/07 16:35:39 by bchabot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = srcs/push_swap.c \
		srcs/push_swap_utils.c \
		srcs/list_utils.c \
		srcs/parse_data.c \
		srcs/check_errors.c \
		srcs/algo.c \
		srcs/instructions/swap.c \
		srcs/instructions/rotate.c \
		srcs/instructions/reverse.c \
		srcs/instructions/push.c

CC = gcc

LIBFT = libft/libft.a

CFLAGS = -g -Wall -Wextra -Werror

NAME = push_swap

OBJS = $(SRCS:.c=.o)

all : $(NAME)

%.o : %.c 
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT) :
	make -sC libft
	@echo "\033[92mLibft compiled."

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "\033[100m\033[1m\033[92mProgram compiled and ready to exacute."

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
