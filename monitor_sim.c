/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_sim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahmoud <mahmoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 11:58:00 by mahmoud           #+#    #+#             */
/*   Updated: 2024/03/13 11:23:52 by mahmoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int is_philo_dead(t_philo *philos)
{
    long time_delta;

    if (get_int(&philos->philos_mutex, &philos->is_full) == 1)
        return (0);
    time_delta = get_current_time() - get_long(&philos->philos_mutex
    , &philos->last_meal);
    if (time_delta > philos->data->time_to_die)
        return (1);
    return (0); 
}

void *monitor_sim(void *data)
{
    t_data *philo_data;
    int i;

    philo_data = (t_data *)data;
    while (1)
    {
        if (threads_running(&philo_data->data_mutex
            , &philo_data->no_of_threads_running, philo_data->no_of_philos) == 1)
            break;
    }
    while (simulation_ended(philo_data) == 0)
    {
        i = 0;
        while (i < philo_data->no_of_philos && simulation_ended(philo_data) == 0)
        {
            if (is_philo_dead(&philo_data->philos[i]))
			{
				print_philo_status(&philo_data->philos[i], "DIED");
				set_int(&philo_data->data_mutex, &philo_data->sim_ended, 1);
			}
            else if (get_int(&philo_data->philos->philos_mutex, &philo_data->philos->is_full) == 1)
				set_int(&philo_data->data_mutex, &philo_data->sim_ended, 1);

            i++;
        }
    }
    return (NULL);
}
