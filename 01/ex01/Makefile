# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mnouchet <mnouchet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/06 22:19:57 by mnouchet          #+#    #+#              #
#    Updated: 2023/06/19 00:56:12 by mnouchet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= zombie

SRCS		:= main.cpp			\
			   Zombie.cpp		\
			   zombieHorde.cpp	\

CPP			:= c++
CPPFLAGS	:= -Wall -Wextra -Werror -std=c++98

RM          := rm -f
MAKEFLAGS   += --silent --no-print-directory
DIR_DUP     = mkdir -p $(@D)

all: $(NAME)

$(NAME):
	$(CPP) $(CPPFLAGS) $(SRCS) -o $(NAME)
	echo "\033[0;32m✓ $@\033[0m"

bonus: all

clean:
	$(RM) $(NAME)

re: clean all

.PHONY: re
