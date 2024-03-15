/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sim.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelsa <mabdelsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 09:28:01 by mahmoud           #+#    #+#             */
/*   Updated: 2024/03/15 15:11:24 by mabdelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(t_philo *philos)
{
	mutex_ops(&philos->right_fork->fork, "LOCK");
	mutex_ops(&philos->left_fork->fork, "LOCK");
	print_philo_status(philos, "TOOK_FORK");
	set_int(&philos->data->data_mutex, &philos->right_fork->fork_id,
		philos->id);
	set_int(&philos->data->data_mutex, &philos->left_fork->fork_id, philos->id);
	print_philo_status(philos, "TOOK_FORK");
	philos->left_fork->fork_id = philos->id;
	set_long(&philos->philos_mutex, &philos->last_meal, get_current_time());
	increment_long(&philos->philos_mutex, &philos->meals_eaten);
	print_philo_status(philos, "EATING");
	ft_usleep(philos->data->time_to_eat);
	if (philos->data->no_of_meals > 0
		&& philos->meals_eaten == philos->data->no_of_meals)
		set_int(&philos->philos_mutex, &philos->is_full, 1);
	mutex_ops(&philos->right_fork->fork, "UNLOCK");
	mutex_ops(&philos->left_fork->fork, "UNLOCK");
}

void	*one_philo(void *data)
{
	t_philo	*philos;

	philos = (t_philo *)data;
	sync_threads(philos->data);
	philos->last_meal = get_current_time();
	philos->data->no_of_threads_running++;
	print_philo_status(philos, "TOOK_FORK");
	while (simulation_ended(philos->data) == 0)
		ft_usleep(100);
	return (NULL);
}

void	*dinner_sim(void *philos_data)
{
	t_philo	*philos;

	philos = (t_philo *)philos_data;
	sync_threads(philos->data);
	set_long(&philos->philos_mutex, &philos->last_meal, get_current_time());
	increment_long(&philos->data->data_mutex,
		&philos->data->no_of_threads_running);
	while (simulation_ended(philos->data) == 0)
	{
		is_greedy(philos);
		if (get_int(&philos->philos_mutex, &philos->is_full) == 1)
			break ;
		if (get_int(&philos->philos_mutex, &philos->is_greedy) == 0)
			eat(philos);
		print_philo_status(philos, "SLEEPING");
		ft_usleep(philos->data->time_to_sleep);
		print_philo_status(philos, "THINKING");
	}
	return (NULL);
}

void	create_threads2(t_data *philo_data)
{
	int	i;

	i = 0;
	if (philo_data->no_of_meals == 0)
		return ;
	else if (philo_data->no_of_philos == 1)
		thread_ops(&philo_data->philos[0].thread_id, one_philo,
			&philo_data->philos[0], "CREATE");
	else
	{
		while (i < philo_data->no_of_philos)
		{
			thread_ops(&philo_data->philos[i].thread_id, dinner_sim,
				&philo_data->philos[i], "CREATE");
			i++;
		}
	}
}

void	create_threads(t_data *philo_data)
{
	int	i;

	create_threads2(philo_data);
	thread_ops(&philo_data->monitor_thread, monitor_sim, philo_data, "CREATE");
	philo_data->start_time = get_current_time();
	set_int(&philo_data->data_mutex, &philo_data->all_threads_ready, 1);
	i = 0;
	while (i < philo_data->no_of_philos)
	{
		thread_ops(&philo_data->philos[i].thread_id, NULL, NULL, "JOIN");
		i++;
	}
	thread_ops(&philo_data->monitor_thread, NULL, NULL, "JOIN");
	set_int(&philo_data->data_mutex, &philo_data->sim_ended, 1);
}
