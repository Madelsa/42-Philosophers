# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mahmoud <mahmoud@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/09 09:08:30 by mahmoud           #+#    #+#              #
#    Updated: 2024/03/13 10:35:18 by mahmoud          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SOURCES = ./philo.c ./utils1.c ./utils2.c ./parsing.c ./inits.c ./mutex_thread_ops.c \
		  ./lock_unlock_set_get.c ./print_philo_status.c ./sync_philos.c ./sim.c \
		  ./monitor_sim.c ./free_all.c
OBJS = $(SOURCES:%.c=%.o)
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
