/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_meal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eribeiro <eribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 10:42:41 by eribeiro          #+#    #+#             */
/*   Updated: 2022/02/18 11:31:05 by eribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_eat(t_philo *p)
{
	pthread_mutex_lock(&p->t->upmeal);
	if (p->t->musteat == -1)
	{
		pthread_mutex_unlock(&p->t->upmeal);
		return (0);
	}
	if (p->t->pmusteat == p->t->nbphilo)
	{
		pthread_mutex_lock(&p->t->end);
		p->t->iend = 0;
		pthread_mutex_unlock(&p->t->end);
	}
	pthread_mutex_unlock(&p->t->upmeal);
	return (0);
}

void	*check_eatth(void *arg)
{
	t_philo		*p;

	p = (t_philo *)arg;
	while (boucle(p))
	{
		if (check_eat(p) == 1)
			return (0);
	}
	return (NULL);
}
