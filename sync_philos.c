/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sync_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahmoud <mahmoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 10:07:16 by mahmoud           #+#    #+#             */
/*   Updated: 2024/03/11 10:08:43 by mahmoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void sync_threads(t_data *philo_data)
{
    while (1)
	{
        if (get_int(&philo_data->data_mutex, &philo_data->sim_ended) == 1)
            break;
    }
}