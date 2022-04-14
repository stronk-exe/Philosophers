/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threading_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 22:59:52 by ael-asri          #+#    #+#             */
/*   Updated: 2022/04/14 01:15:02 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"
/*
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
*/
/*
int	create_threads(t_data *data)
{
	int	i;
//	pthread_mutex_init(&data->gg, NULL);	
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
}*/