SRCS			=	./srcs/arg_to_list.c ./srcs/handle_stack.c ./srcs/init.c ./srcs/ft_atoi.c ./srcs/instruction.c ./srcs/sort.c
INCS			=	./includes
OBJS			=	$(SRCS:.c=.o)
CC				=	gcc
RM				=	rm -rf
CFLAGS			=	-Wall -Wextra -Werror -I$(INCS)
NAME			=	push_swap

all:			$(NAME)


$(NAME):		$(OBJS)
				$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

norm:			
				norminette $(SRCS) $(INCS)/*.h

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re norm