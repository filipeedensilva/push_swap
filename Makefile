# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: feden-pe <feden-pe@student.42lisboa.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/28 17:57:44 by feden-pe          #+#    #+#              #
#    Updated: 2023/10/27 15:09:54 by feden-pe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

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

BONUS = checker
BONUS_SRC = bonus/checker.c \
     obj/check.o \
     obj/climb.o \
     obj/error.o \
     obj/commands.o \
     obj/instructions.o \
     obj/instructions2.o \
     obj/list_utils.o \
     obj/sort.o \
     obj/sort_utils.o \
     obj/cost.o

NAME = push_swap
OBJ = ${addprefix ./obj/,${SRC:%.c=%.o}}

INCLUDES = -I push_swap.h $(LIBFT_HEADER)

LIBFT = libft/libft.a
LIBFT_HEADER = libft/libft.h

FT_PRINTF = libft/ft_printf/libftprintf.a

GNL_SRC = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
GNL_OBJ = ${GNL_SRC:%.c=%.o}
GNL_HEADER = includes/get_next_line.h

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(FT_PRINTF) -o $(NAME)

$(LIBFT):
	make -C ./libft

./obj/%.o: ./sources/%.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(BONUS)

$(BONUS): $(LIBFT) $(GNL_OBJ) $(BONUS_SRC)
	$(CC) $(CFLAGS) $(BONUS_SRC) $(GNL_OBJ) $(LIBFT) $(FT_PRINTF) -o checker

clean:
	make clean -C ./libft
	$(RM) $(OBJ)

fclean: clean
	make fclean -C ./libft
	$(RM) $(BONUS)
	$(RM) $(GNL_OBJ)
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
