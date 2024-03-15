/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_greedy_philo.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahmoud <mahmoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:12:31 by mahmoud           #+#    #+#             */
/*   Updated: 2024/03/14 11:07:53 by mahmoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void is_greedy(t_philo *philos)
{
    mutex_ops(&philos->data->data_mutex, "LOCK");
    if ((philos->left_fork->fork_id == philos->id) ||
        philos->right_fork->fork_id == philos->id)
    {
        mutex_ops(&philos->data->data_mutex, "UNLOCK");
        set_int(&philos->philos_mutex, &philos->is_greedy, 1);
    }
    else
    {
        mutex_ops(&philos->data->data_mutex, "UNLOCK");
        set_int(&philos->philos_mutex, &philos->is_greedy, 0);
    }
}