/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threading.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 22:59:52 by ael-asri          #+#    #+#             */
/*   Updated: 2022/04/10 00:45:58 by ael-asri         ###   ########.fr       */
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
/*void	check_dead(t_philo *philo)
{
//	printf("tdie %d\n", philo->t_die);
//	printf("last meal %ld\n", philo->last_meal);
	
	
	
	long	timing;

	timing = get_time() - philo->last_meal;
//	printf("timing %ld\n", get_time()-philo->last_meal);
	if (timing > philo->t_die)
//	if (philo->meals >= 5 || philo->last_meal + philo->t_die >= get_time()*//* || get_time() - philo->start_time >= philo->t_die*//*)
	{
		philo->is_dead = 1;
		died(philo);
		exit(1);
	}
//	return (NULL);
}
*/

int	check_meals(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philo)
	{
		if (data->philo[i].meals < data->n_meals)
			return (0);
		i++;
	}
	return (1);
}

int	check_deadd(t_data *data)
{
//	printf("tdie %d\n", philo->t_die);
//	printf("last meal %ld\n", philo->last_meal);
	int	i;
	long	timing;

	i = 0;
	
//	printf("timing %ld\n", get_time()-philo->last_meal);
	while (i < data->n_philo)
	{
		timing = get_time() - data->philo[i].last_meal;
		if (timing > data->philo[i].t_die)
//	if (philo->meals >= 5 || philo->last_meal + philo->t_die >= get_time()/* || get_time() - philo->start_time >= philo->t_die*/)
		{
			data->philo[i].is_dead = 1;
			died(&data->philo[i]);
			sf_salina(data);
		//	system("leaks philo");
			printf("hey from ddd---------------------\n");
			return (0);
		//	exit(1);
		}
		
		if (data->nm_ishere && check_meals(data)/*(data->philo[i].meals > data->philo[i].n_meals)*/)
//	if (philo->meals >= 5 || philo->last_meal + philo->t_die >= get_time()/* || get_time() - philo->start_time >= philo->t_die*/)
		{
			data->philo[i].is_dead = 1;
			sf_salina(data);
		//	system("leaks philo");
			printf("we done here---------------------\n");
			return (0);
		//	exit(1);
		}
		i++;
	}
	
	return (1);
}

int	create_threads(t_data *data)
{
	int	i;

	
//	pthread_mutex_init(&data->gg, NULL);	
	data->t = malloc(sizeof(pthread_t) * data->n_philo);
	if(!data->t)
		return (0);
	
//	if (pthread_mutex_init(&data->gg, NULL) != 0)
//		return (0);
//	if (pthread_mutex_init(&data->lock, NULL) != 0)
//			return (0);
//	printf("t sleep %d\n", data->t_sleep);
//	pthread_mutex_init(&data->philo[i].lock, NULL);
//printf("hii\n");
//	printf("%d\n", data->n_philo);
	// i = 0;
	// while (i < data->n_philo)
	// {
	// 	data->philo[i].id = i+1;
	// 	data->philo[i].t_eat = data->t_eat;
	// 	data->philo[i].t_sleep = data->t_sleep;
	// 	data->philo[i].n = data->n_philo;
	// 	data->philo[i].l_fork = data->forks[data->philo[i].id];
	// 	data->philo[i].r_fork = data->forks[(data->philo[i].id + 1) % data->n_philo];
	// 	data->philo[i].meals = 0;
	// 	if (pthread_mutex_init(&data->philo[i].lock, NULL) != 0)
	// 		return (0);
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
	//	if (!routine(ph))
	//		return (0);
	//	pthread_mutex_unlock(&data->gg);
	//	if (pthread_create(&data->t[i], NULL, &routine, (void*)data) != 0)
	//		return (0);
		i++;
	}
	while (1)
	{
		if (!check_deadd(data))
			return (0);
		//	exit(1);
		//	break;
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