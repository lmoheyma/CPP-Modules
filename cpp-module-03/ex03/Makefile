CC = g++

FLAGS = -Wall -Wextra -Werror -Wshadow -std=c++98

SRCS = src/main.cpp \
		src/ClapTrap.cpp \
		src/ScavTrap.cpp \
		src/FragTrap.cpp \
		src/DiamondTrap.cpp

INCLUDE = -I inc/

OBJS_BASE = $(SRCS:.cpp=.o)
OBJ_PATH = obj/
OBJS = $(addprefix $(OBJ_PATH),$(OBJS_BASE))

NAME = DiamondTrap

all: $(OBJ_PATH) $(NAME)

$(OBJ_PATH) :
	mkdir -p obj
	mkdir -p obj/src

$(NAME): $(OBJS)
	@echo "\n"
	@echo "\033[1m\033[32mCompiling diamond trap ..."
	$(CC) $(FLAGS) $(OBJS) -o $(NAME) $(INCLUDE)
	@echo "\n\033[1m\033[35mDone !"

$(OBJ_PATH)%.o: %.cpp
	@printf "\033[0;33mGenerating diamond trap objects... %-33.33s\r" $@
	$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@

clean:
	@echo "\033[1m\033[31m"
	@echo "\nRemoving binaries..."
	rm -f $(OBJS)
	@echo "\033[0m"

fclean: clean
	@echo "\033[1m\033[31m\nDeleting executable..."
	rm -f $(NAME)
	@echo "\033[0m"

re: fclean $(NAME)

.PHONY: all clean fclean re
