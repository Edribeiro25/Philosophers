/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ticket.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eribeiro <eribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 14:01:51 by eribeiro          #+#    #+#             */
/*   Updated: 2022/02/19 14:04:02 by eribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	taketicket(t_philo *p)
{
	int	i;

	i = 0;
	while (i == 0)
	{
		pthread_mutex_lock(&p->t->mcaneat);
		if (p->t->caneat > 0)
		{
			i = 1;
			p->t->caneat--;
		}
		else
			i = 0;
		pthread_mutex_unlock(&p->t->mcaneat);
	}
}

void	releseticket(t_philo *p)
{
	pthread_mutex_lock(&p->t->mcaneat);
	p->t->caneat++;
	pthread_mutex_unlock(&p->t->mcaneat);
}
