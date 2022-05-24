/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngda-sil <ngda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 16:31:59 by tracy             #+#    #+#             */
/*   Updated: 2022/05/24 23:23:22 by ngda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

# define ARGS "./philo nb_philo time_to_die time_to_eat time_to_sleep \
	[nb_of_times_each_philo_must_eat]"
# define INIT "Problem initializing philosophers." 
# define DATA "Problem data."
# define SIM "Problem during simulation."
# define LEFT "T : %.1fms | Philo n˚%d : has taken the left fork.\n"
# define RIGHT "T : %.1fms | Philo n˚%d : has taken the right fork.\n"
# define EAT "\033[0;32mT : %.1fms | Philo n˚%d : is eating.\033[0m\n"
# define SLEEP "\033[0;36mT : %.1fms | Philo n˚%d : is sleeping.\033[0m\n"
# define THINK "\033[0;35mT : %.1fms | Philo n˚%d : is thinking.\033[0m\n"
# define DEATH "\033[1m\033[31mT : %.1fms | Philo n˚%d : DIED.\033[0m\n"

typedef struct s_data	t_data;

typedef struct s_philo
{
	int				id;
	double			t_last_meal;
	int				nb_meal;
	int				is_alive;
	pthread_t		philo;
	pthread_mutex_t	l_fork;
	pthread_mutex_t	*r_fork;
	t_data			*data;
}	t_philo;

typedef struct s_data
{
	int				nb_philo;
	int				t_death;
	int				t_eat;
	int				t_sleep;
	int				nb_m_eat;
	double			start;
	double			now;
	int				death;
	pthread_mutex_t	print;
	t_philo			*p;
}	t_data;

// init
int			check_args(int ac, char **av);
int			init_philo(t_data *a);
int			init_data(int ac, char **av, t_data *a);
//life_of_a_philosopher
int			ft_fork(t_philo *p);
int			ft_sleep(t_philo *p);
//routine
int			start_sim(t_data *a);
//time
void		start_timer(t_data *a);
double		what_time_is_it(t_data *a);
int			print_log(t_philo *p, char *str);
//utils
int			ft_atoi(const char *str);
int			ft_isdigit(int c);
void		*ft_calloc(size_t count, size_t size);
//utils2
int			str_error(char *s, int ret);

#endif
