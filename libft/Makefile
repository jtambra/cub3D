# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtambra <talya_1998@mail.ru>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/31 18:03:37 by jtambra           #+#    #+#              #
#    Updated: 2021/03/29 23:02:40 by jtambra          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_strcmp.c ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
	  ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memccpy.c ft_memchr.c \
		ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
		ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c \
		ft_strdup.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c \
		ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c \
		ft_substr.c ft_tolower.c ft_toupper.c

BON_SRC = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
		ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
		ft_lstmap.c

HEADER = libft.h

OBJ = $(SRC:.c=.o)

OBJ_BON = $(BON_SRC:.c=.o)

FLAG = -Wall -Wextra -Werror

CC = gcc

all: $(NAME)

$(NAME): ./libft.h
			echo LIBFT
			$(CC) $(FLAG) -c $(SRC) -I $(HEADER)
			ar rc $(NAME) $(OBJ)
			ranlib $(NAME)

clean:
	rm -f $(OBJ) $(OBJ_BON)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: $(OBJ_BON)
ifeq ($(shell test -f $(NAME) && ar t $(NAME) | grep lst),)
	ar rc $(NAME) $(OBJ_BON)
	ranlib $(NAME)
endif
