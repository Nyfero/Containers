# Colors
GREY = \e[90m
RED = \e[91m
GREEN = \e[92m
YELLOW = \e[93m
BLUE = \e[34m
PURPLE = \e[95m
CYAN = \e[96m
END = \e[39m

# folders
ATOI_DIR = atoi
DIFF_DIR = diff
ISALPHA_DIR = isalpha
ISASCII_DIR = isascii
STRLEN_DIR = strlen

#file
ATOI_SRCS = 00_atoi_launcher.c 01_atoi_test_negative.c 02_atoi_test_positive.c \
	03_atoi_test_zero.c 04_atoi_test_large_positive.c 05_atoi_test_large_negative.c

DIFF_SRCS = 00_diff_launcher.c 01_diff_test_identical.c 02_diff_test_lessthan.c \
	03_diff_test_greaterthan.c

ISALPHA_SRCS = 00_isalpha_launcher.c 01_isalpha_test_lowercase.c 02_isalpha_test_uppercase.c \
	03_isalpha_test_numbers.c 04_isalpha_test_negative.c

ISASCII_SRCS = 00_isascii_launcher.c 01_isascii_test_valid.c 02_isascii_test_zero.c \
	03_isascii_test_negative.c

STRLEN_SRCS = 00_strlen_launcher.c 01_strlen_test_10_lenght.c 02_strlen_test_0_lenght.c \
	03_strlen_test_null.c 04_strlen_test_40.c

#include
LIBUNIT_DIR = ../framework

LIBFT_DIR = ../libft

LIBUNIT = $(LIBUNIT_DIR)/libunit.a

LIBFT = $(LIBFT_DIR)/libft.a

INC = $(LIBUNIT_DIR)/inc/libunit.h

#compilation
NAME = realtest

CC = clang

CFLAGS = -Wall -Werror -Wextra

RM = rm -f


SRCS = $(addprefix $(ATOI_DIR)/, $(ATOI_SRCS)) \
	$(addprefix $(DIFF_DIR)/, $(DIFF_SRCS)) \
	$(addprefix $(ISALPHA_DIR)/, $(ISALPHA_SRCS)) \
	$(addprefix $(ISASCII_DIR)/, $(ISASCII_SRCS)) \
	$(addprefix $(STRLEN_DIR)/, $(STRLEN_SRCS)) \
	main.c

OBJS = $(SRCS:.c=.o)

#rules
all: $(NAME)

$(NAME): $(LIBFT) $(LIBUNIT) $(OBJS) $(INC)
	@ echo "$(BLUE)\n		*** Make $(NAME) ***\n$(END)"
	@ $(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT) $(LIBUNIT)
	@ echo "$(GREEN)\n		---$(NAME) created ---\n$(END)"

$(LIBUNIT):
	@ echo "$(BLUE)\n		*** Make Libunit ***\n$(END)"
	@ make -C $(LIBUNIT_DIR)

$(LIBFT):
	@ echo "$(BLUE)\n		*** Make Libft ***\n$(END)"
	@ make -C $(LIBFT_DIR)

test: all
	@./$(NAME)

.c.o:
	@ ${CC} ${CFLAGS} -I $(INC) -c $< -o ${<:.c=.o}

clean:
	$(RM) $(OBJS)
	@ make clean -C $(LIBUNIT_DIR)
	@ make clean -C $(LIBFT_DIR)
	@ echo "$(PURPLE)\n		*** Clean objects ***\n$(END)"

fclean: clean
	$(RM) $(NAME)
	@ make fclean -C $(LIBUNIT_DIR)
	@ make fclean -C $(LIBFT_DIR)
	@ echo "$(RED)\n		*** Remove $(NAME) ***\n$(END)"

re: fclean all

bonus: all

.PHONY: all clean fclean re bonus test
