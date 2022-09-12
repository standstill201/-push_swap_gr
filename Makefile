# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seokjyoo <seokjyoo@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/06 20:33:58 by seokjyoo          #+#    #+#              #
#    Updated: 2022/09/12 10:35:55 by seokjyoo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

CFLAG	=	-Wall -Wextra -Werror

RM		=	rm -rf

SRC		=	main.c \
			parsing.c \
			tools/ft_split.c \
			tools/ft_tools.c \
			tools/ft_tools2.c \
			tools_ps/ps_tools.c \
			tools_ps/ps_tools2.c \
			tools_ps/ps_tools3.c \
			tools_ps/sort_min.c \
			greedy/divide_three.c \
			greedy/divide_three2.c \
			greedy/greedy.c \
			greedy/greedy2.c \
			greedy/greedy3.c \
			greedy/greedy_or.c \


OBJS	=	$(SRC:.c=.o)

all	:	$(NAME)

%.o		: %.c
		$(CC) $(CFLAG) -c $< -o $@

clean	:
		$(RM) $(OBJS)

fclean	: clean
		$(RM) $(NAME)

re	: fclean all

$(NAME)	: $(OBJS)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

.PHONY	: all clean fclean re
