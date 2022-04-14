/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophing_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 21:56:05 by ael-asri          #+#    #+#             */
/*   Updated: 2022/04/14 16:28:44 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"
/*
void	*chh(void *p)
{
	t_philo *philo;
//	t_data	*data=NULL;
//	int	i;

	
	philo = p;
	printf("I'm philooo %d\n", philo->id);
	return(NULL);
}

int	create_philosophers(t_data *data)
{
	int	i;
//	t_philo *my_philo;
//	pthread_t		t;
//	data->philo = malloc(sizeof(t_philo) * data->n_philo);
//	if(!data->philo)
//		return (0);
	i = 0;
//	printf("t_die isss %d\n", data->t_die);
	while (i < data->n_philo)
	{
		data->philo.id = i+1;
	*//*	printf("I'm philooo %d\n", data->philo.id);
		data->philo.t_eat = data->t_eat;
			data->philo.t_sleep = data->t_sleep;
			data->philo.t_die = data->t_die;
			data->philo.n = data->n_philo;
			data->philo.l_fork = &data->forks[data->philo.id];
			data->philo.r_fork = &data->forks[(data->philo.id + 1) % data->n_philo];
			data->philo.meals = 0;
			data->philo.is_dead = 0;
			data->philo.last_meal = get_time();
			data->philo.start_time = get_time();
			if (data->nm_ishere)
				data->philo.n_meals = data->n_meals;*//*
		data->pid[i] = fork();
		if (data->pid[i] == 0)
		{
			if (pthread_create(&data->t, NULL, &chh, (void*)&data) != 0)
				return (0);
			if (pthread_join(data->t, NULL) != 0)
				return (0);
			routine(data);
	 	}
		else
			waitpid(-1, NULL, 0);
		i++;
	}
//	if (pthread_mutex_init(data->philo, NULL) != 0)
//		return (0);
	return (1);
}
*/
///////////////////////////////////////////
