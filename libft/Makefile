# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: feden-pe <feden-pe@student.42lisboa.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/15 13:55:00 by feden-pe          #+#    #+#              #
#    Updated: 2023/06/22 18:02:47 by feden-pe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =  ft_atoi.c \
	ft_bzero.c \
	ft_calloc.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memmove.c \
	ft_memcpy.c \
	ft_memset.c \
	ft_strchr.c \
	ft_strdup.c \
	ft_strlcat.c \
	ft_strlcpy.c \
	ft_strlen.c \
	ft_strncmp.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_tolower.c \
	ft_substr.c \
	ft_toupper.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_split.c \
	ft_itoa.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c

BONUS = ft_lstnew.c \
	ft_lstadd_front.c \
	ft_lstsize.c \
	ft_lstlast.c \
	ft_lstadd_back.c \
	ft_lstdelone.c \
	ft_lstclear.c \
	ft_lstiter.c \
	ft_lstmap.c

OBJ_BONUS = $(BONUS:.c=.o)

OBJ = $(SRCS:.c=.o)

FT_PRINTF = ./ft_printf/libftprintf.a

CC = cc

RM = rm -rf

CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

all: $(NAME)

$(NAME): $(OBJ) $(OBJ_BONUS) $(FT_PRINTF)
	ar rcs $(NAME) $(OBJ) $(OBJ_BONUS)

$(FT_PRINTF):
	make -C ./ft_printf

clean:
	make clean -C ./ft_printf
	$(RM) $(OBJ) $(OBJ_BONUS)

fclean: clean
	make fclean -C ./ft_printf
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean bonus fclean re
