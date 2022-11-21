/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasarud <abasarud@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 14:58:28 by abasarud          #+#    #+#             */
/*   Updated: 2022/11/14 10:22:33 by abasarud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	eat(t_phil *phil)
{
	pthread_mutex_lock(&phil->mutex);
	phil->eat_nu = 1;
	phil->last_ate = time_taken();
	phil->limit = phil->last_ate + phil->value->time_to_die;
	ft_message(phil, 0);
	usleep(phil->value->time_to_eat * 1000);
	phil->eat_count++;
	phil->eat_nu = 0;
	pthread_mutex_unlock(&phil->mutex);
	pthread_mutex_unlock(&phil->eat_m);
}

void	use_forks(t_phil *phil)
{
	pthread_mutex_lock(&phil->value->forks_m[phil->left]);
	ft_message(phil, FORK);
	pthread_mutex_lock(&phil->value->forks_m[phil->right]);
	ft_message(phil, FORK);
}

void	forks_done(t_phil *phil)
{
	ft_message(phil, 1);
	pthread_mutex_unlock(&phil->value->forks_m[phil->left]);
	pthread_mutex_unlock(&phil->value->forks_m[phil->right]);
	usleep(phil->value->time_to_sleep * 1000);
}
