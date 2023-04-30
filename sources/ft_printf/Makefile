SRCS	=				 ft_printf.c \
					ft_char_c.c \
					ft_char_d.c \
					ft_char_p.c \
					ft_char_s.c \
					ft_char_u.c \
					ft_char_x.c \
					ft_char_xx.c \
					ft_putchar.c \

SRCF	= srcs

HEAD	= printf.h

OBJS	=  ${SRCS:.c=.o}

NAME	= printf.a

ARC	= @ar rc

CC	= @gcc

RM	= @rm -f

FLAG	= -Wall -Wextra -Werror -fsanitize=address -g3

.c.o:
	${CC} ${FLAG} -c $< -o ${<:.c=.o}

$(NAME):    ${OBJS}
	${ARC} ${NAME} ${OBJS}

$(SRCS) = $(SRCS:.c=.o)

all:	${NAME}

clean:
	${RM} ${OBJS}

fclean:        clean
	${RM} ${NAME}

re:            fclean all

.PHONY :    all clean flean re
