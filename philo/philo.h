/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngda-sil <ngda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 17:43:45 by ngda-sil          #+#    #+#             */
/*   Updated: 2022/07/18 23:56:42 by ngda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

# define RED "\033[31m"
# define LEFT "%.1fms | Philo n˚%d : has taken the left fork.\n"
# define RIGHT "%.1fms | Philo n˚%d : has taken the right fork.\n"
# define EAT "\033[0;32m%.1fms | Philo n˚%d : is eating his %d meal.\033[0m\n"
# define SLEEP "\033[0;36m%.1fms | Philo n˚%d : is sleeping.\033[0m\n"
# define THINK "\033[0;35m%.1fms | Philo n˚%d : is thinking.\033[0m\n"
# define DEATH "\033[1m\033[31m%.1fms | Philo n˚%d : DIED.\033[0m\n"

typedef struct s_data	t_data;
typedef struct s_philo
{
	int				id;
	double			t_last_m;
	int				nb_meal;
	int				full;
	pthread_t		philo;
	t_data			*data;
}	t_philo;

typedef struct s_data
{
	int				nb_philo;
	double			t_death;
	int				t_eat;
	int				t_sleep;
	int				nb_m_eat;
	int				full;
	int				death;
	double			start;
	double			now;
	pthread_t		checker;
	pthread_mutex_t	*fork;
	pthread_mutex_t	eat;
	pthread_mutex_t	log;
	pthread_mutex_t	print;
	pthread_mutex_t	state;
	t_philo			*p;
}	t_data;

// init.c
int		check_args(int ac, char **av);
void	init_data(int ac, char **av, t_data *a);
int		init_mutex(t_data *a);
int		init_philo(t_data *a);

//life_of_a_philosopher.c
int		ft_eat(t_data *a, t_philo *p);
int		ft_fork(t_data *a, t_philo *p);
int		ft_sleep(t_data *a, t_philo *p);

// routine.c
int		start_sim(t_data *a);
// time.c
int		print_log(t_data *a, t_philo *p, char *str);
double	what_time_is_it(t_data *a);
void	start_timer(t_data *a);
void	ft_usleep(double time, t_data *a);

// utils.c
int		ft_isdigit(int c);
int		str_error(char *s, int ret);
long	atol_pos(char *str);
void	*ft_calloc(size_t count, size_t size);

// c_du_propre.c
int		clean(t_data *a);

#endif
