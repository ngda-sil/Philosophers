/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngda-sil <ngda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 20:42:10 by ngda-sil          #+#    #+#             */
/*   Updated: 2022/07/19 00:18:18 by ngda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo	*p;
	t_data	*a;

	p = arg;
	a = p->data;
	if (p->id % 2 != 0)
		ft_usleep(a->t_eat, a);
	while (a->full < a->nb_philo && !a->death)
	{
		if (ft_fork(a, p))
			break ;
		ft_sleep(a, p);
	}
	return (NULL);
}

void	*checker(void *arg)
{
	t_data	*a;
	int		i;

	a = arg;
	i = 0;
	while (a->full < a->nb_philo && !a->death)
	{
		pthread_mutex_lock(&a->state);
		if ((what_time_is_it(a) - a->p[i].t_last_m) > a->t_death)
		{
			a->death = 1;
			printf(DEATH, what_time_is_it(a), a->p[i].id);
		}
		pthread_mutex_unlock(&a->state);
		i++;
		if (i == a->nb_philo)
			i = 0;
	}
	return (NULL);
}

int	start_sim(t_data *a)
{
	int	i;

	i = -1;
	start_timer(a);
	while (++i < a->nb_philo)
		if (pthread_create(&a->p[i].philo, NULL, &routine, &a->p[i]))
			return (1);
	if (pthread_create(&a->checker, NULL, &checker, a))
		return (1);
	i = -1;
	while (++i < a->nb_philo)
		pthread_join(a->p[i].philo, NULL);
	pthread_join(a->checker, NULL);
	if (clean(a))
		return (1);
	return (0);
}
