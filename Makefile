SRCS			=	./srcs/arg_to_list.c ./srcs/handle_stack.c ./srcs/init.c ./srcs/ft_atoi.c ./srcs/instruction.c ./srcs/sort.c ./srcs/ft_lstsize.c
INCS			=	./includes
OBJS			=	$(SRCS:.c=.o)
CC				=	gcc
RM				=	rm -rf
CFLAGS			=	-Wall -Wextra -Werror -I$(INCS)
NAME			=	push_swap

BLACK="\033[1;30m"
RED="\033[1;31m"
GREEN="\033[1;32m"
CYAN="\033[1;35m"
PURPLE="\033[1;36m"
WHITE="\033[1;37m"
EOC="\033[0;0m"

all:			$(NAME)


$(NAME):		$(OBJS)
				@echo $(CYAN) " - Compiling $@"
				@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
				@echo $(GREEN) "OK"

norm:			
				@norminette $(SRCS) $(INCS)/*.h 

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re norm