# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tracy <tracy@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/13 15:37:13 by ngda-sil          #+#    #+#              #
#    Updated: 2022/05/25 03:21:15 by tracy            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# ------------------------------------------------------------------------------

NAME		= philo
CC			= gcc
CFLAGS 		=  -Wall -Wextra -Werror -g
SRC 		=  	init.c \
				life_of_a_philosopher.c \
				main.c \
				routine.c \
				time.c \
				utils.c \
				utils2.c \
				
OBJ			= $(SRC:.c=.o)
# ==============================================================================


all : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean :
	rm -Rf $(OBJ)

fclean : clean
	rm -Rf $(NAME)

re : fclean all

.PHONY: all clean fclean re