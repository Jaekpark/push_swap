NAME			=	libftprintf.a
NAME_DEBUG		=	libftprintf_debug.a

INCS			=	ft_printf.h
SRCS			= 	ft_printf.c print_arg.c print_option.c utils.c
OBJS			=	$(patsubst %.c, %.o, $(SRCS))

SRCS_DIR		=	srcs/
OBJS_DIR		=	objs/
DEBUG_OBJS_DIR	=	objs_debug/
INCS_DIR		=	includes/

SRCS_FILE		=	$(addprefix $(SRCS_DIR), $(SRCS))
OBJS_FILE		=	$(addprefix $(OBJS_DIR), $(OBJS))
DEBUG_OBJS_FILE	=	$(addprefix $(DEBUG_OBJS_DIR), $(OBJS))
INCS_FILE		= 	$(addprefix $(INCS_DIR), $(INCS))

LIBFT_DIR		=	./libft
LIBFT			=	$(LIBFT_DIR)/libft.a
LIBFT_INCS		=	$(LIBFT_DIR)/libft.h
LIBFT_FLAG		=	-lft -L$(LIBFT_DIR)
LIBFT_DEBUG		=	$(LIBFT_DIR)/libft_debug.a

CC				=	gcc
AR				=	ar rcs
RM				=	rm -rf
CFLAGS			=	-Wall -Wextra -Werror
DEBUG_FLAGS		=	-Wall -Wextra -Werror -g -fsanitize=address
HEADER_FLAG		=	-I$(INCS_DIR) -I$(LIBFT_INCS)

BLACK			=	"\033[1;30m"
RED				=	"\033[1;31m"
GREEN			=	"\033[1;32m"
YELLOW			=	"\033[1;33m"
BLUE			=	"\033[1;34m"
CYAN			=	"\033[1;35m"
PURPLE			=	"\033[1;36m"
WHITE			=	"\033[1;37m"
EOC				=	"\033[0;0m"

all:			$(NAME)

debug:			$(NAME_DEBUG)

$(LIBFT):		
				@make -C $(LIBFT_DIR)

$(LIBFT_DEBUG):
				@make debug -C $(LIBFT_DIR)

$(NAME):		$(OBJS_DIR) $(OBJS_FILE) $(LIBFT)
				@echo $(BLUE) " - Compiling $@" $(EOC)
				@$(AR) $(NAME) $(OBJS_FILE) $(LIBFT)				
				@echo $(GREEN) " - OK" $(EOC)

$(NAME_DEBUG):	$(DEBUG_OBJS_DIR) $(DEBUG_OBJS_FILE) $(LIBFT_DEBUG)
				@echo $(BLUE) " - Compiling $@" $(EOC)
				@$(AR) $(NAME_DEBUG) $(DEBUG_OBJS_FILE) $(LIBFT_DEBUG)
				@echo $(GREEN)" - OK" $(EOC)

$(DEBUG_OBJS_DIR):
				@mkdir -p $(DEBUG_OBJS_DIR)

$(DEBUG_OBJS_DIR)%.o:	$(SRCS_DIR)%.c
				@$(CC) -c $(DEBUG_FLAGS) $(HEADER_FLAG) $< -o $@

$(OBJS_DIR) :
					@mkdir -p $(OBJS_DIR)

$(OBJS_DIR)%.o :	$(SRCS_DIR)%.c 
					@$(CC) -c $(CFLAGS) $(HEADER_FLAG) $< -o $@

norm:			
				@echo $(BLUE) " - ft_printf norm check" $(EOC)
				@norminette $(SRCS_FILE) $(INCS_FILE)

clean:
				@make clean -C $(LIBFT_DIR)
				@echo $(BLUE) " - clean libs" $(EOC)
				@$(RM) $(OBJS_FILE) $(DEBUG_OBJS_FILE)
				@echo $(GREEN) " - OK" $(EOC)


fclean:
				@make fclean -C $(LIBFT_DIR)
				@echo $(BLUE) " - fclean libs" $(EOC)
				@$(RM) $(NAME_DEBUG) $(NAME) $(OBJS_DIR) $(DEBUG_OBJS_DIR)
				@echo $(GREEN) " - OK" $(EOC)


re:				fclean $(NAME)

redebug:		fclean $(NAME_DEBUG)

.PHONY:			all clean fclean re norm debug redebug
