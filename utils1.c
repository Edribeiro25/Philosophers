/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eribeiro <eribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 09:55:59 by eribeiro          #+#    #+#             */
/*   Updated: 2022/02/18 11:42:02 by eribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	checkdigit(char *c)
{
	int	i;

	i = 0;
	while (c[i])
	{
		if (c[i] > '9' || c[i] < '0')
			return (1);
		i++;
	}
	return (0);
}

int	check(int j)
{
	if (j < 0)
		return (0);
	else
		return (-1);
}

int	ft_atoi(const char *str)
{
	int				i;
	int				j;
	unsigned int	r;

	r = 0;
	i = 0;
	j = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			j *= -1;
		i++;
	}
	if (str[i] < '0' || str[i] > '9')
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = (r * 10) + (str[i++] - '0');
		if (r > 2147483648)
			return (check(j));
	}
	return (j * r);
}

int	musteat(t_table *t, char *c, int ac)
{
	if (ac == 6)
	{
		if (checkdigit(c) == 1)
		{
			printf("Invalid number of must eat\n");
			return (1);
		}
		t->musteat = ft_atoi(c);
		if (t->musteat < 0)
		{
			printf("Invalid number of must eat\n");
			return (1);
		}
	}
	else
		t->musteat = -1;
	return (0);
}

long	get_mytime(void)
{
	long			ms;
	struct timeval	t;

	gettimeofday(&t, NULL);
	ms = ((t.tv_sec * 1000) + (t.tv_usec / 1000));
	return (ms);
}
