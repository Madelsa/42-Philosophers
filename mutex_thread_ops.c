/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_thread_ops.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahmoud <mahmoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 11:21:33 by mahmoud           #+#    #+#             */
/*   Updated: 2024/03/13 15:08:42 by mahmoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void mutex_ops(pthread_mutex_t *mutex, char *operation)
{
    if (ft_strcmp(operation, "LOCK") == 0)
        pthread_mutex_lock(mutex);
    else if (ft_strcmp(operation, "UNLOCK") == 0)
        pthread_mutex_unlock(mutex);
    else if (ft_strcmp(operation, "INIT") == 0)
        pthread_mutex_init(mutex, NULL);
    else if (ft_strcmp(operation, "DESTROY") == 0)
        pthread_mutex_destroy(mutex);
    else
        return (ft_putstr_fd
                ("\033[1;31mOperation not found.\033[0m\n", 2));
}

void	thread_ops(pthread_t *thread, void *(*func)(void *),
		void *data, char *operation)
{
	if (ft_strcmp(operation, "CREATE") == 0)
		pthread_create(thread, NULL, func, data);
	else if (ft_strcmp(operation, "JOIN") == 0)
		pthread_join(*thread, NULL);
	else
		return (ft_putstr_fd
                ("\033[1;31mOperation not found.\033[0m\n", 2));
}