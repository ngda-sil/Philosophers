/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tracy <tracy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 16:31:59 by tracy             #+#    #+#             */
/*   Updated: 2022/05/23 17:44:06 by tracy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

# define ARGS "./philo nb_philo time_to_die time_to_eat time_to_sleep [nb_of_times_each_philo_must_eat]" 
typedef struct s_philo
{
	int		nb_forks;
}	t_philo;

typedef struct s_data
{
	int	nb_philo;
	int	t_death;
	int	t_eat;
	int	t_sleep;
	int	nb_m_eat;
}	t_data;

// error
int	check_args(int ac, char **av, t_data *a);


#endif
