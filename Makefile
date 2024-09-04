# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gualvare <gualvare@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/28 13:57:09 by gualvare          #+#    #+#              #
#    Updated: 2024/09/04 15:16:06 by gualvare         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRCS = src/pipex.c src/pipex_utils.c src/exec.c
OBJS = $(SRCS:.c=.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

INCLUDE = src/pipex.h \
		  libft/libft.h libft/ft.printf.h
CC = cc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address

END = \033[m
RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
PURPLE = \033[35m
CIAN = \033[36m


all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
		@$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)
		@echo "\n $(CIAN) === $(NAME) has been created successfully!===$(END)\n"

$(LIBFT):
	@echo "\n $(YELLOW) === Compiling libft... === $(END)\n"
	@make -C $(LIBFT_DIR)

%.o: %.c $(INCLUDE)
	@$(CC) $(CFLAGS) -c $< -o $@

#object: clean files.o
clean:
	@echo "\n$(YELLOW)--- Cleaning object files...$(END) ---\n"
	@make -C $(LIBFT_DIR) clean
	@rm -f $(OBJS)

#object: clean all the produced files including executable files
fclean: clean
	@echo "\n $(YELLOW)--- Cleaning everything, including the executable...$(END) ---\n"
	@make -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)

#object: re-compile all the files
re: fclean all

.PHONY: all clean fclean re bonus
