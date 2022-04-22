/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forking_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 21:55:51 by ael-asri          #+#    #+#             */
/*   Updated: 2022/04/21 23:31:41 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

int	init_done_eating(t_data *data)
{
	if (data->nm_ishere)
	{
		if (pthread_create(&data->tid, NULL, &ft_eating_checker, data))
		{
			printf("Error while creating thread");
			return (1);
		}
		pthread_detach(data->tid);
	}
	return (0);
}

int	init_semaphores(t_data *data)
{
	sem_unlink("forks");
	sem_unlink("lock");
	sem_unlink("stop");
	sem_unlink("done_eating");
	data->forks = sem_open("forks", O_CREAT | O_EXCL, S_IRWXU, data->n_philo);
	data->lock = sem_open("lock", O_CREAT | O_EXCL, S_IRWXU, 1);
	data->stop = sem_open("stop", O_CREAT | O_EXCL, S_IRWXU, 0);
	if (data->nm_ishere)
		data->done_eating = sem_open("done_eating",
				O_CREAT | O_EXCL, S_IRWXU, 0);
	return (0);
}
