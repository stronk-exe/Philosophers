/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ending.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 00:22:50 by ael-asri          #+#    #+#             */
/*   Updated: 2022/04/21 22:12:54 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_free(t_data *data)
{
	free(data->t);
	free(data->philo);
	free(data->forks);
}

void	sf_salina(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philo)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	pthread_mutex_unlock(&data->lock);
	pthread_mutex_destroy(&data->lock);
}
