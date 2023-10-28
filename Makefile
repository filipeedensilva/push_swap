# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: feden-pe <feden-pe@student.42lisboa.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/28 17:57:44 by feden-pe          #+#    #+#              #
#    Updated: 2023/10/28 21:26:32 by feden-pe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = #-Wall -Wextra -Werror -g

RM = rm -f

SRC = main.c \
      check.c \
      climb.c \
      error.c \
      commands.c \
      instructions.c \
      instructions2.c \
      list_utils.c \
      sort.c \
      sort_utils.c \
      cost.c

NAME = push_swap
OBJ = ${addprefix ./obj/,${SRC:%.c=%.o}}

INCLUDES = -I push_swap.h $(LIBFT_HEADER)

LIBFT = libft/libft.a
LIBFT_HEADER = libft/libft.h

FT_PRINTF = libft/ft_printf/libftprintf.a

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(FT_PRINTF) -o $(NAME)

$(LIBFT):
	make -C ./libft

./obj/%.o: ./sources/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C ./libft
	$(RM) $(OBJ)

fclean: clean
	make fclean -C ./libft
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
