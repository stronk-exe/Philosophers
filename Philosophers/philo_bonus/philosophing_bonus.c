/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophing_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 21:56:05 by ael-asri          #+#    #+#             */
/*   Updated: 2022/04/21 17:32:03 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

int	ft_philo(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philo)
	{
		data->philo.id = i + 1;
		data->philo.n_meals = 0;
		data->pid[i] = fork();
		if (data->pid[i] == -1)
		{
			while (--i >= 0)
				kill(data->pid[i], SIGKILL);
			return (1);
		}
		else if (data->pid[i] == 0)
		{
			ft_init(data);
			ft_routine(data);
		}
		i++;
	}
	sem_wait(data->stop);
	return (0);
}
