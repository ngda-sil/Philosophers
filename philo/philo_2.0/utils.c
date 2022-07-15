/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngda-sil <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 17:54:58 by ngda-sil          #+#    #+#             */
/*   Updated: 2022/07/14 19:03:48 by ngda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}

int	str_error(char *s, int ret)
{
	printf("%s\n", s);
	return (ret);
}

long	atol_pos(char *str)
{
	long	res;
	int		i;

	i = -1;
	res = 0;
	while (str[++i])
		res = res * 10 + (str[i] - '0');
	return (res);
}

void	ft_bzero(void *s, size_t n)
{
	char	*str;

	str = s;
	while (n-- > 0)
		*str++ = '\0';
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
