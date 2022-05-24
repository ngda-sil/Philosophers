/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngda-sil <ngda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 13:48:36 by ngda-sil          #+#    #+#             */
/*   Updated: 2022/05/24 23:23:17 by ngda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo	*b;

	b = (void *)arg;
	if (b->id % 2 != 0)
		usleep(200);
	while (42)
	{
		ft_fork(b);
		ft_sleep(b);
	}
	return (NULL);
}

void	is_everybody_alive(t_data *a)
{
	int		i;

	i = 0;
	while (a->p[i].is_alive == 0)
	{
		if (a->p[i].t_last_meal >= a->t_death)
		{
			a->p[i].is_alive = 1;
			print_log(&a->p[i], DEATH);
			pthread_mutex_lock(&a->print);
		}
		if (i == a->nb_philo)
			i = 0;
		else
			i++;
	}
}

int	start_sim(t_data *a)
{
	int			i;

	start_timer(a);
	i = -1;
	while (++i < a->nb_philo)
		if (pthread_create(&a->p[i].philo, NULL, &routine, &a->p[i]))
			return (1);
	is_everybody_alive(a);
	/*i = -1;
	while (++i < a->nb_philo)
		if (pthread_join(a->p[i].philo, NULL))
			return (1);*/
	return (0);
}
