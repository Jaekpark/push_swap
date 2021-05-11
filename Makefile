PUSH_SWAP_PATH	=	~/42cursus/inner_circles/my_push_swap/
TESTER			=	./utils/run.sh
INCS			=	push_swap.h
SRCS			=	arg_to_stack.c conq_max.c conq_min.c do_clear.c do_init.c do_divide.c do_conquer.c\
					do_swap.c do_push.c do_rotate.c do_small_sort.c find_index.c find_max.c find_min.c\
					inst_push.c inst_r_rotate.c inst_rotate.c inst_swap.c print_node_a.c print_node_b.c\
					print_node.c print_stack_color.c print_stack.c print_stack_frame.c print_status.c\
					utils_for_sort.c utils_for_flag.c utils_for_checker.c utils_for_arg.c utils_for_print.c
PW_SRC			=	push_swap.c
CK_SRC			=	checker.c

OBJS			=	$(patsubst %.c, %.o, $(SRCS))
PW_OBJ			=	$(patsubst %.c, %.o, $(PW_SRC))
CK_OBJ			=	$(patsubst %.c, %.o, $(CK_SRC))

SRCS_DIR		=	srcs/
OBJS_DIR		=	objs/
DEBUG_OBJS_DIR	=	objs_debug/
INCS_DIR		=	includes/
PW_DIR			=	srcs/push_swap/
CK_DIR			=	srcs/checker/
TESTER_PATH		=	push_swap_tester/

SRCS_FILE		=	$(addprefix $(SRCS_DIR), $(SRCS))
PW_SRC_FILE		=	$(addprefix $(PW_DIR), $(PW_SRC))
CK_SRC_FILE		=	$(addprefix $(CK_DIR), $(CK_SRC))
DEBUG_OBJS_FILE	=	$(addprefix $(DEBUG_OBJS_DIR), $(OBJS))
OBJS_FILE		=	$(addprefix $(OBJS_DIR), $(OBJS))
PW_OBJ_FILE		=	$(addprefix $(OBJS_DIR), $(PW_OBJ))
CK_OBJ_FILE		=	$(addprefix $(OBJS_DIR), $(CK_OBJ))
CK_DEBUG_OBJ_FILE = $(addprefix $(DEBUG_OBJS_DIR), $(CK_OBJ))	
PW_DEBUG_OBJ_FILE = $(addprefix $(DEBUG_OBJS_DIR), $(PW_OBJ))
INCS_FILE		= 	$(addprefix $(INCS_DIR), $(INCS))

LIBFT			=	$(LIB_DIR)/libft/libft.a
LIBFT_DIR		=	$(LIB_DIR)/libft
LIBFT_INCS		=	$(LIBFT_DIR)/includes/libft.h

LIB_DIR			=	./libs
LIB				=	$(LIB_DIR)/libftprintf.a
LIB_INCS		=	$(LIB_DIR)/includes/ft_printf.h
DEBUG_LIB		=	$(LIB_DIR)/libftprintf_debug.a

CC				=	gcc
RM				=	rm -rf
CFLAGS			=	-Wall -Wextra -Werror
DEBUG_FLAG		=	-Wall -Wextra -Werror -g -fsanitize=address
HEADER_FLAG		=	-I$(INCS_DIR) -I$(LIB_INCS) -I$(LIBFT_INCS)
LIB_FLAG		=	-lftprintf -L$(LIB_DIR) -lft -L$(LIBFT_DIR)
DEBUG_LIB_FLAG	=	-lftprintf_debug -L$(LIB_DIR) -lft_debug -L$(LIBFT_DIR)
NAME_PW			=	push_swap
NAME_CK			=	checker
DEBUG_PW		=	debug_push_swap
DEBUG_CK		=	debug_checker

BLACK			=	"\033[1;30m"
RED				=	"\033[1;31m"
GREEN			=	"\033[1;32m"
YELLOW			=	"\033[1;33m"
BLUE			=	"\033[1;34m"
CYAN			=	"\033[1;35m"
PURPLE			=	"\033[1;36m"
WHITE			=	"\033[1;37m"
EOC				=	"\033[0;0m"
NUM1			= 	1
NUM2			=	2

all:			$(NAME_PW) $(NAME_CK)

debug:			$(DEBUG_PW) $(DEBUG_CK)

lib:			$(LIB)

$(LIB):			
				@make -C $(LIB_DIR)

$(NAME_PW):		$(LIB) $(OBJS_DIR) $(OBJS_FILE) $(PW_OBJ_FILE)
				@echo $(YELLOW) " - Compiling $@"
				@$(CC) $(CFLAGS) $(LIB_FLAG) $(HEADER_FLAG) $(OBJS_FILE) $(PW_OBJ_FILE) -o $@
				@echo $(GREEN) " - OK" $(EOC)

$(NAME_CK):		$(LIB) $(OBJS_DIR) $(OBJS_FILE) $(CK_OBJ_FILE)
				@echo $(YELLOW) " - Compiling $@"
				@$(CC) $(CFLAGS) $(LIB_FLAG) $(HEADER_FLAG) $(OBJS_FILE) $(CK_OBJ_FILE) -o $@
				@echo $(GREEN) " - OK" $(EOC)

