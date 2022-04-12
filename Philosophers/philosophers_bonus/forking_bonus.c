/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forking_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 15:00:17 by ael-asri          #+#    #+#             */
/*   Updated: 2022/04/12 01:26:30 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

int	init_processes(t_data *data)
{
	int	i;

	i = 0;
	data->forks = malloc(sizeof(sem_t) * data->n_philo);
	if (!data->forks)
		return (0);
//	while (i < data->n_philo)
//	{
		data->forks = sem_open("forks", O_CREAT, 0666, data->n_philo);
	//	pthread_mutex_init(&data->forks[i], NULL);
//		i++;
//	}
	return (1);
}