# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eribeiro <eribeiro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/10 17:32:30 by eribeiro          #+#    #+#              #
#    Updated: 2022/02/19 14:03:13 by eribeiro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS =	main.c \
		table.c \
		utils.c \
		utils1.c \
		utils2.c \
		ticket.c \
		routine.c \
		routine_die.c \
		routine_meal.c \
		routine_uni.c \
		free.c \

OBJS = 			$(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) -pthread $(OBJS) -o $(NAME)

clean:
		/bin/rm -f $(OBJS)

fclean: clean
		/bin/rm -f $(NAME)

re: fclean all

phony : all re fclean clean
