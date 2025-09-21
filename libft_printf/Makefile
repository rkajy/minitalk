# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: radandri <radandri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/11 18:42:51 by radandri          #+#    #+#              #
#    Updated: 2025/09/16 11:19:45 by radandri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
# TEST = test
SRCS = ft_printf.c \
       ft_utils_az.c \
       ft_utils_numbers.c \
	   ft_utils_hexa.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJS)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# compile the test program
# $(TEST): $(OBJS) main.o
# 	$(CC) $(CFLAGS) -o $(TEST) main.o $(NAME) $(LIBFT)

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean
	
fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