$(DEBUG_LIB):
				@make debug -C $(LIB_DIR)

$(DEBUG_PW):	$(DEBUG_LIB) $(DEBUG_OBJS_DIR) $(DEBUG_OBJS_FILE) $(PW_DEBUG_OBJ_FILE) 
				@echo $(YELLOW) " - Compiling $@"
				@$(CC) $(DEBUG_FLAG) $(DEBUG_LIB_FLAG) $(HEADER_FLAG) $(DEBUG_OBJS_FILE) $(PW_DEBUG_OBJ_FILE) -o $@	
				@echo $(GREEN)" - OK"$(EOC)

$(DEBUG_CK):	$(DEBUG_LIB) $(DEBUG_OBJS_DIR) $(DEBUG_OBJS_FILE) $(CK_DEBUG_OBJ_FILE) 
				@echo $(YELLOW) " - Compiling $@"$(EOC)
				@$(CC) $(DEBUG_FLAG) $(DEBUG_LIB_FLAG) $(HEADER_FLAG) $(DEBUG_OBJS_FILE) $(CK_DEBUG_OBJ_FILE) -o $@	
				@echo $(GREEN) " - OK"$(EOC)

$(PW_OBJ_FILE):
				@$(CC) -c $(CFLAGS) $(HEADER_FLAG) $(PW_SRC_FILE) -o $(PW_OBJ_FILE)

$(PW_DEBUG_OBJ_FILE):
				@$(CC) -c $(DEBUG_FLAG) $(HEADER_FLAG) $(PW_SRC_FILE) -o $(PW_DEBUG_OBJ_FILE)

$(CK_OBJ_FILE):
				@$(CC) -c $(CFLAGS) $(HEADER_FLAG) $(CK_SRC_FILE) -o $(CK_OBJ_FILE)

$(CK_DEBUG_OBJ_FILE):
				@$(CC) -c $(DEBUG_FLAG) $(HEADER_FLAG) $(CK_SRC_FILE) -o $(CK_DEBUG_OBJ_FILE)

$(OBJS_DIR) :
					@mkdir -p $(OBJS_DIR)

$(OBJS_DIR)%.o :	$(SRCS_DIR)%.c $(INCS_FILE)
					@$(CC) -c $(CFLAGS) $(HEADER_FLAG) $< -o $@

$(DEBUG_OBJS_DIR):	
					@mkdir -p $(DEBUG_OBJS_DIR)

$(DEBUG_OBJS_DIR)%.o : $(SRCS_DIR)%.c $(INCS_FILE)
						@$(CC) -c $(DEBUG_FLAG) $(HEADER_FLAG) $< -o $@

norm:			
				@echo $(CYAN) " - push swap norm check"$(EOC)
				@norminette $(SRCS_FILE) $(INCS_FILE)
				@make norm -C $(LIB_DIR)
				@make norm -C $(LIBFT_DIR)

num:
	@echo $(CYAN) "generate $(NUM2) numbers" $(EOC)
	@ruby -e "puts ($(NUM1)..$(NUM2)).to_a.shuffle.join(' ')" > $(NUM2)

test:
	@./utils/analyzer.sh

leaks:
	@osascript -e 'tell app "Terminal" to do script "while true; do leaks push_swap; sleep 2; clear; done"'
	@osascript -e 'tell app "Terminal" to do script "while true; do leaks checker; sleep 2; clear; done"'
	@./utils/leaks.sh

clean:
				@make clean -C $(LIB_DIR)
				@echo $(YELLOW) " - clean push_swap" $(EOC)
				@$(RM) $(DEBUG_OBJS_FILE) $(OBJS_FILE) $(CK_OBJ_FILE) $(PW_OBJ_FILE) $(CK_DEBUG_OBJ_FILE) $(PW_DEBUG_OBJ_FILE) $(TESTER_PATH)
				@echo $(GREEN) " - OK" $(EOC)

fclean:
				@make fclean -C $(LIB_DIR)
				@echo $(YELLOW) " - fclean push_swap" $(EOC)
				@$(RM) $(NAME_PW) $(NAME_CK) $(DEBUG_CK) $(DEBUG_PW) $(OBJS_DIR) $(DEBUG_OBJS_DIR) $(TESTER_PATH)
				@echo $(GREEN) " - OK" $(EOC)

tester:
				@rm -rf $(TESTER_PATH)
				@git clone https://github.com/minckim42/push_swap_tester.git
				@make -C $(TESTER_PATH)
				@sed "s/DIR=..\/push_swap/DIR=..\//g" $(TESTER_PATH)/push_swap_tester.bash > $(TESTER_PATH)/test.bash
				@chmod 777 $(TESTER_PATH)/test.bash
				@cd $(TESTER_PATH) && ./test.bash
				@cd $(PUSH_SWAP_PATH)


re:				fclean $(NAME_PW) $(NAME_CK)

.PHONY:			all clean fclean re norm debug tester num leaks
