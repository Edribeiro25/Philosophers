/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eribeiro <eribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 09:55:59 by eribeiro          #+#    #+#             */
/*   Updated: 2022/02/19 14:03:47 by eribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdlib.h>
# include <stdio.h> 
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <time.h>

typedef struct s_table
{
	int					nbphilo;
	int					tdie;
	int					teat;
	int					tsleep;
	int					musteat;
	int					pmusteat;
	int					iend;
	int					caneat;
	long				time;
	pthread_mutex_t		mcaneat;
	pthread_mutex_t		upmeal;
	pthread_mutex_t		end;
	pthread_mutex_t		mprint;
	pthread_mutex_t		*forks;
}	t_table;

typedef struct s_philo
{
	int				nbpilo;
	int				nbmeal;
	long			time_meal;
	t_table			*t;
	pthread_t		phil;
	pthread_mutex_t	tmeal;
	pthread_mutex_t	*forkn;
	pthread_mutex_t	*forkn_1;
}	t_philo;

int		checkdigit(char *c);
int		ft_atoi(const char *str);
int		recupinfo(int ac, char **av, t_table *t1);
int		init_philo(t_table *t, t_philo *p);
int		malloc_mutex(t_table *t);
int		musteat(t_table *t, char *c, int ac);
int		boucle(t_philo *p);
int		onephilo(t_philo *p);
int		freeer(t_table *t);
int		print_error(int ac);
int		freeall(t_table *t, t_philo *p);
void	taketicket(t_philo *p);
void	releseticket(t_philo *p);
void	printmess(t_philo *p, char *c, int dead, int id);
void	my_sleep(int t);
void	*check_die(void *arg);
void	*check_eatth(void *arg);
void	*routine(void *phi);
long	get_mytime(void);
#endif
