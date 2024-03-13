# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mahmoud <mahmoud@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/09 09:08:30 by mahmoud           #+#    #+#              #
#    Updated: 2024/03/13 12:28:13 by mahmoud          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SOURCES = ./philo.c ./utils1.c ./utils2.c ./parsing.c ./inits.c ./mutex_thread_ops.c \
		  ./lock_unlock_set_get.c ./print_philo_status.c ./sync_philos.c ./sim.c \
		  ./monitor_sim.c ./free_all.c ./handle_greedy_philo.c
OBJS = $(SOURCES:%.c=%.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(SOURCES) -o $(NAME)


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
