/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eribeiro <eribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 10:42:00 by eribeiro          #+#    #+#             */
/*   Updated: 2022/02/19 13:44:46 by eribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_error(int ac)
{
	if (ac < 5)
		printf("Error too few arguments\n");
	if (ac > 6)
		printf("Error too much arguments\n");
	return (0);
}

int	malloc_mutex(t_table *t)
{
	pthread_mutex_t	*f;
	int				i;

	i = 0;
	f = malloc(sizeof(pthread_mutex_t) * t->nbphilo);
	if (!f)
		return (1);
	while (i < t->nbphilo)
	{
		if (pthread_mutex_init(&f[i], NULL) != 0)
			return (1);
		i++;
	}
	t->caneat = t->nbphilo - 1;
	t->pmusteat = 0;
	t->iend = 1;
	t->forks = f;
	return (0);
}

void	printmess(t_philo *p, char *c, int dead, int id)
{
	pthread_mutex_lock(&p->t->mprint);
	pthread_mutex_lock(&p->t->end);
	if (p->t->iend == 1)
	{
		printf("%lu ms : %d %s", get_mytime() - p->t->time, id, c);
	}
	pthread_mutex_unlock(&p->t->end);
	if (dead)
	{	
		pthread_mutex_lock(&p->t->end);
		p->t->iend = 0;
		pthread_mutex_unlock(&p->t->end);
	}
	pthread_mutex_unlock(&p->t->mprint);
}

int	init_philo(t_table *t, t_philo *p)
{
	int	i;

	i = 0;
	while (i < t->nbphilo)
	{
		p[i].nbpilo = i + 1;
		p[i].t = t;
		if (i == t->nbphilo)
			p[i].forkn = &t->forks[0];
		else if (i != 0)
			p[i].forkn = &t->forks[i];
		if (i == 0)
		{
			p[i].forkn = &t->forks[t->nbphilo - 1];
			p[i].forkn_1 = &t->forks[i];
		}
		else
			p[i].forkn_1 = &t->forks[i -1];
		p[i].time_meal = 0;
		i++;
	}
	return (0);
}
