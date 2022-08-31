NAME	=	push_swap

CC		=	cc
CFLAG	=	-Wall -Wextra -Werror -g

RM		=	rm -f


FILES	=	./libft/libft.a \

SRC		=	./src_ps/main.c \
			./src_ps/dv_three.c \
			./src_ps/ps_tools.c \
			./src_ps/ps_tools2.c \
			./src_ps/greedy.c \

OBJS	=	$(SRC:.c=.o) 

all	:	$(NAME)

$(NAME)	: $(OBJS)
		$(CC) $(CFLAG) $(FILES) $(OBJS) -o $@

%.o		: %.c
		cd ./libft ; make
		$(CC) $(CFLAG) -c $< -o $@

clean	:
		$(RM) $(OBJS)

fclean	: clean
		$(RM) $(NAME)

re	: fclean all


.PHONY	: all clean fclean re


