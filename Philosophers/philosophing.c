/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 21:56:05 by ael-asri          #+#    #+#             */
/*   Updated: 2022/04/06 17:33:33 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	create_philosophers(t_data *data)
{
//	t_philo *my_philo;
	int	i;

	i = 0;
	data->philo = malloc(sizeof(t_philo) * data->n_philo);
	if(!data->philo)
		return (0);
	
	while (i < data->n_philo)
	{
		data->philo[i].id = i+1;
		data->philo[i].t_eat = data->t_eat;
		data->philo[i].t_sleep = data->t_sleep;
		data->philo[i].n = data->n_philo;
		data->philo[i].l_fork = &data->forks[data->philo[i].id];
		data->philo[i].r_fork = &data->forks[(data->philo[i].id + 1) % data->n_philo];
		data->philo[i].meals = 0;
		printf("I'm philo %d\n", data->philo[i].id);
		i++;
	}
	
//	if (pthread_mutex_init(data->philo, NULL) != 0)
//		return (0);
	return (1);
}
