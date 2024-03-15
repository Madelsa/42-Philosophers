/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelsa <mabdelsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 09:04:50 by mahmoud           #+#    #+#             */
/*   Updated: 2024/03/15 15:02:21 by mabdelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_data	t_data;

typedef struct s_fork
{
	int					fork_id;
	pthread_mutex_t		fork;
}						t_fork;

typedef struct s_philo
{
	int					id;
	long				meals_eaten;
	int					is_full;
	int					is_greedy;
	long				last_meal;
	t_fork				*left_fork;
	t_fork				*right_fork;
	pthread_mutex_t		philos_mutex;
	pthread_t			thread_id;
	t_data				*data;
}						t_philo;

typedef struct s_data
{
	long				no_of_philos;
	long				time_to_die;
	long				time_to_eat;
	long				time_to_sleep;
	long				no_of_meals;
	long				start_time;
	long				no_of_threads_running;
	int					sim_ended;
	int					all_threads_ready;
	pthread_t			monitor_thread;
	t_fork				*forks;
	pthread_mutex_t		data_mutex;
	pthread_mutex_t		print_mutex;
	t_philo				*philos;
}						t_data;

void					*ft_calloc(size_t count, size_t size);
void					ft_bzero(void *str, size_t len);
long					ft_atol(const char *str);
int						validate_input(char **av);
void					ft_putstr_fd(char *s, int fd);
int						ft_strcmp(const char *s1, const char *s2);
size_t					ft_strlen(const char *str);
int						ft_isdigit(int x);
int						ft_usleep(size_t milliseconds);
size_t					get_current_time(void);
void					insert_general_data(t_data *philo_data, char **av);
void					mutex_ops(pthread_mutex_t *mutex, char *operation);
void					thread_ops(pthread_t *thread, void *(*func)(void *),
							void *data, char *operation);
void					insert_philo_data(t_data *philo_data);
void					create_threads(t_data *philo_data);
void					set_int(pthread_mutex_t *mutex, int *variable,
							int value);
int						get_int(pthread_mutex_t *mutex, int *value);
int						simulation_ended(t_data *philo_data);
void					set_long(pthread_mutex_t *mutex, long *variable,
							long value);
long					get_long(pthread_mutex_t *mutex, long *value);
void					sync_threads(t_data *philo_data);
void					print_philo_status(t_philo *philos, char *str);
void					increment_long(pthread_mutex_t *mutex, long *value);
int						threads_running(pthread_mutex_t *mutex,
							long *no_of_threads_running, long no_of_philos);
void					*monitor_sim(void *data);
void					is_greedy(t_philo *philos);
void					free_all(t_data *philo_data);

#endif