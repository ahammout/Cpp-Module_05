# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahammout <ahammout@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/24 18:09:01 by ahammout          #+#    #+#              #
#    Updated: 2023/07/27 16:28:59 by ahammout         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := Bureaucrat

CC := c++

CFLAGS := -Wall -Wextra -Werror -std=c++98

INCLUDES := -I includes/

OBJ_DIR := obj/

SRC_DIR := src/

COLOUR_GREEN=\033[0;32m
COLOUR_RED=\033[0;31m
# COLOUR_BLUE=\033[0;34m
COLOUR_END=\033[0m

SRC := $(wildcard $(SRC_DIR)*.cpp $(SRC_DIR)*/*.cpp)
OBJS := $(patsubst $(SRC_DIR)%.cpp,$(OBJ_DIR)%.o,$(SRC))

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $^ -o $@
	@echo "$(COLOUR_GREEN)Executable created$(COLOUR_END)"

$(OBJ_DIR)%.o : $(SRC_DIR)%.cpp includes/*.hpp
	@echo "$(COLOUR_GREEN)Creating object file$(COLOUR_END)"
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(COLOUR_RED)Remove objects$(COLOUR_END)"
	@rm -fr $(OBJ_DIR)
	@rm -fr $(OBJS)
	@rm -fr *_shrubbery

fclean: clean
	@echo "$(COLOUR_RED)Remove executable$(COLOUR_END)"
	@rm -rf $(NAME)

re: fclean all