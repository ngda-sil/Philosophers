/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngda-sil <ngda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 13:48:36 by ngda-sil          #+#    #+#             */
/*   Updated: 2022/06/04 00:38:45 by ngda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo	*b;

	b = (void *)arg;
	if (b->id % 2 != 0)
		usleep(25000);
	while (!b->data->death)
	{
		ft_fork(b);
		if (b->data->nb_philo == b->data->full)
			break;
		ft_sleep(b);
	}
	return (NULL);
}

int	is_everybody_alive(t_data *a)
{
	int		i;

	i = -1;
	while (++i < a->nb_philo)
	{
		if (what_time_is_it(a) - a->p[i].t_last_meal >= a->t_death)
		{
			a->death = 1;
			if (pthread_mutex_lock(&a->print))
				return (1);
			printf(DEATH, what_time_is_it(a), a->p[i].id);
				return (0);
		}
	}
	return (0);
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

	i = -1;
	start_timer(a);
	while (++i < a->nb_philo)
	{
		if (pthread_create(&a->p[i].philo, NULL, &routine, &a->p[i]))
			return (1);
		
	}
	while (!a->death && a->full != a->nb_philo)
	{
		/*if (a->nb_m_eat != -1)
			if (has_everybody_eaten(a))
				return (1);*/
		if (is_everybody_alive(a))
			return (1);
		usleep(2500);
	}
	/*i = -1;
	while (++i < a->nb_philo)
	{
		if (pthread_join(a->p[i].philo, NULL))
			return (1);
	}*/
	free(a->p);
	return (0);
}
