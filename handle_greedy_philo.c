/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_greedy_philo.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahmoud <mahmoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:12:31 by mahmoud           #+#    #+#             */
/*   Updated: 2024/03/13 12:23:07 by mahmoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int is_greedy(t_philo *philos)
{
    if ((philos->left_fork->fork_id == philos->id) ||
        philos->right_fork->fork_id == philos->id)
    {
        return (1);
    }
    return (0);
}