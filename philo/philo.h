/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tracy <tracy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 16:31:59 by tracy             #+#    #+#             */
/*   Updated: 2022/05/24 01:53:41 by tracy            ###   ########.fr       */
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

# define ARGS "./philo nb_philo time_to_die time_to_eat time_to_sleep [nb_of_times_each_philo_must_eat]"
# define INIT "Problem initializing philosophers." 

typedef struct s_philo
{
	int				id;
	int				t_last_meal;
	int				nb_meal;
	bool			is_alive;
	pthread_mutex_t	l_fork;
	pthread_mutex_t	*r_fork;
}	t_philo;

typedef struct s_data
{
	int	nb_philo;
	int	t_death;
	int	t_eat;
	int	t_sleep;
	int	nb_m_eat;
	t_philo	*p;
}	t_data;

// init
int		check_args(int ac, char **av);
int		init_philo(t_data *a);
void	init_data(int ac, char **av, t_data *a);
//routine
void	start_sim(t_data *a);
//utils
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
void	*ft_calloc(size_t count, size_t size);
//utils2
int		str_error(char *s, int ret);

#endif
