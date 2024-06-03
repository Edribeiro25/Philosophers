/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_die.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eribeiro <eribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 10:42:37 by eribeiro          #+#    #+#             */
/*   Updated: 2022/02/18 11:30:09 by eribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	longtimetodie(t_philo *p)
{
	pthread_mutex_lock(&p->tmeal);
	if ((get_mytime() - p->time_meal) > p->t->tdie)
	{
		pthread_mutex_unlock(&p->tmeal);
		return (0);
	}
	pthread_mutex_unlock(&p->tmeal);
	return (1);
}

void	*check_die(void *arg)
{
	t_philo		*p;
	int			i;

	p = (t_philo *)arg;
	while (boucle(p))
	{
		i = 0;
		while (i < p->t->nbphilo)
		{
			if (longtimetodie(&p[i]) == 0)
			{
				printmess(p, "has died\n", 1, p[i].nbpilo);
				return (0);
			}	
			i++;
		}
	}
	return (NULL);
}
