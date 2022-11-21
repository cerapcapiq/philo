/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasarud <abasarud@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 16:00:05 by abasarud          #+#    #+#             */
/*   Updated: 2022/11/14 11:37:47 by abasarud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_strlen(char const *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		i++;
	}
	return (i);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			write(fd, "-", 1);
			n = -n;
			ft_putnbr_fd(n, fd);
		}
		else if (n < 10)
		{
			c = n + '0';
			write(fd, &c, 1);
		}
		else
		{
			ft_putnbr_fd(n / 10, fd);
			c = (n % 10) + '0';
			write(fd, &c, 1);
		}
	}
}

int	ft_atoi(const char *str)
{
	long	num;
	int		sign;
	int		i;

	i = 0;
	sign = 1;
	num = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '-')
		sign = sign * -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + str[i] - '0';
		i++;
		if (num * sign > 2147483647)
			return (-1);
		if (num * sign < -2147483648)
			return (0);
	}
	return (num * sign);
}

int	time_taken(void)
{
	static struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * (int)1000) + (tv.tv_usec / 1000));
}
