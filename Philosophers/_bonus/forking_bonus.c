/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forking_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 21:55:51 by ael-asri          #+#    #+#             */
/*   Updated: 2022/04/17 22:20:26 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

int	init_semaphores(t_data *data)
{
	sem_unlink("lock");
	sem_unlink("forks");
	data->lock = sem_open("lock", O_CREAT, 0666, 1);
	data->forks = sem_open("forks", O_CREAT, 0666, data->n_philo);
	data->sos = sem_open("sos", O_CREAT, 0666, 0);
	data->pid = malloc(sizeof(pid_t) * data->n_philo);
	if (!data->pid)
		return (0);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->n_philo);
	if (!data->forks)
		return (0);
	return (1);
}
