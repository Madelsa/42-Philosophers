/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sync_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahmoud <mahmoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 10:07:16 by mahmoud           #+#    #+#             */
/*   Updated: 2024/03/12 12:21:59 by mahmoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void increment_long(pthread_mutex_t *mutex, long *value)
{
    mutex_handle(mutex, "LOCK");
    (*value)++;
    mutex_handle(mutex, "UNLOCK");
}

void sync_threads(t_data *philo_data)
{
    while (1)
	{
        if (get_int(&philo_data->data_mutex, &philo_data->all_threads_ready) == 1)
            break;
    }


}

int threads_running(pthread_mutex_t *mutex, long *no_of_threads_running
    , long no_of_philos)
{
    int return_value;
    
    return_value = 0;
    mutex_handle(mutex, "LOCK");
    if (*no_of_threads_running == no_of_philos)
        return_value = 1;
    mutex_handle(mutex, "UNLOCK");
    return (return_value);
}
