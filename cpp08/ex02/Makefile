CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = MutantStack

SRCDIR = .
OBJDIR = obj

SRCS = main.cpp
INCS_DIR	=	.
MAIN_INC	= -I $(INCS_DIR)
OBJS = $(SRCS:%.cpp=$(OBJDIR)/%.o)
INCS = $(shell find $(INCS_DIR) -type f -name "*.hpp")


all: $(NAME)

$(NAME): $(OBJS) $(INCS)
	$(CXX) $(CXXFLAGS) $(OBJS) $(MAIN_INC) -o $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) $(MAIN_INC) -c $< -o $@
clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re