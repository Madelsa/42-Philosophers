/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahmoud <mahmoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 09:04:50 by mahmoud           #+#    #+#             */
/*   Updated: 2024/03/10 11:06:21 by mahmoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/time.h>
#include <limits.h>

typedef struct s_data t_data;

typedef struct s_philo
{
    int id;
    long no_of_meals;
    int is_full;
    long last_meal;
    pthread_mutex_t *left_fork;
    pthread_mutex_t *right_fork;
    pthread_t thread_id;
    t_data *data;
} t_philo;

typedef struct s_data
{
    long no_of_philos;
    long time_to_die;
    long time_to_eat;
    long time_to_sleep;
    long no_of_meals;
    long start_time;
    int sim_ended;
    pthread_mutex_t *forks;
    t_philo *philos;
} t_data;



void    error_msg(void);
long    ft_atol(const char *str);
int     validate_input(char **av);
void	ft_putstr_fd(char *s, int fd);
int	    ft_strcmp(const char *s1, const char *s2);
size_t	ft_strlen(const char *str);
int	ft_isdigit(int x);
int	ft_usleep(size_t milliseconds);
void insert_philo_data(t_data *philo_data, char **av);









#endif