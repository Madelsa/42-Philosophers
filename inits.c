/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahmoud <mahmoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 14:08:01 by mahmoud           #+#    #+#             */
/*   Updated: 2024/03/13 13:03:53 by mahmoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void insert_general_data(t_data *philo_data, char **av)
{
    int i;
    
    i = 0;
    philo_data->no_of_philos = ft_atol(av[1]);
    philo_data->time_to_die = ft_atol(av[2]);
    philo_data->time_to_eat = ft_atol(av[3]);
    philo_data->time_to_sleep = ft_atol(av[4]);
    if (av[5] != NULL)
        philo_data->no_of_meals = ft_atol(av[5]);
    else
        philo_data->no_of_meals = -1;
    philo_data->sim_ended = 0;
    philo_data->all_threads_ready = 0;
    philo_data->no_of_threads_running = 0;
    philo_data->philos = ft_calloc(sizeof(t_philo), philo_data->no_of_philos);
    philo_data->forks = ft_calloc(sizeof(t_fork), philo_data->no_of_philos);
    mutex_ops(&philo_data->data_mutex, "INIT");
    mutex_ops(&philo_data->print_mutex, "INIT");
    while (i < philo_data->no_of_philos)
    {
        mutex_ops(&philo_data->forks[i].fork, "INIT");
        philo_data->forks[i].fork_id = 0;
        i++;
    }
}

void insert_philo_data(t_data *philo_data)
{
    int i;

    i = 0;
    while (i < philo_data->no_of_philos)
    {
        philo_data->philos[i].id = i + 1;
        philo_data->philos[i].is_full = 0;
        philo_data->philos[i].meals_eaten = 0;
        philo_data->philos[i].data = philo_data;
        mutex_ops(&philo_data->philos->philos_mutex, "INIT");
        philo_data->philos[i].left_fork = &philo_data->forks[i];
        philo_data->philos[i].right_fork = &philo_data->forks[(i + 1) %
            philo_data->no_of_philos];
        if (philo_data->philos[i].id % 2 == 0)
        {
            philo_data->philos[i].right_fork = &philo_data->forks[i];
            philo_data->philos[i].left_fork = &philo_data->forks[(i + 1) %
                philo_data->no_of_philos];
        }
        i++;
    }
}

