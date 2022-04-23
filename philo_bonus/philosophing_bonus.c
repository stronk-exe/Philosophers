/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophing_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 21:56:05 by ael-asri          #+#    #+#             */
/*   Updated: 2022/04/23 02:06:54 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	parsing(t_data *data, int i)
{
	long	tt;

	tt = get_time();
	data->philo.id = i + 1;
	data->philo.n_meals = 0;
	data->philo.alive = 0;
	data->start_time = tt;
}

int	ft_philo(t_data *data)
{
	int		i;

	i = 0;
	while (i < data->n_philo)
	{
		parsing(data, i);
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
		else
			usleep(100);
		i++;
	}
	sem_wait(data->stop);
	return (0);
}
