/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelsa <mabdelsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 09:00:22 by mahmoud           #+#    #+#             */
/*   Updated: 2024/03/15 14:53:13 by mabdelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data	philo_data;

	if (ac < 5 || ac > 6)
		return (ft_putstr_fd("\033[1;31mInvalid input format.\033[0m\n", 2), 1);
	if (validate_input(av) == 1)
		return (1);
	insert_general_data(&philo_data, av);
	insert_philo_data(&philo_data);
	create_threads(&philo_data);
	free_all(&philo_data);
}
