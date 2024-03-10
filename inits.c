/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahmoud <mahmoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 14:08:01 by mahmoud           #+#    #+#             */
/*   Updated: 2024/03/10 11:04:53 by mahmoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void insert_philo_data(t_data *philo_data, char **av)
{
    philo_data->no_of_philos = ft_atol(av[1]);
    philo_data->time_to_die = ft_atol(av[2]);
    philo_data->time_to_eat = ft_atol(av[3]);
    philo_data->time_to_sleep = ft_atol(av[4]);
    philo_data->sim_ended = 0;
    if (av[5] != NULL)
        philo_data->no_of_meals = ft_atol(av[5]);
    else
        philo_data->no_of_meals = -1;
}