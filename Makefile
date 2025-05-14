# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jnovoa-a <jnovoa-a@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/13 14:14:31 by jnovoa-a          #+#    #+#              #
#    Updated: 2025/05/13 19:19:58 by jnovoa-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= get_next_line.a

CC		= cc
CFLAGS	= -Wall -Wextra -Werror

SRC		= get_next_line.c get_next_line_utils.c
OBJ		= $(SRC:.c=.o)

AR		= ar rcs
RM		= rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
