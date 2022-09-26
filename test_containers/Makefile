#    Colors
GREY = \e[90m
RED = \e[91m
GREEN = \e[92m
YELLOW = \e[93m
BLUE = \e[34m
PURPLE = \e[95m
CYAN = \e[96m
END = \e[39m

#    Showing command
DISP = TRUE

ifeq ($(DISP),TRUE)
    HIDE =
else
    HIDE = @
endif

#	Includes
CLASS_PATH = class

CLASS = $(addprefix $(CLASS_PATH)/, Tester.hpp)

#    Files
TESTER_FILE = Tester.cpp

VECTOR_FILES = launcher_vector.cpp vector_capacity.cpp vector_reserve.cpp vector_resize.cpp

SRCS_PATH = srcs

VECTOR_PATH = $(SRCS_PATH)/vector

SRCS = $(addprefix framework/, $(TESTER_FILE)) \
	$(addprefix $(VECTOR_PATH)/, $(VECTOR_FILES)) \
	main.cpp

#    Compilation
NAME = test_containers

CXX = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -rf

OBJS = $(SRCS:.cpp=.o)

#    Rules
all: $(NAME)

.c.o:
	$(HIDE) $(CXX) $(CFLAGS) $(INC) -c $< -o ${<:.c=.o}

$(NAME): $(OBJS) $(INC)
	@ echo "$(BLUE)\n		*** Make $(NAME) ***\n$(END)"
	@ $(CXX) $(CFLAGS) $(OBJS) -o $(NAME)
	@ echo "$(GREEN)\n		---$(NAME) created ---\n$(END)"

clean:
	$(HIDE) $(RM) $(OBJS)
	@ echo "$(PURPLE)\n        *** Clean objects ***\n$(END)"

fclean: clean
	$(HIDE) $(RM) $(NAME)
	@ echo "$(RED)\n        *** Remove $(NAME) ***\n$(END)"

re: fclean all

.PHONY: $(NAME) all clean fclean re
