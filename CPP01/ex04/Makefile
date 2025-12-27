# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/26 14:36:40 by cmetee-b          #+#    #+#              #
#    Updated: 2025/12/27 08:57:26 by cmetee-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME    = replace
CXX		= c++
CXXFLAGS= -Wall -Wextra -Werror -std=c++98
RM		= rm -f

SRC		= main.cpp
OBJ		= $(SRC:.cpp=.o)

GREEN	= \033[32m
YELLOW	= \033[93m
RED		= \033[31m
RESET	= \033[0m
BOLD	= \033[1m

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(YELLOW)Compiling objects...$(RESET)"
	@ $(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)Build Complete: $(BOLD)$(RESET)$(NAME)"

%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo "$(GREEN)Compiled: $(RESET)$<"

clean:
	@$(RM) $(OBJ)
	@echo "$(YELLOW)Objects files removed$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(YELLOW)Executable removed.$(RESET)"

re: fclean all

.PHONY: all clean fclean