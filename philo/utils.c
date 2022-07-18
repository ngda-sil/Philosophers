/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngda-sil <ngda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 17:54:58 by ngda-sil          #+#    #+#             */
/*   Updated: 2022/07/18 23:54:33 by ngda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}

int	str_error(char *s, int ret)
{
	printf(RED"%s\n", s);
	return (ret);
}

long	atol_pos(char *str)
{
	long	res;
	int		i;

	i = 0;
	res = 0;
	while (str[i])
	{
		res = res * 10 + (str[i] - 48);
		i++;
	}
	return (res);
}

void	ft_bzero(void *s, size_t n)
{
	char	*str;
	int		i;

	i = 0;
	str = s;
	while (n-- > 0)
	{
		str[0] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*s;

	s = malloc(size * count);
	if (!s)
		return (NULL);
	ft_bzero(s, size * count);
	return (s);
}
