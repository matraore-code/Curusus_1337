# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: matraore <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/17 16:07:30 by matraore          #+#    #+#              #
#    Updated: 2019/10/24 01:37:23 by matraore         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_isalpha.c ft_memchr.c ft_putendl_fd.c ft_strjoin.c ft_strnstr.c \
	  ft_isascii.c ft_memcmp.c ft_putnbr_fd.c ft_strlcat.c ft_strrchr.c \
	  ft_isalnum.c ft_isdigit.c ft_memcpy.c ft_putstr_fd.c ft_strlcpy.c \
	  ft_strtrim.c ft_atoi.c ft_isprint.c ft_memmove.c ft_split.c \
	  ft_strlen.c ft_substr.c ft_bzero.c ft_itoa.c ft_memset.c ft_strchr.c \
	  ft_strmapi.c ft_tolower.c ft_calloc.c ft_memccpy.c ft_putchar_fd.c \
	  ft_strdup.c ft_strncmp.c ft_toupper.c

NAME = libft.a

OBJSRC = ft_isalpha.o ft_memchr.o ft_putendl_fd.o ft_strjoin.o ft_strnstr.o \
		 ft_isascii.o ft_memcmp.o ft_putnbr_fd.o ft_strlcat.o ft_strrchr.o \
		 ft_isalnum.o ft_isdigit.o ft_memcpy.o ft_putstr_fd.o ft_strlcpy.o \
		 ft_strtrim.o ft_atoi.o ft_isprint.o ft_memmove.o ft_split.o \
		 ft_strlen.o ft_substr.o ft_bzero.o ft_itoa.o ft_memset.o ft_strchr.o \
		 ft_strmapi.o ft_tolower.o ft_calloc.o ft_memccpy.o ft_putchar_fd.o \
		 ft_strdup.o ft_strncmp.o ft_toupper.o

all : $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c $(SRC)
	ar rc $(NAME) $(OBJSRC)
	ranlib $(NAME)

bonus :
	echo "hh"
clean :
	/bin/rm -f $(OBJSRC)

fclean :
	/bin/rm -f $(NAME)

re : fclean all
