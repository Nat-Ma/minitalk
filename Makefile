# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nrauh <nrauh@student.42berlin.de>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/28 15:24:11 by nrauh             #+#    #+#              #
#    Updated: 2024/07/28 17:15:22 by nrauh            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

SRCS = client.c server.c
OBJS := $(SRCS:%.c=%.o)

NAME = minitalk
LIBFT = libft/libft.a

all: ${NAME}

%.o: %.c
	${CC} ${CFLAGS} -Ilibft -c $? -o $@

${NAME}: server client

server: server.o
	make -C libft
	${CC} ${CFLAGS} $? -Llibft -lft -o server

client: client.o
	make -C libft
	${CC} ${CFLAGS} $? -Llibft -lft -o client

clean:
	make clean -C libft
	${RM} ${OBJS}

fclean: clean
	${RM} server client $(NAME) $(LIBFT)

re: fclean all

.PHONY: libft server client all clean fclean re
