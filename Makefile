# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jleblond <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/10 10:22:18 by jleblond          #+#    #+#              #
#    Updated: 2019/01/10 13:37:21 by tlamart          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

CC = gcc
CFLAGS = -Wall -Werror -Wextra


SOURCE = main.c \
	   get_file.c \
	   create_tetri.c \
	   backtracking.c \
	   fillit.c \

HEADER = fillit.h

OFILE = $(SOURCE:.c=.o)

NAME = fillit

LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(LIBFT) $(OFILE)
	$(CC) $(CFLAGS) $(OFILE) libft/libft.a -o $(NAME)

$(OFILE):  $(SOURCE)
	$(CC) $(CFLAGS) -c $(SOURCE)

$(LIBFT):
	make -C ./libft

clean:
	rm -f $(OFILE)
	make clean -C ./libft

fclean: clean
	rm -f $(NAME)
	make fclean -C ./libft

re: fclean all
