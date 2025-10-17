
NAME    = megaphone
CXX     = c++
CXXFLAGS= -Wall -Wextra -Werror -std=c++98
RM      = rm -f

SRC     = megaphone.cpp
OBJ     = $(SRC:.cpp=.o)

GREEN   = \033[32m
YELLOW  = \033[33m
RED     = \033[31m
RESET   = \033[0m
BOLD    = \033[1m

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(YELLOW)Compiling objects...$(RESET)"
	@ $(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)Build Complete: $(BOLD)$(NAME)$(RESET)"

%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo "$(GREEN)Compiled: $(RESET)$<"

clean:
	@$(RM) $(OBJ)
	@echo "$(RED)Objects files removed$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)Executable removed.$(RESET)"

re: fclean all

.PHONY: all clean fclean