/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tracy <tracy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 13:48:36 by ngda-sil          #+#    #+#             */
/*   Updated: 2022/05/25 03:21:05 by tracy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo	*b;

	b = (void *)arg;
	if (b->id % 2 != 0)
		usleep(100);
	while (42)
	{
		ft_fork(b);
		ft_sleep(b);
	}
	return (NULL);
}

int	is_everybody_alive(t_data *a)
{
	int		i;
	double	now;

	i = -1;
	while (++i < a->nb_philo)
	{
		now = what_time_is_it(a);
		if (now - a->p[i].t_last_meal >= a->t_death)
		{
			a->death = 1;
			print_log(&a->p[i], DEATH);
			if (pthread_mutex_lock(&a->print))
				return (1);
			return (0);
		}
	}
	return(0);
}

int	has_everybody_eaten(t_data *a)
{
	int		i;

	i = -1;
	while (++i < a->nb_philo)
	{
		if (a->p[i].nb_meal == a->nb_m_eat && !a->p[i].is_full)
		{
			a->full++;
			a->p[i].is_full = 1;
		}
		if (a->nb_philo == a->full)
		{
			if (pthread_mutex_lock(&a->print))
				return (1);
			return (0);
		}
	}
	return (0);
}

int	start_sim(t_data *a)
{
	int			i;

	start_timer(a);
	i = -1;
	while (++i < a->nb_philo)
		if (pthread_create(&a->p[i].philo, NULL, &routine, &a->p[i]))
			return (1);
	while (!a->death && a->full != a->nb_philo)
		if(is_everybody_alive(a) || has_everybody_eaten(a))
			return (1);
	/*i = -1;
	while (++i < a->nb_philo)
	{
		if (pthread_join(a->p[i].philo, NULL))
			return (1);
	}*/
	free(a->p);
	return (0);
}
