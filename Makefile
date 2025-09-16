# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: radandri <radandri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/16 09:28:36 by radandri          #+#    #+#              #
#    Updated: 2025/09/16 11:02:52 by radandri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
SERVER_NAME = server
CLIENT_NAME = client

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

CLIENT_SRCS = client.c \
			
	   
SERVER_SRCS = server.c \



OBJS = $(SRCS:.c=.o)

all: $(LIBFT)