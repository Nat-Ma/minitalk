# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: natalierauh <natalierauh@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/28 15:24:11 by nrauh             #+#    #+#              #
#    Updated: 2024/08/03 10:56:10 by natalierauh      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror

SRCS = client.c server.c client_bonus.c server_bonus.c
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

server_bonus: server_bonus.o
	make -C libft
	${CC} ${CFLAGS} $? -Llibft -lft -o server_bonus

client_bonus: client_bonus.o
	make -C libft
	${CC} ${CFLAGS} $? -Llibft -lft -o client_bonus

bonus: server_bonus client_bonus

clean:
	make clean -C libft
	${RM} ${OBJS}

fclean: clean
	${RM} server client server_bonus client_bonus $(NAME) $(LIBFT)

re: fclean all

.PHONY: libft server client all clean fclean re bonus
