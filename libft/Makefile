# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bscussel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/02 14:58:19 by bscussel          #+#    #+#              #
#    Updated: 2019/07/04 19:19:21 by bscussel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a
FLAGS		= -c -Wall -Werror -Wextra
HEADER		= libft.h
SRCFILES	= ft_sqrt.c \
			  err_prog.c \
			  ft_strnew.c \
			  ft_strdel.c \
			  ft_strsub.c \
			  ft_putchar.c \
			  ft_putstr.c \

O_FILES 	= $(SRCFILES:%.c=%.o)

all: $(NAME)

$(NAME): $(O_FILES)
			ar rc $(NAME) $(O_FILES)
			ranlib $(NAME)

$(O_FILES): $(SRCFILES)
			gcc $(FLAGS) -I=$(HEADER) $(SRCFILES)

clean:
			rm -f $(O_FILES)

fclean: clean
			rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
