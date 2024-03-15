/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelsa <mabdelsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 10:07:31 by mahmoud           #+#    #+#             */
/*   Updated: 2024/03/15 14:59:32 by mabdelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_sign(char *str)
{
	int	i;
	int	sign_count;

	i = 0;
	sign_count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '-' || str[i] == '+')
		{
			sign_count++;
			if (i != 0 || ft_isdigit(str[i + 1]) == 0 || sign_count > 1)
				return (ft_putstr_fd(
						"\033[1;31mToo many/wrong sign placement.\033[0m\n", 2),
					1);
		}
		else if (ft_isdigit(str[i]) == 0)
			return (ft_putstr_fd(
					"\033[1;31mNon-digit character found.\033[0m\n", 2),
				1);
		i++;
	}
	return (0);
}

int	validate_input(char **av)
{
	int	i;

	i = 1;
	if (av[1][0] == '-' || ft_atol(av[1]) == 0)
		return (ft_putstr_fd("\033[1;31mNo. \
        of Philosophers must be greater than 0.\033[0m\n", 2), 1);
	while (av[i] != NULL)
	{
		if ((ft_strcmp(av[i], "0") != 0 && ft_atol(av[i]) == 0)
			|| (ft_strcmp(av[i], "-1") != 0 && ft_atol(av[i]) == -1))
			return (ft_putstr_fd("\033[1;31mInput \
            overflowed (> INT_MAX or < 0).\033[0m\n", 2), 1);
		if (ft_atol(av[i]) > INT_MAX || ft_atol(av[i]) < 0)
			return (ft_putstr_fd("\033[1;31mValue \
            > than INT_MAX or < than 0.\033[0m\n", 2), 1);
		if (check_sign(av[i]) == 1)
			return (1);
		i++;
	}
	return (0);
}
