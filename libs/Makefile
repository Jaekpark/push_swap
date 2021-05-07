NAME			=	libftprintf.a

INCS			=	ft_printf.h
SRCS			= 	ft_printf.c print_arg.c print_option.c utils.c
OBJS			=	$(patsubst %.c, %.o, $(SRCS))

SRCS_DIR		=	srcs/
OBJS_DIR		=	objs/
INCS_DIR		=	includes/

SRCS_FILE		=	$(addprefix $(SRCS_DIR), $(SRCS))
OBJS_FILE		=	$(addprefix $(OBJS_DIR), $(OBJS))
INCS_FILE		= 	$(addprefix $(INCS_DIR), $(INCS))

LIBFT_DIR		=	./libft
LIBFT			=	$(LIBFT_DIR)/libft.a
LIBFT_INCS		=	$(LIBFT_DIR)/libft.h
LIBFT_FLAG		=	-lft -L$(LIBFT_DIR)

CC				=	gcc
AR				=	ar rcs
RM				=	rm -rf
CFLAGS			=	-Wall -Wextra -Werror
HEADER_FLAG		=	-I$(INCS_DIR) -I$(LIBFT_INCS)

BLACK			=	"\033[1;30m"
RED				=	"\033[1;31m"
GREEN			=	"\033[1;32m"
CYAN			=	"\033[1;35m"
PURPLE			=	"\033[1;36m"
WHITE			=	"\033[1;37m"
EOC				=	"\033[0;0m"

all:			$(NAME)

$(LIBFT):		
				@make -C $(LIBFT_DIR)

$(NAME):		$(OBJS_DIR) $(OBJS_FILE) $(LIBFT)
				@$(AR) $(NAME) $(OBJS_FILE) $(LIBFT)
				@echo $(PURPLE) " - Compiling $@" $(GREEN)"\n  - OK" $(EOC)

$(OBJS_DIR) :
					@echo $(CYAN) " - make objs directory" $(EOC)
					@mkdir -p $(OBJS_DIR)
					@echo $(GREEN) " - OK" $(EOC)					

$(OBJS_DIR)%.o :	$(SRCS_DIR)%.c 
					@$(CC) -c $(CFLAGS) $(HEADER_FLAG) $< -o $@

norm:			
				@echo $(PURPLE) " - ft_printf norm check" $(EOC)
				norminette $(SRCS) $(INCS)/*.h

clean:
				@echo $(PURPLE) " - clean $(NAME)" $(EOC)
				@$(RM) $(OBJS_FILE)
				@echo $(GREEN) " - OK" $(EOC)
				@make clean -C $(LIBFT_DIR)

fclean:			
				@echo $(PURPLE) " - fclean $(NAME)" $(EOC)
				@$(RM) $(NAME) $(OBJS_FILE)
				@echo $(GREEN) " - OK" $(EOC)
				@make fclean -C $(LIBFT_DIR)

re:				fclean $(NAME)

.PHONY:			all clean fclean re norm
