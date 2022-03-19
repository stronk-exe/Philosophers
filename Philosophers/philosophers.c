/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 17:11:57 by ael-asri          #+#    #+#             */
/*   Updated: 2022/03/05 18:55:35 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"


void philo(t_philosopher *philo)
{
	int	i;
	
//	printf("current time is %ld\n", current_time.tv_sec);
	
	pthread_t t[philo->n_philo];

	i = 0;
//	pthread_mutex_init(&(philo.lock), NULL);
//	create_philosophers(philo);
	while (i < philo->n_philo)
	{
		if (pthread_create(&t[i], NULL, &routine, (void *)&philo) != 0)
			exit(1);
//		pthread_join(t[i], NULL);
	//	philo->n[i] = i;
	//	i++;
//		printf("----\n");
		i++;
	}
	i = 0;
	while (i < philo->n_philo)
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
	t_philosopher my_philo;
	
//	int	n_philo;
//	int	t_sleep;

	if (ac == 5 || ac == 6)
	{
		my_philo.n_philo = ft_atoi(av[1]);
		my_philo.massa2il.t_die = ft_atoi(av[2]);
		my_philo.massa2il.t_eat = ft_atoi(av[3]);
		my_philo.massa2il.t_sleep = ft_atoi(av[4]);
		if (ac == 6)
			my_philo.meals = ft_atoi(av[5]);
		my_philo.all_alive = 1;
		printf("bp %d\n", my_philo.n_philo);
	//	philos.n = 0;
	//	philos.n = malloc(sizeof(int)*philos.n_philo+1);
	//	philos.n[philos.n_philo] = '\0';
	//	philo(&philos);
		create_philosophers(&my_philo);

	}
	else
		write(2, "error\n", 6);
/*	if (n_philo > 1)
		forking(n_philo-1);
	else
		forking(n_philo);*/
	
}