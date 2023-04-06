# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/04 16:53:57 by rennacir          #+#    #+#              #
#    Updated: 2023/04/06 01:42:34 by rennacir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror

PARS = $(addprefix parsing/, parsing.c parsing_1.c error.c)
LIBF = $(addprefix libf/, ft_strlen.c ft_strcmp.c)
GNL =  $(addprefix GNL/, get_next_line.c get_next_line_utils.c)
SRCS = main.c  $(PARS) $(LIBF) $(GNL)

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):  $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ)  -o $(NAME)
	@echo $(NAME) "Created"

%.o:%.c so_long.h
	@$(CC) -c $(CFLAGS) $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all


.PHONY: all clean fclean re