/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forking_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 15:00:17 by ael-asri          #+#    #+#             */
/*   Updated: 2022/04/10 18:09:18 by ael-asri         ###   ########.fr       */
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
	while (i < data->n_philo)
	{
		sem_open(&data->forks[i], 0);
	//	pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
	return (1);
}