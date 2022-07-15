/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngda-sil <ngda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 20:42:10 by ngda-sil          #+#    #+#             */
/*   Updated: 2022/07/15 20:29:18 by ngda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo	*b;

	b = (void *)arg;
	if (b->id % 2 != 0)
		usleep(b->data->t_eat / 2);
	while (!b->data->death || b->data->nb_philo == b->data->full)
	{
		ft_fork(b->data, b);
		ft_sleep(b);
	}
	return (NULL);
}

void	*checker(void *arg)
{
	t_philo	*c;
	t_data  *b;
	int		i;
	int		j;

	c = arg;		
	b = c->data;
	i = 0;
	j = -1;
	while (1)
	{
		b->now = what_time_is_it(b);
		if (( b->now - b->p[i].t_last_m) > b->t_death)
		{
			b->death = 1;
			printf(DEATH, what_time_is_it(b), b->p[i].id);
			break;
		}
		if (b->p[i].nb_meal == b->nb_m_eat && !b->p[i].full)
		{
			b->full++;
			b->p[i].full = 1;
		}
		if (b->nb_philo == b->full)
		{
			break;
		}
		i++;
		if (i == b->nb_philo)
			i = 0;
	}
	return (NULL);
}

int	start_sim(t_data *a, t_philo *p)
{
	(void)p;
	int			i;

	i = -1;
	start_timer(a);
	while (++i < a->nb_philo)
	{
		if (pthread_create(&a->p[i].philo, NULL, &routine, &a->p[i]))
			return (1);
	}
	if (pthread_create(&a->checker, NULL, &checker, &a->p[0]))
			return (1);
	i = -1;
	while (++i < a->nb_philo)
		pthread_join(a->p[i].philo, NULL);	
	pthread_join(a->checker, NULL);
	free(a->fork);
	free(a->p);
	// destroy mutex
	return (0);
}
