/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasarud <abasarud@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 14:58:30 by abasarud          #+#    #+#             */
/*   Updated: 2022/11/14 11:41:32 by abasarud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	init_mutex(t_value *value)
{
	int	i;

	pthread_mutex_init(&value->write_m, NULL);
	pthread_mutex_init(&value->dead_mutex, NULL);
	pthread_mutex_lock(&value->dead_mutex);
	value->forks_m
		= (pthread_mutex_t *)malloc(sizeof(*(value->forks_m)) * value->persons);
	if (!value->forks_m)
		return (1);
	i = 0;
	while (value->persons > i)
		pthread_mutex_init(&value->forks_m[i++], NULL);
	return (0);
}

void	ft_init_action(t_value *value)
{
	int	i;

	i = 0;
	while (i < value->persons)
	{
		value->phil[i].eat_nu = 0;
		value->phil[i].position = i;
		value->phil[i].left = i;
		value->phil[i].right = (i + 1) % value->persons;
		value->phil[i].eat_count = 0;
		value->phil[i].value = value;
		pthread_mutex_init(&value->phil[i].mutex, NULL);
		pthread_mutex_init(&value->phil[i].eat_m, NULL);
		pthread_mutex_lock(&value->phil[i].eat_m);
		i++;
	}
}

int	init_thread(t_value *value, int ac, char *av[])
{
	value->persons = ft_atoi(av[1]);
	value->time_to_die = ft_atoi(av[2]);
	value->time_to_eat = ft_atoi(av[3]);
	value->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		value->eat_freq = ft_atoi(av[5]);
	else
		value->eat_freq = 0;
	if (value->persons < 2 || value->persons > 200 || value->time_to_die < 60
		|| value->time_to_eat < 60 || value->time_to_sleep < 60
		|| value->eat_freq < 0)
		return (1);
	value->forks_m = NULL;
	value->phil = NULL;
	value->phil = (t_phil *)malloc(sizeof(*(value->phil)) * value->persons);
	if (!value->phil)
		return (1);
	ft_init_action(value);
	return (init_mutex(value));
}
