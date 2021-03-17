# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jolim <jolim@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/07 07:07:34 by jolim             #+#    #+#              #
#    Updated: 2021/03/17 21:38:51 by jolim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : all clean fclean re bonus

AR = ar
ARFLAGS = rcv

CC = gcc
CFLAGS = -Wall -Werror -Wextra

NAME = ../libgnl.a

OBJS = get_next_line.o \
		get_next_line_utils.o

SRCS = $(OBJS:.o=.c)

all : $(NAME)

$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

bonus : all $(BONUS_OBJ)
	$(AR) $(ARFLAGS) $(NAME) $(BONUS_OBJ)

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all
