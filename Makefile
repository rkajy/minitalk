# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: radandri <radandri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/16 09:28:36 by radandri          #+#    #+#              #
#    Updated: 2025/09/16 19:16:29 by radandri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
SERVER_NAME = server
CLIENT_NAME = client

LIBFT_PRINTF_DIR = libftprintf

LIBFT_PRINTF = $(LIBFT_PRINTF_DIR)/libftprintf.a

CLIENT_SRCS = client.c \
			  minitalk.c \

SERVER_SRCS = server.c \
			  minitalk.c \

CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)

SERVER_OBJS = $(SERVER_SRCS:.c=.o)


all: $(LIBFT_PRINTF) $(CLIENT_NAME) $(SERVER_NAME)

$(SERVER_NAME): $(LIBFT_PRINTF) $(SERVER_OBJS)
	$(CC)	$(CFLAGS)	$(SERVER_OBJS)	$(LIBFT_PRINTF)  -o $(SERVER_NAME)

$(CLIENT_NAME):	$(LIBFT_PRINTF)	$(CLIENT_OBJS)
	$(CC)	$(CFLAGS)	$(CLIENT_OBJS)	$(LIBFT_PRINTF)	-o	$(CLIENT_NAME)

$(LIBFT_PRINTF):
	make -C $(LIBFT_PRINTF_DIR)

clean:
	make -C $(LIBFT_PRINTF_DIR) clean
	rm -rf $(CLIENT_OBJS) $(SERVER_OBJS)

fclean: clean
	make -C $(LIBFT_PRINTF_DIR) fclean
	rm -rf $(CLIENT_NAME) $(SERVER_NAME)

re: fclean all

.PHONY:	all	clean	fclean	re