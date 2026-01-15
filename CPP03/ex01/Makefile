# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/26 14:36:40 by cmetee-b          #+#    #+#              #
#    Updated: 2026/01/15 02:29:25 by cmetee-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME    = ScavTrap
CXX     = c++
CXXFLAGS= -Wall -Wextra -Werror -std=c++98
RM      = rm -rf

INCDIR	= includes
SRCDIR  = srcs
OBJDIR	= objects

SRC     = ClapTrap.cpp main.cpp ScavTrap.cpp

VPATH	= $(SRCDIR)
OBJ		= $(addprefix $(OBJDIR)/, $(SRC:.cpp=.o))

RED		= \033[1;31m
GREEN	= \033[1;32m
YELLOW	= \033[1;33m
BLUE	= \033[1;34m
RESET	= \033[0m

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(YELLOW)Compiling objects...$(RESET)"
	@ $(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)Build Complete: $(RESET)$(NAME)"

$(OBJDIR)/%.o: %.cpp | $(OBJDIR)
	@mkdir -p $(@D)
	@$(CXX) $(CXXFLAGS) -I$(INCDIR) -c $< -o $@
	@echo "$(GREEN)Compiled: $(RESET)$<"

$(OBJDIR):
	@mkdir -p $(OBJDIR)

clean:
	@$(RM) $(OBJDIR)
	@echo "$(RED)Objects files removed$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)Executable removed.$(RESET)"

re: fclean all

.PHONY: all clean fclean