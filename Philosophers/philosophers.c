/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 17:11:57 by ael-asri          #+#    #+#             */
/*   Updated: 2022/03/04 10:40:35 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"



#include "stdio.h"

void	eating(t_philo *philo)
{
	printf("%d %d has taken a fork\n", philo->t_eat, philo->n);
	printf("%d %d is eating\n", philo->t_eat, philo->n);
	sleep(philo->t_eat);
}

void	sleeping(t_philo *philo)
{
	printf("%d %d is sleeping\n", philo->t_sleep, philo->n);
	sleep(philo->t_sleep);
}

void	thinking(t_philo *philo)
{
	printf("%d %d is thinking\n", philo->t_think, philo->n);
	sleep(philo->t_think);
}

void	died(t_philo *philo)
{
	printf("%d %d died\n", philo->t_sleep, philo->n);
}

void	*routine(void *p)
{
	t_philo *philo;
	long time;
	long	cc;
	int	i;
	struct timeval current_time;
	gettimeofday(&current_time, NULL);

	i = 0;
	philo = p;
	time = current_time.tv_sec;
	cc = current_time.tv_sec;
//	pthread_mutex_lock(&(philo->lock));

	while (cc < (time + philo->t_die) /*&& i < philo->meal*/)
	{
	//	printf("raw time %ld\n", current_time.tv_sec);
	//	printf("new time %ld\n", current_time.tv_sec + philo->t_die);
		eating(philo);
		sleeping(philo);
		thinking(philo);
		cc = gettimeofday(&current_time, NULL);
		i++;
	}
	died(philo);
//	pthread_mutex_unlock(&(philo->lock));
	return(0);
}

void philo(t_philo philo)
{
	int	i;
	
//	printf("current time is %ld\n", current_time.tv_sec);
	
	pthread_t t[philo.n_philo];

	i = 0;
//	pthread_mutex_init(&(philo.lock), NULL);
	while (i < philo.n_philo)
	{
		if (pthread_create(&t[i], NULL, &routine, (void *)&philo) != 0)
			exit(1);
//		pthread_join(t[i], NULL);
		philo.n++;
//		printf("----\n");
		i++;
	}
	i = 0;
	while (i < philo.n_philo)
	{
		if (pthread_join(t[i], NULL) != 0)
			exit(1);
		printf("----\n");
		i++;
	}
//	pthread_mutex_destroy(&(philo.lock));
	
}
/*
void	forking(int n)
{
	int	i;

	i = 0;
	while ()
	{
		
	}
}*/
int main(int ac, char **av)
{
	t_philo philos;
	
//	int	n_philo;
//	int	t_sleep;

	if (ac == 5 || ac == 6)
	{
		philos.n_philo = ft_atoi(av[1]);
		philos.t_die = ft_atoi(av[2]);
		philos.t_eat = ft_atoi(av[3]);
		philos.t_sleep = ft_atoi(av[4]);
		if (ac == 6)
			philos.meal = ft_atoi(av[5]);
		philos.n = 0;
		philo(philos);
	}
	else
		write(2, "error\n", 6);
/*	if (n_philo > 1)
		forking(n_philo-1);
	else
		forking(n_philo);*/
	
}