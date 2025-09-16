# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: radandri <radandri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/16 09:28:36 by radandri          #+#    #+#              #
#    Updated: 2025/09/16 11:25:57 by radandri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
SERVER_NAME = server
CLIENT_NAME = client

LIBFT_PRINTF_DIR = libftprintf

LIBFT_PRINF = $(LIBFT_PRINTF_DIR)/libftprintf.a

CLIENT_SRCS = client.c \
			  minitalk.c \


	   
SERVER_SRCS = server.c \
			  minitalk.c \


CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)

SERVER_OBJS = $(SERVER_SRCS:.c=.o)


all: $(LIBFT_PRINF) $(CLIENT_NAME) $(SERVER_NAME)

