CC = c++

FLAGS = -Wall -Wextra -Werror -g -std=c++98

SRCS = src/Account.cpp \
		src/tests.cpp

INCLUDE = -I inc/

OBJS_BASE = $(SRCS:.cpp=.o)

OBJS = $(addprefix obj/,$(OBJS_BASE))

NAME = PhoneBook

all: obj $(NAME)

obj :
	mkdir -p obj
	mkdir -p obj/src

$(NAME): $(OBJS)
	@echo "\n"
	@echo "\033[0;32mCompiling phonebook..."
	$(CC) $(FLAGS) $(OBJS) -o $(NAME) $(INCLUDE)
	@echo "\n\033[0mDone !"

obj/%.o: %.cpp
	@printf "\033[0;33mGenerating phonebook objects... %-33.33s\r" $@
	$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@

clean:
	@echo "\033[0;31m"
	@echo "\nRemoving binaries..."
	rm -f $(OBJS)
	@echo "\033[0m"

fclean: clean
	@echo "\033[0;31m\nDeleting executable..."
	rm -f $(NAME)
	@echo "\033[0m"

re: fclean $(NAME)

.PHONY: all clean fclean re
