/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahmoud <mahmoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 09:04:50 by mahmoud           #+#    #+#             */
/*   Updated: 2024/03/11 11:14:56 by mahmoud          ###   ########.fr       */
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
    long meals_eaten;
    int is_full;
    long last_meal;
    pthread_mutex_t *left_fork;
    pthread_mutex_t *right_fork;
    pthread_mutex_t philos_mutex;
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
    int all_threads_ready;
    pthread_mutex_t *forks;
    pthread_mutex_t data_mutex;
    pthread_mutex_t print_mutex;
    t_philo *philos;
} t_data;



void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *str, size_t len);
long    ft_atol(const char *str);
int     validate_input(char **av);
void	ft_putstr_fd(char *s, int fd);
int	    ft_strcmp(const char *s1, const char *s2);
size_t	ft_strlen(const char *str);
int	ft_isdigit(int x);
int	ft_usleep(size_t milliseconds);
size_t	get_current_time(void);
void insert_general_data(t_data *philo_data, char **av);
void mutex_handle(pthread_mutex_t *mutex, char *operation);
void	thread_handle(pthread_t *thread, void *(*func)(void *),
		void *data, char *operation);
void insert_philo_data(t_data *philo_data);
void set_int(pthread_mutex_t *mutex, int *variable, int value);
int get_int(pthread_mutex_t *mutex, int *value);
int	simulation_ended(t_data *philo_data);
void set_long(pthread_mutex_t *mutex, long *variable, long value);
long get_long(pthread_mutex_t *mutex, long *value);
void sync_threads(t_data *philo_data);
void print_philo_status(t_philo *philos, char *str);


















#endif