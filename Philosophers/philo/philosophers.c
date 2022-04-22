/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 17:11:57 by ael-asri          #+#    #+#             */
/*   Updated: 2022/04/21 22:12:37 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	throw_error(void)
{
	printf("opps error\n");
	return (0);
}

int	big_init(t_data *data, int ac, char **av)
{
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
	else
		data->nm_ishere = 0;
	if (data->n_philo <= 0 || data->t_die <= 0
		|| data->t_eat <= 0 || data->t_sleep <= 0)
		return (throw_error());
	return (1);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac == 5 || ac == 6)
	{
		if (!big_init(&data, ac, av))
			return (0);
		if (pthread_mutex_init(&data.lock, NULL) != 0)
			return (0);
		init_forkes(&data);
		data.philo = malloc(sizeof(t_philo) * data.n_philo);
		if (!data.philo)
			return (0);
		data.t = malloc(sizeof(pthread_t) * data.n_philo);
		if (!data.t)
			return (0);
		create_philosophers(&data);
		if (!create_threads(&data))
		{
			sf_salina(&data);
			ft_free(&data);
			return (0);
		}
	}
	else
		return (throw_error());
}
