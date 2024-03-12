/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_philo_status.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahmoud <mahmoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 10:28:01 by mahmoud           #+#    #+#             */
/*   Updated: 2024/03/12 13:08:32 by mahmoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void print_status(t_philo *philos, char *str, long *time_delta)
{
    if (simulation_ended(philos->data) == 0)
	{
		if (ft_strcmp("TOOK_FORK", str) == 0)
			printf("\033[37m%ld %d has taken a fork\033[0m\n", *time_delta, philos->id);
		else if (ft_strcmp("EATING", str) == 0)
			printf("\033[32m%ld %d is eating\033[0m\n", *time_delta, philos->id);
		else if (ft_strcmp("SLEEPING", str) == 0)
			printf("\033[33m%ld %d is sleeping\033[0m\n", *time_delta, philos->id);
		else if (ft_strcmp("THINKING", str) == 0)
			printf("\033[36m%ld %d is thinking\033[0m\n", *time_delta, philos->id);
		else if (ft_strcmp("DIED", str) == 0)
			printf("\033[31m%ld %d is dead\033[0m\n", *time_delta, philos->id);
	}
}

void print_philo_status(t_philo *philos, char *str)
{
    long	time_delta;

	time_delta = get_current_time() - philos->data->start_time; 
	if (get_int(&philos->philos_mutex, &philos->is_full) == 1)
		return ;
	mutex_handle(&philos->data->print_mutex, "LOCK");
    print_status(philos, str, &time_delta);
	mutex_handle(&philos->data->print_mutex, "UNLOCK");
}

