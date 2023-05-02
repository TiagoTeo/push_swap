NAME	= push_swap

SRCS	=	srcs/checks.c \
			srcs/choose_solve.c \
			srcs/ft_split.c \
			srcs/is_functions.c \
			srcs/is_functions_2.c \
			srcs/lst_functions.c \
			srcs/lst_functions_2.c \
			srcs/mov_same_time.c \
			srcs/movements_a.c \
			srcs/movements_b.c \
			srcs/push_swap.c \
			srcs/sim_functions.c \
			srcs/ultimate_push_a.c \
			srcs/ultimate_push_a_2.c \
			srcs/ultimate_push_a_3.c \
			srcs/ultimate_push_b.c \
			srcs/ultimate_push_b_2.c \
			srcs/ultimate_push_b_3.c \
			srcs/ultimate_push_b_4.c \
			srcs/utils.c \

#OBJS		= $(addprefix obj/,$(SRCS:.c=.o))
OBJS	= $(SRCS:%.c=%.o)

CC		= @cc -Wall -Wextra -Werror -g -fsanitize=address

RM		= @rm -f


all:		$(NAME)

.c.o: 
			$(CC) -c $< -o $@

$(NAME):	$(OBJS)
			$(CC) $(OBJS) $(LIBFTA) -o $(NAME)
			@echo "$(GREEN)Successfully built --> $(YELLOW)$(NAME)$(DEFAULT)"

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)
			@echo "$(RED)Files Removed!$(DEFAULT)"

re:			fclean all

.PHONY:		all clean re fclean

god:
			git status
			git add .
			git status
			git commit -m "🔥Random Makefile Commit🔥"
			git status
			git push

#COLORS
GREEN = \033[1;32m
RED = \033[1;31m
DEFAULT = \033[0m
YELLOW = \033[1;33m