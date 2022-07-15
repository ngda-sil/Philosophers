# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngda-sil <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/14 17:39:29 by ngda-sil          #+#    #+#              #
#    Updated: 2022/07/15 18:59:58 by ngda-sil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ------------------------------------------------------------------------------

NAME			= philo
CC				= gcc
CFLAGS			= -Wall -Wextra -Werror -g
SRC				= main.c \
				  init.c \
				  life_of_a_philosopher.c \
				  routine.c \
				  time.c \
				  utils.c
OBJ				= $(SRC:.c=.o)

# ==============================================================================


all : $(OBJ)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean :	
	rm -Rf $(OBJ)

fclean : clean
	rm -Rf $(NAME)

re : fclean all

.PHONY: all clean fclean re
