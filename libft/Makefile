NAME			=	libft.a

INCS			=	libft.h
SRCS			=	ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_memccpy.c \
					ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strnstr.c \
					ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
					ft_isprint.c ft_toupper.c ft_tolower.c ft_calloc.c ft_strdup.c \
					ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
					ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
					ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
					ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c ft_gnl.c
OBJS			=	$(patsubst %.c, %.o, $(SRCS))

SRCS_DIR		=	srcs/
OBJS_DIR		=	objs/
INCS_DIR		=	includes/

SRCS_FILE		=	$(addprefix $(SRCS_DIR), $(SRCS))
OBJS_FILE		=	$(addprefix $(OBJS_DIR), $(OBJS))
INCS_FILE		= 	$(addprefix $(INCS_DIR), $(INCS))

CC				=	gcc
AR				=	ar rcs
RM				=	rm -rf
CFLAGS			=	-Wall -Wextra -Werror
HEADER_FLAG		=	-I$(INCS_DIR)

BLACK			=	"\033[1;30m"
RED				=	"\033[1;31m"
GREEN			=	"\033[1;32m"
CYAN			=	"\033[1;35m"
PURPLE			=	"\033[1;36m"
WHITE			=	"\033[1;37m"
EOC				=	"\033[0;0m"

all:			$(NAME)

$(NAME):		$(OBJS_DIR) $(OBJS_FILE)
				@$(AR) libft.a $(OBJS_FILE)
				@echo $(PURPLE) " - Compiling $@" $(GREEN)"\n  - OK" $(EOC)

$(OBJS_DIR) :
					@echo $(CYAN) " - make objs directory" $(EOC)
					@mkdir -p $(OBJS_DIR)
					@echo $(GREEN) " - OK" $(EOC)					

$(OBJS_DIR)%.o :	$(SRCS_DIR)%.c 
					@$(CC) -c $(CFLAGS) $(HEADER_FLAG) $< -o $@

norm:			
				norminette $(SRCS) $(INCS)/*.h

clean:
				@echo $(PURPLE) " - clean libft" $(EOC)
				@$(RM) $(OBJS_FILE)
				@echo $(GREEN) " - OK" $(EOC)

fclean:			
				@echo $(PURPLE) " - fclean libft" $(EOC)
				@$(RM) $(NAME) $(OBJS_FILE)
				@echo $(GREEN) " - OK" $(EOC)

re:				fclean $(NAME)

.PHONY:			all clean fclean re norm