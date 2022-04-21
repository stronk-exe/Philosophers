/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threading.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 22:59:52 by ael-asri          #+#    #+#             */
/*   Updated: 2022/04/21 20:07:35 by ael-asri         ###   ########.fr       */
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
//	sf_salina(data);
	return (0);
}

int	check_dead(t_data *data)
{
	int		i;
	long	timing;

	i = 0;
	while (i < data->n_philo)
	{
		timing = get_time() - data->philo[i].last_meal;
		if (timing >= data->philo[i].t_die)
		{
			data->philo[i].is_dead = 1;
			data->philo[i].alive = 0;
			sf_salina(data);
			died(&data->philo[i]);
			return (0);
		}
		i++;
	}
	return (1);
}

int	create_threads(t_data *data)
{
	int	i;

	data->t = malloc(sizeof(pthread_t) * data->n_philo);
	if (!data->t)
		return (0);
	i = 0;
	while (i < data->n_philo)
	{
		if (pthread_create(&data->t[i], NULL, &routine,
				(void*)&data->philo[i]) != 0)
			return (0);
		i += 2;
	}
	usleep(20);
	i = 1;
	while (i < data->n_philo)
	{
		if (pthread_create(&data->t[i], NULL, &routine,
				(void*)&data->philo[i]) != 0)
			return (0);
		i += 2;
	}
	while (1)
	{
		if (!check_dead(data) || !check_meals(data))
		{
		//	printf("---we done here---\n");
		//	died(data->philo[i]);
			sf_salina(data);
			return (0);
		}
		usleep(100);
	}
	i = 0;
	while (i < data->n_philo)
	{
		if (pthread_join(data->t[i], NULL) != 0)
			return (0);
		i++;
	}
	return (1);
}
