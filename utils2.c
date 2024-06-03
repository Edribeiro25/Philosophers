/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eribeiro <eribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 13:37:55 by eribeiro          #+#    #+#             */
/*   Updated: 2022/02/19 13:42:44 by eribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	boucle(t_philo *p)
{
	pthread_mutex_lock(&p->t->end);
	if (p->t->iend == 0)
	{
		pthread_mutex_unlock(&p->t->end);
		return (0);
	}
	pthread_mutex_unlock(&p->t->end);
	return (1);
}

void	my_sleep(int t)
{
	long	ms;
	long	ms2;

	ms = get_mytime();
	ms2 = ms;
	while (ms - ms2 < t)
	{
		usleep(100);
		ms = get_mytime();
	}
}
