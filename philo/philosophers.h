/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasarud <abasarud@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 14:58:42 by abasarud          #+#    #+#             */
/*   Updated: 2022/11/17 13:08:00 by abasarud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <stdio.h>

# define RED "\x1B[0;31m"
# define GRN "\x1B[32m"
# define YEL "\x1B[33m"
# define CYN "\x1B[36m"
# define WHI "\x1B[37m"
# define NC "\x1B[0m"

# define EATING     0
# define SLEEPING   1
# define THINKING   2
# define FORK       3
# define DEAD       4
# define DONE       5

struct	s_state;

typedef struct s_phil
{
	int				position;
	int				eat_nu;
	int				limit;
	int				last_ate;
	int				left;
	int				right;
	int				eat_count;
	pthread_mutex_t	mutex;
	pthread_mutex_t	eat_m;

	struct s_value	*value;
}	t_phil;

typedef struct s_value
{
	int				persons;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_to_die;
	int				eat_freq;
	int				start;

	pthread_mutex_t	dead_mutex;
	pthread_mutex_t	*forks_m;
	pthread_mutex_t	write_m;

	t_phil			*phil;
}	t_value;

void	err_msg(int error);

int		input_arg(char *av[]);

void	ft_free_data(t_value *value);

int		clear_value(t_value *value);

void	eat(t_phil *phil);

void	use_forks(t_phil *phil);

void	forks_done(t_phil *phil);

int		start_thread(t_value *value);

void	ft_message(t_phil *phil, int type);

int		time_taken(void);

int		init_thread(t_value *value, int ac, char *av[]);

void	ft_putnbr_fd(int n, int fd);

int		ft_atoi(const char *str);

int		ft_strlen(char const *str);

int		ft_error(int error);

int		ft_input(char **av);

#endif
