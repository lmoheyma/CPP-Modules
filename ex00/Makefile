CC = c++

FLAGS = -Wall -Wextra -Werror -g

SRCS = megaphone.cpp

OBJS_BASE = $(SRCS:.cpp=.o)

OBJS = $(addprefix obj/,$(OBJS_BASE))

NAME = megaphone

all: obj $(NAME)

obj :
	mkdir -p obj

$(NAME): $(OBJS)
	@echo "\n"
	@echo "\033[0;32mCompiling megaphone..."
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)
	@echo "\n\033[0mDone !"

obj/%.o: %.cpp
	@printf "\033[0;33mGenerating megaphone objects... %-33.33s\r" $@
	$(CC) $(FLAGS) -c $< -o $@

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
