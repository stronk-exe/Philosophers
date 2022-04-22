/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 17:11:57 by ael-asri          #+#    #+#             */
/*   Updated: 2022/04/22 10:31:18 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	*ft_check(void *d)
{
	t_data	*data;
	long	tim;
	int		gg;

	data = d;
	while (1)
	{
		tim = get_time();
		if ((tim - data->philo.last_meal) > data->t_die)
		{
			sem_wait(data->lock);
			gg = get_time() - data->start_time;
			printf("%d %d died\n", gg, data->philo.id);
			sem_post(data->stop);
			exit(0);
		}
		usleep(10);
	}
	return (NULL);
}

void	*ft_eating_checker(void *d)
{
	t_data	*data;
	int		i;

	data = d;
	i = -1;
	sem_wait(data->lock);
	while (++i < data->n_philo)
	{
		sem_post(data->lock);
		sem_wait(data->done_eating);
		sem_wait(data->lock);
	}
	sem_post(data->stop);
	return (NULL);
}

int	ft_init(t_data *data)
{
	data->philo.last_meal = get_time();
	if (pthread_create(&data->tid, NULL, &ft_check, data) != 0)
		return (0);
	pthread_detach(data->tid);
	return (1);
}

int	big_init(t_data *data, int ac, char **av)
{
	memset(data, 0, sizeof(t_data));
	data->n_philo = ft_atoi(av[1]);
	data->t_die = ft_atoi(av[2]);
	data->t_eat = ft_atoi(av[3]);
	data->t_sleep = ft_atoi(av[4]);
	if (ac == 6)
	{
		data->n_meals = ft_atoi(av[5]);
		if (data->n_meals < 0)
			return (throw_error());
		data->nm_ishere = 1;
	}
	if (data->n_philo <= 0 || data->t_die <= 0
		|| data->t_eat <= 0 || data->t_sleep <= 0)
		return (throw_error());
	data->pid = malloc(sizeof(pid_t) * data->n_philo);
	init_semaphores(data);
	init_done_eating(data);
	return (1);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac == 5 || ac == 6)
	{
		if (!big_init(&data, ac, av))
			return (0);
		if (!ft_philo(&data))
			return (0);
		kill_them(&data);
	}
	else
		return (throw_error());
}
