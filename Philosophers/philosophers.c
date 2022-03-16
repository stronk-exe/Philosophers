/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 17:11:57 by ael-asri          #+#    #+#             */
/*   Updated: 2022/03/15 19:59:18 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"



#include "stdio.h"

void	eating(t_philo *philo, int n)
{
//	pthread_mutex_lock(&philo->fork[n]);
	printf("%d %d has taken a fork\n", philo->t_eat, n);
	printf("%d %d is eating\n", philo->t_eat, n);
	sleep(philo->t_eat);
//	pthread_mutex_unlock(&philo->fork[n]);
}

void	sleeping(t_philo *philo, int n)
{
	printf("%d %d is sleeping\n", philo->t_sleep, n);
	sleep(philo->t_sleep);
}

void	thinking(t_philo *philo, int n)
{
	printf("%d %d is thinking\n", philo->t_think, n);
//	sleep(philo->t_think);
}

void	died(t_philo *philo, int n)
{
	printf("%d %d died\n", philo->t_sleep, n);
}

void	*routine(void *p)
{
	t_philo *philo= NULL;
	long time;
	long	cc;
	int	i;
//	pthread_mutex_init(philo->fork, NULL);
	struct timeval current_time;
	gettimeofday(&current_time, NULL);

	i = 0;
	philo = p;
	time = current_time.tv_sec / 1000;
	cc = time;
//	pthread_mutex_lock(&(philo->lock));

//	while ((cc * 1000) < (time + philo->t_die) /*&& i < philo->meal*/)
	while (cc < (time + philo->t_die) /*&& i < philo->meal*/)
//	while (1)
	{
	//	printf("raw time %ld\n", current_time.tv_sec);
	//	printf("new time %ld\n", current_time.tv_sec + philo->t_die);
		
		printf("cc %ld\n", cc);
		printf("time %ld\n", time+philo->t_die);
	//	printf("cc %ld\n", cc);
		i = 0;
	//	while (i < philo->n_philo)
	//	{
		//	if (philo->n[i] )
			sleeping(philo,i);
			eating(philo, i);
		//	printf("----\n");
			thinking(philo, i);
		//	printf("----\n");
			i++;
	///	}
	//	sleeping(philo);
	//	thinking(philo, philo->n[i]);
		cc = current_time.tv_sec;
	//	i++;
	}
	printf("cc %ld\n", cc/1000);
	died(philo, i);
//	pthread_mutex_destroy(philo->fork);
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
		philo.n[i] = i;
		i++;
//		printf("----\n");
		i++;
	}
	i = 0;
	while (i < philo.n_philo)
	{
		if (pthread_join(t[i], NULL) != 0)
			exit(1);
	//	printf("----\n");
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
		philos.n = malloc(sizeof(int)*philos.n_philo+1);
	//	printf("nuber of philos %d\n", philos.n_philo);
		philos.fork = malloc(sizeof(pthread_mutex_t)*philos.n_philo);
		philos.n[philos.n_philo] = '\0';
		philo(philos);
	}
	else
		write(2, "error\n", 6);
/*	if (n_philo > 1)
		forking(n_philo-1);
	else
		forking(n_philo);*/
	
}