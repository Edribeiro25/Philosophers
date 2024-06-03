/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eribeiro <eribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 09:59:25 by eribeiro          #+#    #+#             */
/*   Updated: 2022/02/19 13:19:28 by eribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	numberofphilo(t_table *t, char *c)
{
	if (checkdigit(c) == 1)
	{
		printf("Invalid char of number of Philosopher\n");
		return (1);
	}
	t->nbphilo = ft_atoi(c);
	if (t->nbphilo <= 0)
	{
		printf("Invalid number of Philosopher\n");
		return (1);
	}
	return (0);
}

int	timetodie(t_table *t, char *c)
{
	if (checkdigit(c) == 1)
	{
		printf("Invalid char of time to die\n");
		return (1);
	}
	t->tdie = ft_atoi(c);
	if (t->tdie < 0)
	{
		printf("Invalid number of time to die\n");
		return (1);
	}
	return (0);
}

int	timetoeat(t_table *t, char *c)
{
	if (checkdigit(c) == 1)
	{
		printf("Invalid char of time to eat\n");
		return (1);
	}
	t->teat = ft_atoi(c);
	if (t->teat < 0)
	{
		printf("Invalid number of time to eat\n");
		return (1);
	}
	return (0);
}

int	timetosleep(t_table *t, char *c)
{
	if (checkdigit(c) == 1)
	{
		printf("Invalid number of time to sleep\n");
		return (1);
	}
	t->tsleep = ft_atoi(c);
	if (t->tsleep < 0)
	{
		printf("Invalid number of time to sleep\n");
		return (1);
	}
	return (0);
}

int	recupinfo(int ac, char **av, t_table *t)
{
	if (numberofphilo(t, av[1]) == 1)
		return (1);
	if (timetodie(t, av[2]) == 1)
		return (1);
	if (timetoeat(t, av[3]) == 1)
		return (1);
	if (timetosleep(t, av[4]) == 1)
		return (1);
	if (musteat(t, av[5], ac) == 1)
		return (1);
	if (malloc_mutex(t) == 1)
		return (1);
	return (0);
}
