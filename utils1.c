/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahmoud <mahmoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 10:03:09 by mahmoud           #+#    #+#             */
/*   Updated: 2024/03/09 11:16:04 by mahmoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static long	process_digits_atol(const char *str, int sign, int i)
{
	long	result;
	long	prev;

	result = 0;
	prev = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		prev = result;
		result = result * 10 + str[i++] - '0';
		if (prev > result)
		{
			if (sign < 0)
				return (0);
			else
				return (-1);
		}
	}
	return (result * sign);
}

long	ft_atol(const char *str)
{
	int	sign;
	int	i;

	if (str == NULL)
		return (0);
	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] == '0')
		i++;
	return (process_digits_atol(str, sign, i));
}

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}

int	ft_isdigit(int x)
{
	if (x >= '0' && x <= '9')
		return (1);
	else
		return (0);
}