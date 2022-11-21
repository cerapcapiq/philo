/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasarud <abasarud@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 14:58:38 by abasarud          #+#    #+#             */
/*   Updated: 2022/11/14 11:34:23 by abasarud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static char	*display_message(int type)
{
	if (type == 2)
		return ("\033[0;32m is thinking\033[0m\n");
	else if (type == 1)
		return ("\033[0;34m  is sleeping\033[0m\n");
	else if (type == 3)
		return ("\033[0;36m is using forks\033[0m\n");
	else if (type == 0)
		return ("\033[1;35m is eating\033[0m\n");
	else if (type == 5)
		return ("\033[1;33m eat amount done\n");
	else if (type == 4)
		return ("\033[1;31m is dead\n");
	return (0);
}

void	ft_message(t_phil *phil, int type)
{
	static int	done = 0;

	pthread_mutex_lock(&phil->value->write_m);
	if (!done)
	{
		ft_putnbr_fd(time_taken() - phil->value->start, 1);
		write (1, " ", 1);
		if (type != 5)
			ft_putnbr_fd(phil->position + 0, 1);
		if (type >= 4)
			done = 1;
		write(1, display_message(type), ft_strlen(display_message(type)));
	}
	pthread_mutex_unlock(&phil->value->write_m);
}
