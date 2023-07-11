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

NAME		:= violence

SRCS		:= main.cpp		\
			   Weapon.cpp	\
			   HumanA.cpp	\
			   HumanB.cpp

BUILD_DIR	:= .build
OBJS		:= $(SRCS:%.cpp=$(BUILD_DIR)/%.o)

CXX			:= c++
CFLAGS		:= -Wall -Wextra -Werror -std=c++98

RM          := rm -f
MAKEFLAGS   += --silent --no-print-directory
DIR_DUP     = mkdir -p $(@D)

all: $(NAME)

$(BUILD_DIR)/%.o: %.cpp
	echo "→ Compiling $<"
	$(DIR_DUP)
	$(CXX) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CXX) $(CFLAGS) $(OBJS) -o $(NAME)
	echo "\033[0;32m✓ Compiled $@ successfully\033[0m"

bonus: all

clean:
	echo "→ Removing objects"
	$(RM) -r $(BUILD_DIR)

fclean: clean
	echo "→ Removing binaries"
	$(RM) $(NAME)

re: clean all

.PHONY: re
