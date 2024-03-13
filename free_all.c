/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahmoud <mahmoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 10:31:38 by mahmoud           #+#    #+#             */
/*   Updated: 2024/03/13 10:35:03 by mahmoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void free_all(t_data *philo_data)
{
    int i;

    i = 0;
    while (i < philo_data->no_of_philos)
    {
        mutex_handle(&philo_data->philos->philos_mutex, "DESTROY");
        i++;
    }
    mutex_handle(&philo_data->data_mutex, "DESTROY");
    mutex_handle(&philo_data->print_mutex, "DESTROY");
    free(philo_data->forks);
    free(philo_data->philos);
}