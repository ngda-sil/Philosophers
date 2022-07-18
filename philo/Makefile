# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngda-sil <ngda-sil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/14 17:39:29 by ngda-sil          #+#    #+#              #
#    Updated: 2022/07/18 19:27:52 by ngda-sil         ###   ########.fr        #
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
				  utils.c \
				  c_du_propre.c
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
