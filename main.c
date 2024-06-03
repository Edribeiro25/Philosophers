/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eribeiro <eribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 17:32:09 by eribeiro          #+#    #+#             */
/*   Updated: 2022/02/19 13:54:46 by eribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	join_thd(pthread_t time, pthread_t meat, t_philo *p)
{
	int	i;

	i = 0;
	if (pthread_join(time, NULL) != 0)
		return (1);
	if (p->t->musteat > -1)
	{
		if (pthread_join(meat, NULL) != 0)
			return (1);
	}
	i = 0;
	while (i < p->t->nbphilo)
	{
		if (pthread_join(p[i].phil, NULL) != 0)
			return (1);
		i++;
	}
	return (0);
}

int	lunchthread(t_table *t, t_philo *p)
{
	int			i;
	pthread_t	time;
	pthread_t	meat;

	i = 0;
	t->time = get_mytime();
	while (i < t->nbphilo)
	{
		p[i].time_meal = t->time;
		if (pthread_create(&p[i].phil, NULL, &routine, &p[i]) != 0)
			return (1);
		i++;
	}
	if (t->musteat > -1)
	{
		if (pthread_create(&meat, NULL, &check_eatth, &p[0]) != 0)
			return (1);
	}
	if (pthread_create(&time, NULL, &check_die, &p[0]) != 0)
		return (1);
	join_thd(time, meat, p);
	return (0);
}

int	lunchmu(t_table *t, t_philo *p)
{
	int	i;

	i = 0;
	while (i < t->nbphilo)
	{
		if (pthread_mutex_init(&p[i].tmeal, NULL) != 0)
			return (1);
		i++;
	}
	if (pthread_mutex_init(&t->mcaneat, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&t->end, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&t->upmeal, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&t->mprint, NULL) != 0)
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_table	*table;
	t_philo	*philo;

	table = malloc(sizeof(t_table));
	if (!table)
		return (1);
	if (ac < 5 || ac > 6)
		return (print_error(ac));
	if (recupinfo(ac, av, table) == 1)
		return (freeer(table));
	philo = malloc(sizeof(t_philo) * table->nbphilo);
	if (!philo)
		return (freeer(table));
	if (init_philo(table, philo) == 1)
		return (freeall(table, philo));
	if (lunchmu(table, philo) == 1)
		return (freeall(table, philo));
	if (table->nbphilo > 1)
		lunchthread(table, philo);
	else
		onephilo(philo);
	freeall(table, philo);
	return (0);
}
