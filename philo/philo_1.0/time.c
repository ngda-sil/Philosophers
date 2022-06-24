/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngda-sil <ngda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 16:01:00 by ngda-sil          #+#    #+#             */
/*   Updated: 2022/06/04 00:38:48 by ngda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_timer(t_data *a)
{
	struct timeval	start;

	gettimeofday(&start, NULL);
	a->start = start.tv_sec * 1000 + start.tv_usec / 1000;
}

double	what_time_is_it(t_data *a)
{
	struct timeval	start;

	gettimeofday(&start, NULL);
	a->now = start.tv_sec * 1000 + start.tv_usec / 1000;
	return (a->now - a->start);
}

int	print_log(t_philo *p, char *str)
{
	if (pthread_mutex_lock(&p->data->print))
		return (1);
	printf(str, what_time_is_it(p->data), p->id, p->nb_meal);
	if (pthread_mutex_unlock(&p->data->print))
		return (1);
	return (0);
}

void	ft_usleep(double time, t_data *a)
{
	double	zero;

	zero = what_time_is_it(a);
	while (!a->death)
	{
		usleep(50);
		if (what_time_is_it(a) - zero >= time)
			break ;
	}
}
