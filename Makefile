# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: inskim <inskim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/01 22:08:10 by inskim            #+#    #+#              #
#    Updated: 2022/10/06 21:23:16 by inskim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = printf.c ./utils/check.c ./utils/handle_char.c ./utils/handle_hex.c ./utils/handle_int.c ./utils/handle_ptr.c ./utils/handle_uint.c ./utils/get.c ./utils/handle_format.c ./utils/handle_hex2.c ./utils/handle_percent.c ./utils/handle_str.c ./utils/libft.c ./utils/handle_char_null.c ./utils/handle_num_precision_zero.c ./utils/put.c
BONUS_SRCS = printf_bonus.c ./utils/check_bonus.c ./utils/handle_char_bonus.c ./utils/handle_hex_bonus.c ./utils/handle_int_bonus.c ./utils/handle_ptr_bonus.c ./utils/handle_uint_bonus.c ./utils/get_bonus.c ./utils/handle_format_bonus.c ./utils/handle_hex2_bonus.c ./utils/handle_percent_bonus.c ./utils/handle_str_bonus.c ./utils/libft_bonus.c ./utils/handle_char_null_bonus.c ./utils/handle_num_precision_zero_bonus.c ./utils/put_bonus.c

HEADER = ft_printf.h

ifdef WITH_BONUS
	OBJS = $(BONUS_SRCS:.c=.o)
else
	OBJS = $(SRCS:.c=.o)
endif

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	ar -rcs $@ $^

bonus:
	make WITH_BONUS=1

clean:
	rm -f $(NAME)

fclean: clean
	rm -f $(OBJS) $(BONUS_SRCS:.c=.o)

re: 
	make fclean 
	make all

.PHONY: all clean fclean re bonus
