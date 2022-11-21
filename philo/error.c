/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasarud <abasarud@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 14:58:26 by abasarud          #+#    #+#             */
/*   Updated: 2022/11/17 13:33:45 by abasarud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	clear_value(t_value *value)
{
	int	i;

	if (value->forks_m)
	{
		i = 0;
		while (i < value->persons)
			pthread_mutex_destroy(&value->forks_m[i++]);
		free(value->forks_m);
	}
	if (value->phil)
	{
		i = 0;
		while (i < value->persons)
		{
			pthread_mutex_destroy(&value->phil[i].mutex);
			pthread_mutex_destroy(&value->phil[i++].eat_m);
		}
		free(value->phil);
	}
	pthread_mutex_destroy(&value->write_m);
	pthread_mutex_destroy(&value->dead_mutex);
	return (1);
}

void	err_msg(int error)
{
	printf(RED);
	printf("Error\n");
	if (error == -1)
		printf("invalid arg\n");
	else if (error == -2)
		printf("threads exceeded!\n");
	else if (error == -3)
		printf("fail to create thread\n");
	else if (error == -4)
		printf("pthread join failed!\n");
	else if (error == -5)
		printf("Setup failed!\n");
}

int	ft_isnbr(char *nbr)
{
	if (!nbr)
		return (0);
	if (*nbr == '+' || *nbr == '-')
		nbr++;
	while (*nbr)
	{
		if (*nbr < '0' || *nbr > '9')
			return (0);
		if (*nbr >= '0' && *nbr <= '9')
			nbr++;
	}
	return ((*nbr == 0));
}

int	ft_input(char **av)
{
	int	i;

	i = 0;
	while (av[++i])
	{
		if (!ft_isnbr(av[i]) || ft_atoi(av[i]) < 0)
			return (0);
	}
	return (1);
}

int	ft_error(int error)
{
	err_msg(error);
	return (1);
}
