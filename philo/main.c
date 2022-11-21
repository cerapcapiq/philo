/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasarud <abasarud@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 14:58:33 by abasarud          #+#    #+#             */
/*   Updated: 2022/11/17 13:34:42 by abasarud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int ac, char *av[])
{
	t_value	value;

	if (!((ac == 5 || ac == 6) && ft_input(av)))
		return (ft_error(-1));
	if (init_thread(&value, ac, av))
		return (clear_value(&value) && ft_error(-2));
	if (start_thread(&value))
		return (clear_value(&value) && ft_error(-3));
	pthread_mutex_lock(&value.dead_mutex);
	pthread_mutex_unlock(&value.dead_mutex);
	clear_value(&value);
	return (0);
}
