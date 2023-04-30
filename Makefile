SRCS			=  		main.c \
					main_utils.c \
					loop_values.c \
					all_core_functions.c \
				   	utils_of_first_sort.c \
					utils_of_second_sort.c \
					secondary_utils.c \

SND_SRCS		=		small_stacks_algo.c \
					size_3_stack_algo.c \
					lst_utils.c \
					push.c \
					reverse_rotate.c \
					rotate.c \
				   	swap.c \
				   	push_swap_utils.c \
					libft_functions.c \

FT_PRINTF		=		ft_printf.c \
					ft_char_c.c \
					ft_char_d.c \
					ft_char_p.c \
					ft_char_s.c \
					ft_char_u.c \
					ft_char_x.c \
					ft_char_xx.c \
					ft_putchar.c \
					

### COLORS ###
NOC         = \033[0m
BOLD        = \033[1m
UNDERLINE   = \033[4m
BLACK       = \033[1;30m
RED         = \033[1;31m
GREEN       = \033[1;32m
YELLOW      = \033[1;33m
BLUE        = \033[1;34m
VIOLET      = \033[1;35m
CYAN        = \033[1;36m
WHITE       = \033[1;37m

SRCS := $(addprefix sources/primary/,$(SRCS))

SND_SRCS := $(addprefix sources/secondary/,$(SND_SRCS))

FT_PRINTF := ${addprefix sources/ft_printf/,$(FT_PRINTF)}

OBJS			=	$(SRCS:.c=.o) $(SND_SRCS:.c=.o) $(FT_PRINTF:.c=.o)
HEADER_DIR		=	includes/
HEADERS			=	includes/push_swap.h
CC				=	@gcc
RM				=	@rm -f
LIBC			=	@ar rc
CFLAGS			=	-Werror -Wextra -Wall
CHECKER_DIR		=	sources/checker_sources
NAME			=	push_swap

%.o:%.c			${HEADERS}
				$(CC) ${CFLAGS} -c $< -o $@

all:			message $(NAME) ft_printf_do checker_do say_hi

$(NAME):		${OBJS}
				@echo " - Compiling $@..."
				${CC} ${CFLAGS} -I. $(HEADERS) ${OBJS} -o ${NAME}

ft_printf_do:
				@echo " - Compiling Ft_Printf"
				@$(MAKE) -C sources/ft_printf

checker_do:		
				@echo " - Compiling Checker..."
				@$(MAKE) -C $(CHECKER_DIR)
				@cp sources/checker_sources/checker checker

say_hi:
				@echo "\n 	Hi ! push_swap and checker are now in the directory, ready to be launched. \
				\n\n\n			----- Have fun ! ----- \n\nCommands : make + test1_100, test3, test10, test100, test500, test1000\n\
				\n 							Calculations can be instantaneous by putting the QUICK Parameter to 1 in header."

message:
				@echo "\n			$(_CYAN)Compiling Push_Swap, Ft_Printf and Checker"

test1_100:
				@./.testeur_push_swap/tester.sh . 1-100 3
test3:
				@./.testeur_push_swap/tester.sh . 3 10
test10:
				@./.testeur_push_swap/tester.sh . 10 10
test100:
				@./.testeur_push_swap/tester.sh . 100 10
test500:
				@./.testeur_push_swap/tester.sh . 500 10
test1000:
				@./.testeur_push_swap/tester.sh . 1000 10

clean:
				@echo " $(_RED)- Cleaning..."
				$(RM) $(OBJS) push_swap_result.log push_swap_run_args.log
				@rm -f sources/checker_sources/*.o

fclean:			clean
				$(RM) $(NAME) checker push_swap_run_args.log

re:				fclean all

.PHONY:			all clean fclean re say_hi checker_do ft_printf_do message test1_100 test3 test10 test100 test500 test1000
