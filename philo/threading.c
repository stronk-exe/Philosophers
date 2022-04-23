/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threading.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 22:59:52 by ael-asri          #+#    #+#             */
/*   Updated: 2022/04/23 16:35:24 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_meals(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philo)
	{
		if (!data->philo[i].done_eating)
		{
			pthread_mutex_lock(&data->philo[i].lock);
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_dead(t_data *data)
{
	int		i;

	i = 0;
	while (i < data->n_philo)
	{
		if (get_time() - data->philo[i].last_meal >= data->philo[i].t_die)
		{
			give_it(data);
			pthread_mutex_lock(&data->lock);
			printf("%ld %d died\n",
				get_time() - data->philo[i].start_time, data->philo[i].id + 1);
			return (0);
		}
		i++;
	}
	return (1);
}

int	creat_1(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philo)
	{
		if (pthread_create(&data->t[i], NULL, &routine,
				(void*)&data->philo[i]) != 0)
			return (0);
		pthread_detach(data->t[i]);
		usleep(50);
		i += 2;
	}
	return (1);
}

int	creat_2(t_data *data)
{
	int	i;

	i = 1;
	while (i < data->n_philo)
	{
		if (pthread_create(&data->t[i], NULL, &routine,
				(void*)&data->philo[i]) != 0)
			return (0);
		pthread_detach(data->t[i]);
		usleep(50);
		i += 2;
	}
	return (1);
}

int	create_threads(t_data *data)
{
	int	i;

	if (!creat_1(data))
		return (0);
	usleep(100);
	if (!creat_2(data))
		return (0);
	i = 0;
	while (i < data->n_philo)
	{
		if (pthread_join(data->t[i], NULL) != 0)
			return (0);
		i++;
	}
	return (1);
}
