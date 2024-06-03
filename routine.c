/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eribeiro <eribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 10:41:51 by eribeiro          #+#    #+#             */
/*   Updated: 2022/02/19 14:02:56 by eribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	pair(int i)
{
	if ((i % 2) == 0)
		return (1);
	return (0);
}

void	upmeal(t_philo *p)
{
	if (p->t->musteat > -1)
	{
		p->nbmeal++;
		if (p->nbmeal == p->t->musteat)
		{
			pthread_mutex_lock(&p->t->upmeal);
			p->t->pmusteat++;
			pthread_mutex_unlock(&p->t->upmeal);
		}
	}
}

void	eatphilo(t_philo *p)
{
	taketicket(p);
	if (boucle(p) == 1)
	{
		pthread_mutex_lock(p->forkn);
		printmess(p, "has taken a fork\n", 0, p->nbpilo);
		pthread_mutex_lock(p->forkn_1);
		printmess(p, "has taken a fork\n", 0, p->nbpilo);
		printmess(p, "is eating\n", 0, p->nbpilo);
		my_sleep(p->t->teat);
		pthread_mutex_lock(&p->tmeal);
		p->time_meal = get_mytime();
		pthread_mutex_unlock(&p->tmeal);
		upmeal(p);
		pthread_mutex_unlock(p->forkn_1);
		pthread_mutex_unlock(p->forkn);
	}
	releseticket(p);
}

void	philosleep(t_philo *p)
{
	if (boucle(p) == 1)
	{
		printmess(p, "is sleeping\n", 0, p->nbpilo);
		my_sleep(p->t->tsleep);
		printmess(p, "is thinking\n", 0, p->nbpilo);
	}
}

void	*routine(void *phi)
{
	t_philo	*p;

	p = (t_philo *)phi;
	p->nbmeal = 0;
	if (pair(p->nbpilo) == 1)
		usleep(1000);
	while (boucle(p) == 1)
	{
		eatphilo(p);
		philosleep(p);
	}
	return (NULL);
}
