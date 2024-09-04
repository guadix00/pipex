# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gualvare <gualvare@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/05 14:05:44 by gualvare          #+#    #+#              #
#    Updated: 2024/08/28 14:29:00 by gualvare         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libft.a


SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
	   ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
	   ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	   ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c \
	   ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c \
	   ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_printf.c \
	   identifier_cs.c identifier_num.c identifier_x.c


OBJS = $(SRCS:.c=.o)


CC = gcc
CFLAGS = -Wall -Wextra -Werror

AR = ar
ARFLAGS = rcs

CIAN = \033[36m


all: $(NAME)


$(NAME): $(OBJS)
	@$(AR) $(ARFLAGS) $(NAME) $(OBJS)
	@echo "\n $(CIAN) ===== Project $(NAME) compiled! ===== $(END)\n"


%.o: %.c libft.h ft_printf.h Makefile
	@$(CC) $(CFLAGS) -c $< -o $@


clean:
	@rm -f $(OBJS)


fclean: clean
	@rm -f $(NAME)


re: fclean all


.PHONY: all clean fclean re

