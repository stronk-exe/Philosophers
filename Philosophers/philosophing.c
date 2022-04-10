/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 21:56:05 by ael-asri          #+#    #+#             */
/*   Updated: 2022/04/10 00:46:24 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	create_philosophers(t_data *data)
{
	int	i;
//	t_philo *my_philo;

	data->philo = malloc(sizeof(t_philo) * data->n_philo);
	if(!data->philo)
		return (0);
	i = 0;
//	printf("t_die isss %d\n", data->t_die);
	while (i < data->n_philo)
	{
		data->philo[i].id = i+1;
		data->philo[i].t_eat = data->t_eat;
		data->philo[i].t_sleep = data->t_sleep;
		data->philo[i].t_die = data->t_die;
		data->philo[i].n = data->n_philo;
		data->philo[i].l_fork = &data->forks[data->philo[i].id];
		data->philo[i].r_fork = &data->forks[(data->philo[i].id + 1) % data->n_philo];
		data->philo[i].meals = 0;
		data->philo[i].is_dead = 0;
		data->philo[i].last_meal = get_time();
		data->philo[i].start_time = get_time();
		if (data->nm_ishere)
			data->philo[i].n_meals = data->n_meals;
	//	if (pthread_mutex_init(&data->philo[i].lock, NULL) != 0)
	//		return (0);
	//	printf("%d\n", data->philo[i].l_fork);
	//	printf("%d\n", data->philo[i].r_fork);
	//	if (pthread_mutex_init(&data->philo[i].output, NULL) != 0)
	//		return (0);
	//	printf("I'm philo %d\n", data->philo[i].id);
	//	printf("meals %d\n", data->philo[i].n_meals);
		i++;
	}
//	if (pthread_mutex_init(data->philo, NULL) != 0)
//		return (0);
	return (1);
}
