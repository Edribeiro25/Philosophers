/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_uni.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eribeiro <eribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 10:44:41 by eribeiro          #+#    #+#             */
/*   Updated: 2022/02/18 11:34:26 by eribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*onet(void *arg)
{
	t_philo	*p;

	p = (t_philo *)arg;
	printf("%lu ms : %d %s", get_mytime() - p->t->time, 1, "has take a fork\n");
	pthread_mutex_lock(p->forkn);
	my_sleep(p->t->tdie);
	pthread_mutex_unlock(p->forkn);
	printf("%lu ms : %d %s", get_mytime() - p->t->time, 1, "has die\n");
	return (NULL);
}

int	onephilo(t_philo *p)
{
	pthread_t	one;

	p->t->time = get_mytime();
	if (pthread_create(&one, NULL, &onet, p) != 0)
		return (1);
	if (pthread_join(one, NULL) != 0)
		return (1);
	return (0);
}
