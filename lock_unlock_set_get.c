/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lock_unlock_set_get.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahmoud <mahmoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 09:46:27 by mahmoud           #+#    #+#             */
/*   Updated: 2024/03/11 10:22:34 by mahmoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void set_int(pthread_mutex_t *mutex, int *variable, int value)
{
    mutex_handle(mutex, "LOCK");
    *variable = value;
    mutex_handle(mutex, "UNLOCK");
}

int get_int(pthread_mutex_t *mutex, int *value)
{
    int return_value;
    
    mutex_handle(mutex, "LOCK");
    return_value = *value;
    mutex_handle(mutex, "UNLOCK");
    return (return_value);
}

int	simulation_ended(t_data *philo_data)
{
	return (get_int(&philo_data->data_mutex, &philo_data->sim_ended));
}

void set_long(pthread_mutex_t *mutex, long *variable, long value)
{
    mutex_handle(mutex, "LOCK");
    *variable = value;
    mutex_handle(mutex, "UNLOCK");
}

long get_long(pthread_mutex_t *mutex, long *value)
{
    long return_value;
    
    mutex_handle(mutex, "LOCK");
    return_value = *value;
    mutex_handle(mutex, "UNLOCK");
    return (return_value);
}

