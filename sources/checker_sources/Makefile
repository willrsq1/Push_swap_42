SRCS_CHECKER	=	do_instructions.c \
					libft_functions_checker.c \
					lst_utils_checker.c \
					main_functions.c \
					main.c \
					push_checker.c \
					reverse_rotate_checker.c \
					rotate_checker.c \
					swap_checker.c \

FT_PRINTF		=		ft_printf.c \
					ft_char_c.c \
					ft_char_d.c \
					ft_char_p.c \
					ft_char_s.c \
					ft_char_u.c \
					ft_char_x.c \
					ft_char_xx.c \
					ft_putchar.c \

SRCS_CHECKER := $(addprefix sources/,$(SRCS_CHECKER))

FT_PRINTF := $(addprefix ../ft_printf/,$(FT_PRINTF))

OBJS			=	$(SRCS_CHECKER:.c=.o) $(FT_PRINTF:.c=.o)

HEADER_DIR		=	includes/
HEADERS			=	includes/checker_push_swap.h
CC				=	@gcc
RM				=	@rm -f
LIBC			=	@ar rc
CFLAGS			=	-Wall -Wextra -Werror -I $(HEADERS)

NAME			=	checker

%.o: %.c $(HEADERS) Makefile
	$(CC) -c $< -o $@ -I $(HEADER_DIR)

all:			$(NAME)
				@echo "		---Checker's compilation completed---"

$(NAME):		$(OBJS) ${HEADER_DIR} 
				${CC} ${CFLAGS} $(OBJS) -o ${NAME}

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re
