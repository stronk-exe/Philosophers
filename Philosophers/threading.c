/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threading.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 22:59:52 by ael-asri          #+#    #+#             */
/*   Updated: 2022/03/25 18:47:46 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	create_threads(t_data *data)
{
	int	i;

	i = 0;
	data->t = malloc(sizeof(t_philo) * data->n_philo);
	if(!data->t)
		return (0);
//	if (pthread_mutex_init(data->philo->t, NULL) != 0)
//		return (0);
//	printf("t sleep %d\n", data->t_sleep);
	while (i < data->n_philo)
	{
		
		if (pthread_create(&data->t[i], NULL, &routine, (void*)data) != 0)
			return (0);
		data->philo[i].id = i+1;
		data->philo[i].meals = 0;
	//	printf("I'm philo %d\n", data->philo[i].id);
		i++;
	}
	i = 0;
	while (i < data->n_philo)
	{
		if (pthread_join(data->t[i], NULL) != 0)
			return (0);
		printf("I'm philo %d\n", data->philo[i].id);
		i++;
	}
	return (1);
}