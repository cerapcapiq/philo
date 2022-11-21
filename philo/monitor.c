/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasarud <abasarud@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 14:58:40 by abasarud          #+#    #+#             */
/*   Updated: 2022/11/14 10:24:34 by abasarud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	*ft_monitor(void *philo_v)
{
	t_phil	*phil;

	phil = (t_phil *)philo_v;
	while (1)
	{
		pthread_mutex_lock(&phil->mutex);
		if (!phil->eat_nu && time_taken() > phil->limit)
		{
			ft_message(phil, 4);
			pthread_mutex_unlock(&phil->mutex);
			pthread_mutex_unlock(&phil->value->dead_mutex);
			return ((void *)0);
		}
		pthread_mutex_unlock(&phil->mutex);
		usleep(1000);
	}
}

static void	*m_count(void *value_v)
{
	t_value	*value;
	int		i;
	int		total;

	value = (t_value *)value_v;
	total = 0;
	while (total < value->eat_freq)
	{
		i = 0;
		while (i < value->persons)
			pthread_mutex_lock(&value->phil[++i].eat_m);
		total++;
	}
	ft_message(&value->phil[0], 5);
	pthread_mutex_unlock(&value->dead_mutex);
	return ((void *)0);
}

static void	*routine(void *philo_v)
{
	t_phil		*phil;
	pthread_t	tid;

	phil = (t_phil *)philo_v;
	phil->last_ate = time_taken();
	phil->limit = phil->last_ate + phil->value->time_to_die;
	if (pthread_create(&tid, NULL, &ft_monitor, philo_v) != 0)
		return ((void *)1);
	pthread_detach(tid);
	while (1)
	{
		use_forks(phil);
		eat(phil);
		forks_done(phil);
		ft_message(phil, THINKING);
	}
	return ((void *)0);
}

int	start_thread(t_value *value)
{
	pthread_t	tid;
	int			i;
	void		*phil;

	value->start = time_taken();
	if (value->eat_freq > 0)
	{
		if (pthread_create(&tid, NULL, &m_count, (void *)value) != 0)
			return (1);
		pthread_detach(tid);
	}
	i = 0;
	while (i < value->persons)
	{
		phil = (void *)(&value->phil[i]);
		if (pthread_create(&tid, NULL, &routine, phil) != 0)
			return (1);
		pthread_detach(tid);
		usleep(100);
		i++;
	}
	return (0);
}
