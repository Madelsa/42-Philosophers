/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sim.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahmoud <mahmoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 09:28:01 by mahmoud           #+#    #+#             */
/*   Updated: 2024/03/11 11:30:48 by mahmoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *dinner_sim(void *philos_data)
{
    t_philo *philos;
    philos = (t_philo *)philos_data;
   sync_threads(philos->data);
   while (simulation_ended(philos->data) == 0)
   {
        

        
   }
}

void create_threads(t_data *philo_data)
{
    int i;

    i = 0;
    if (philo_data->no_of_meals == 0)
        return ;
    else if (philo_data->no_of_philos == 1)
        ;
    else
    {
        while (i < philo_data->no_of_philos)
        {
            thread_handle(&philo_data->philos[i].thread_id, dinner_sim,
                &philo_data->philos[i], "CREATE");
        }
    }
    philo_data->start_time = get_current_time();
    set_int(&philo_data->data_mutex, &philo_data->all_threads_ready, 1);
    i = 0;
    while (i < philo_data->no_of_philos)
    {
        thread_handle(&philo_data->philos[i].thread_id, NULL, NULL, "JOIN");
        i++;
    }
    
}
