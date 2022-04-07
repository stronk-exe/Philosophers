/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threading.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 22:59:52 by ael-asri          #+#    #+#             */
/*   Updated: 2022/04/06 18:16:19 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
/*
int	create_threads(t_data *data)
{
	int	i;

	i = 0;
	data->t = malloc(sizeof(t_philo) * data->n_philo);
	if(!data->t)
		return (0);
//	if (pthread_mutex_init(data->philo->t, NULL) != 0)
//		return (0);
//	printf("t sleep %d\n", data->t_sleep);
	while (i < data->n_philo)
	{
		
		if (pthread_create(&data->t[i], NULL, &routine, (void*)data) != 0)
			return (0);
		data->philo[i].id = i+1;
	//	printf("I'm philo %d\n", data->philo[i].id);
		i++;
	}
	i = 0;
	while (i < data->n_philo)
	{
		if (pthread_join(data->t[i], NULL) != 0)
			return (0);
		printf("I'm philo %d\n", data->philo[i].id);
		i++;
	}
	return (1);
}
*/
int	create_threads(t_data *data)
{
	int	i;

	
//	pthread_mutex_init(&data->gg, NULL);	
	data->t = malloc(sizeof(pthread_t) * data->n_philo);
	if(!data->t)
		return (0);
	
//	if (pthread_mutex_init(&data->gg, NULL) != 0)
//		return (0);
	// if (pthread_mutex_init(&data->lock, NULL) != 0)
	// 		return (0);
//	printf("t sleep %d\n", data->t_sleep);
//	pthread_mutex_init(&data->philo[i].lock, NULL);
//printf("hii\n");
//	printf("%d\n", data->n_philo);
//	i = 0;
	// while (i < data->n_philo)
	// {
	// 	data->philo[i].id = i+1;
	// 	data->philo[i].t_eat = data->t_eat;
	// 	data->philo[i].t_sleep = data->t_sleep;
	// 	data->philo[i].n = data->n_philo;
	// 	data->philo[i].l_fork = data->forks[data->philo[i].id];
	// 	data->philo[i].r_fork = data->forks[(data->philo[i].id + 1) % data->n_philo];
	// 	data->philo[i].meals = 0;
	// //	if (pthread_mutex_init(&data->philo[i].lock, NULL) != 0)
	// //		return (0);
	// //	printf("%d\n", data->philo[i].l_fork);
	// //	printf("%d\n", data->philo[i].r_fork);
	// //	if (pthread_mutex_init(&data->philo[i].output, NULL) != 0)
	// //		return (0);
	// //	printf("I'm philo %d\n", data->philo[i].id);
	// 	i++;
	// }
	i = 0;
	while (i < data->n_philo)
	{
	//	pthread_mutex_init(&data->philo[i].lock, NULL);	
	//	pthread_mutex_lock(&data->gg);
		if (pthread_create(&data->t[i], NULL, &routine, (void*)&data->philo[i]) != 0)
			return (0);
	//	printf("hii\n");
	//	pthread_mutex_unlock(&data->gg);
	//	if (pthread_create(&data->t[i], NULL, &routine, (void*)data) != 0)
	//		return (0);
		i++;
	}
	i = 0;
	while (i < data->n_philo)
	{
		if (pthread_join(data->t[i], NULL) != 0)
			return (0);
	//	printf("I'm returned philo %d\n", data->philo[i].id);
		i++;
	}
	return (1);
}