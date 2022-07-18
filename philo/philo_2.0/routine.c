/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngda-sil <ngda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 20:42:10 by ngda-sil          #+#    #+#             */
/*   Updated: 2022/07/18 17:18:50 by ngda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo	*b;

	b = (void *)arg;
	if (b->id % 2 != 0)
		ft_usleep(b->data->t_eat, b->data);
	while (b->data->nb_philo > b->data->full && !b->data->death)
	{
		if (ft_fork(b->data, b))
			break ;
		ft_sleep(b);
	}
	return (NULL);
}

void	*checker(void *arg)
{
	t_data	*b;
	int		i;
	int		j;

	b = (t_data *)arg;
	i = 0;
	j = -1;
	while (b->full < b->nb_philo && !b->death)
	{
		pthread_mutex_lock(&b->state);
		if ((what_time_is_it(b) - b->p[i].t_last_m) > b->t_death)
		{
			//printf("philo(%d) : (%f)-(%f)=(%f) vs (%f)\n", b->p[i].id, what_time_is_it(b), b->p[i].t_last_m, (what_time_is_it(b) - b->p[i].t_last_m), b->t_death);
			b->death = 1;
			printf(DEATH, what_time_is_it(b), b->p[i].id);
		}
		pthread_mutex_unlock(&b->state);
		i++;
		if (i == b->nb_philo)
			i = 0;
	}
	return (NULL);
}

void	destroy_the_mutexes(t_data *a)
{
	int	i;

	i = -1;
	pthread_mutex_destroy(&a->print);
	pthread_mutex_destroy(&a->state);
	while (++i < a->nb_philo)
		pthread_mutex_destroy(&a->fork[i]);
}

int	start_sim(t_data *a, t_philo *p)
{
	(void)p;
	int	i;

	i = -1;
	start_timer(a);
	while (++i < a->nb_philo)
	{
		if (pthread_create(&a->p[i].philo, NULL, &routine, &a->p[i]))
			return (1);
	}
	if (pthread_create(&a->checker, NULL, &checker, a))
		return (1);
	i = -1;
	while (++i < a->nb_philo)
		pthread_join(a->p[i].philo, NULL);
	pthread_join(a->checker, NULL);
	destroy_the_mutexes(a);
	free(a->fork);
	free(a->p);
	return (0);
}
