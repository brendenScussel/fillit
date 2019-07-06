# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bscussel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/05 17:38:05 by bscussel          #+#    #+#              #
#    Updated: 2019/07/05 17:38:09 by bscussel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CC = gcc

CFLAGS = -Wall -Wextra -Werror

HEADER = fillit.h

CFILES = *.c

OFILES = *.o

LIBFT = libft.a

LCFILES = ./libft/*.c

LOFILES = ./*.o

LHEADER = libft/libft.h

all: $(NAME)

$(NAME): $(LOFILES)
	ar rc $(LIBFT) $(LOFILES)
	ranlib $(LIBFT)
	$(CC) $(CFLAGS) -I=$(HEADER) -o $(NAME) $(CFILES) $(LIBFT)

$(LOFILES): $(LCFILES)
	$(CC) -c $(CFLAGS) -I=$(LHEADER) $(LCFILES)

clean:
	rm -rf $(OFILES) $(LOFILES)

fclean:
	rm -rf $(NAME) $(LIBFT) $(OFILES) $(LOFILES)

re: fclean all

debug:
	gcc $(CFLAGS) -g *.c libft.a -o $(NAME)

.PHONY: clean fclean all re
