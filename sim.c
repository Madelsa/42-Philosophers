/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sim.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahmoud <mahmoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 09:28:01 by mahmoud           #+#    #+#             */
/*   Updated: 2024/03/12 13:22:29 by mahmoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *one_philo(void *data)
{
    t_philo *philos;

    philos = (t_philo*)data;
    sync_threads(philos->data);
    // set_long(&philos->philos_mutex, &philos->last_meal, get_current_time());
    // increment_long(&philos->data->data_mutex, &philos->data->no_of_threads_running);
    philos->last_meal = get_current_time();
    philos->data->no_of_threads_running++;
    print_philo_status(philos, "TOOK_FORK");
    while (simulation_ended(philos->data) == 0)
        ft_usleep(100);
    return (NULL);
}

void eat (t_philo *philos)
{
    mutex_handle(philos->right_fork, "LOCK");
    print_philo_status(philos, "TOOK_FORK");
    mutex_handle(philos->left_fork, "LOCK");
    print_philo_status(philos, "TOOK_FORK");
    set_long(&philos->philos_mutex, &philos->last_meal, get_current_time());
    philos->meals_eaten++;
    print_philo_status(philos, "EATING");
    ft_usleep(philos->data->time_to_eat);
    if (philos->data->no_of_meals > 0
		&& philos->meals_eaten == philos->data->no_of_meals)
		set_int(&philos->philos_mutex, &philos->is_full, 1);
    mutex_handle(philos->right_fork, "UNLOCK");
    mutex_handle(philos->left_fork, "UNLOCK");
}

void thinking(t_philo *philos)
{
    print_philo_status(philos, "THINKING");
}

void *dinner_sim(void *philos_data)
{
    t_philo *philos;
    philos = (t_philo *)philos_data;
   sync_threads(philos->data);
   set_long(&philos->philos_mutex, &philos->last_meal, get_current_time());
   increment_long(&philos->data->data_mutex
    , &philos->data->no_of_threads_running);
   while (simulation_ended(philos->data) == 0)
   {
        eat(philos);
        print_philo_status(philos, "SLEEPING");
        ft_usleep(philos->data->time_to_sleep);
        thinking(philos);
        
   }
   return (NULL);
}

void create_threads(t_data *philo_data)
{
    int i;

    i = 0;
    if (philo_data->no_of_meals == 0)
        return ;
    else if (philo_data->no_of_philos == 1)
        thread_handle(&philo_data->philos[0].thread_id, one_philo
        , &philo_data->philos[0], "CREATE");
    else
    {
        while (i < philo_data->no_of_philos)
        {
            thread_handle(&philo_data->philos[i].thread_id, dinner_sim,
                &philo_data->philos[i], "CREATE");
            i++;
        }
    }
    thread_handle(&philo_data->monitor_thread, monitor_sim, philo_data, "CREATE");
    philo_data->start_time = get_current_time();
    set_int(&philo_data->data_mutex, &philo_data->all_threads_ready, 1);
    i = 0;
    while (i < philo_data->no_of_philos)
    {
        thread_handle(&philo_data->philos[i].thread_id, NULL, NULL, "JOIN");
        i++;
    } 
    thread_handle(&philo_data->monitor_thread, NULL, NULL, "JOIN");
	set_int(&philo_data->data_mutex, &philo_data->sim_ended, 1);


}
