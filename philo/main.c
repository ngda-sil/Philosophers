/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngda-sil <ngda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 17:45:35 by ngda-sil          #+#    #+#             */
/*   Updated: 2022/07/18 23:56:38 by ngda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data	a;

	if (check_args(ac, av))
		return (1);
	init_data(ac, av, &a);
	if (init_mutex(&a))
		return (1);
	if (init_philo(&a))
	{
		clean(&a);
		return (str_error("Problem initializing philos", 1));
	}
	if (start_sim(&a))
		return (str_error("Problem during simulation", 1));
	return (0);
}
