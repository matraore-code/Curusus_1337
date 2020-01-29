# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: matraore <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/15 21:42:54 by matraore          #+#    #+#              #
#    Updated: 2020/01/20 23:40:48 by matraore         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRC = convert.c d.c flags.c ft_atoi.c ft_printf.c ft_putchar.c ft_putstr_fd.c\
	  ft_putnbr_fd.c ft_strdup.c ft_strlcpy.c ft_strlen.c ft_strncmp.c\
	  get_display.c initialiser.c p.c s.c parser.c percent.c precision.c x.c\
	  u.c specifier.c width.c switch.c traitement.c c.c

NAME = libftprintf.a

OBJSRC = convert.o d.o flags.o ft_atoi.o ft_printf.o ft_putchar.o\
		ft_putnbr_fd.o ft_strdup.o ft_strlcpy.o ft_strlen.o ft_strncmp.o\
		get_display.o initialiser.o p.o s.o parser.o percent.o precision.o\
		u.o specifier.o width.o switch.o traitement.o  ft_putstr_fd.o  x.o c.o 

all : $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c $(SRC)
	ar rc $(NAME) $(OBJSRC)
	ranlib $(NAME)

bonus :
	echo "hh"
clean :
	/bin/rm -f $(OBJSRC)

fclean : clean
	/bin/rm -f $(NAME)

re : fclean all
