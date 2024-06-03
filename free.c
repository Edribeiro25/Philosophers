/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eribeiro <eribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 10:49:28 by eribeiro          #+#    #+#             */
/*   Updated: 2022/02/18 12:07:07 by eribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	freeall(t_table *t, t_philo *p)
{
	int	i;

	i = 0;
	while (i < t->nbphilo)
	{
		pthread_mutex_destroy(&t->forks[i]);
		i++;
	}
	free(t->forks);
	pthread_mutex_destroy(&t->upmeal);
	pthread_mutex_destroy(&t->end);
	pthread_mutex_destroy(&t->mprint);
	i = 0;
	while (i < t->nbphilo)
	{
		pthread_mutex_destroy(&p[i].tmeal);
		i++;
	}
	free(t);
	free(p);
	return (1);
}

int	freeer(t_table *t)
{
	free(t);
	return (1);
}
