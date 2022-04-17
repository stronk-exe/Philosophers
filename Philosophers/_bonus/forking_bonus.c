/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forking_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 21:55:51 by ael-asri          #+#    #+#             */
/*   Updated: 2022/04/17 13:43:16 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"
/*
int	init_forkes(t_data *data)
{
	int	i;

	i = 0;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->n_philo);
	if (!data->forks)
		return (0);
//	printf("hi\n");
	while (i < data->n_philo)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
	return (1);
}

int	init_forkes(t_data *data)
{
	int	i;

	i = 0;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->n_philo);
	if (!data->forks)
		return (0);
//	printf("hi\n");
	while (i < data->n_philo)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
	return (1);
}
*/

int	init_semaphores(t_data *data)
{
	sem_unlink("lock");
	sem_unlink("forks");
	data->lock = sem_open("lock", O_CREAT, 0666, 1);
	data->forks = sem_open("forks", O_CREAT, 0666, data->n_philo);
	data->sos = sem_open("sos", O_CREAT, 0666, 0);
//	data->t = malloc(sizeof(pthread_t) * data->n_philo);
//	if(!data->t)
//		return (0);
	data->pid = malloc(sizeof(pid_t) * data->n_philo);
	if(!data->pid)
		return (0);
//	data->philo = malloc(sizeof(t_philo) * data->n_philo);
//	if(!data->philo)
//		return (0);
/*	int	i;

	i = 0;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->n_philo);
	if (!data->forks)
		return (0);
	while (i < data->n_philo)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}*/
	return (1);
}