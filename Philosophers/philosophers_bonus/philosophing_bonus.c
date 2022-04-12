/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophing_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 14:08:07 by ael-asri          #+#    #+#             */
/*   Updated: 2022/04/12 01:31:38 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

int	create_philosophers(t_data *data)
{
	int	i;
//	t_philo *my_philo;

	data->philo = malloc(sizeof(t_philo) * data->n_philo);
	if(!data->philo)
		return (0);
	i = 0;
//	printf("t_die isss %d\n", data->t_die);
	
	while (i < data->n_philo)
	{
		data->pid[i] = fork();
		printf("hello\n");
		if (!data->pid)
		{
			data->philo[i].id = i+1;
			data->philo[i].t_eat = data->t_eat;
			data->philo[i].t_sleep = data->t_sleep;
			data->philo[i].t_die = data->t_die;
			data->philo[i].n = data->n_philo;
			data->philo[i].l_fork = &data->forks[data->philo[i].id];
			data->philo[i].r_fork = &data->forks[(data->philo[i].id + 1) % data->n_philo];
			data->philo[i].meals = 0;
			data->philo[i].is_dead = 0;
			data->philo[i].last_meal = get_time();
			data->philo[i].start_time = get_time();
			if (data->nm_ishere)
				data->philo[i].n_meals = data->n_meals;
		}
		i++;
	}
	return (1);
}