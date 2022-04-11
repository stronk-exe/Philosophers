/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 14:58:02 by ael-asri          #+#    #+#             */
/*   Updated: 2022/04/11 00:36:53 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

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

int	create_processes(t_data *data)
{
	int	i;

	data->t = malloc(sizeof(pthread_t) * data->n_philo);
	if(!data->t)
		return (0);
	i = 0;
	while (i < data->n_philo)
	{
		if (pthread_create(&data->t[i], NULL, &routine, (void*)&data->philo[i]) != 0)
			return (0);
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