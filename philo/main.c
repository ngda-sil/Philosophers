/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tracy <tracy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 16:38:51 by tracy             #+#    #+#             */
/*   Updated: 2022/05/24 01:54:28 by tracy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data	a;

	if (check_args(ac, av))
		return (str_error(ARGS, 1));
	init_data(ac, av, &a);
	if (init_philo(&a))
		return (str_error(INIT, 1));
	//start_sim(&a);
	return (0);
}