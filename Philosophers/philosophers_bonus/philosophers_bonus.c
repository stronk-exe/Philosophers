/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 14:08:03 by ael-asri          #+#    #+#             */
/*   Updated: 2022/04/11 01:25:00 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

int main(int ac, char **av)
{
	t_data data;
	
//	int	n_philo;
//	int	t_sleep;

	if (ac == 5 || ac == 6)
	{
		data.n_philo = ft_atoi(av[1]);
		data.t_die = ft_atoi(av[2]);
		data.t_eat = ft_atoi(av[3]);
		data.t_sleep = ft_atoi(av[4]);
		if (ac == 6)
		{
			data.n_meals = ft_atoi(av[5]);
			if (data.n_meals <= 0)
				return (0);
			//	return (throw_error());
			data.nm_ishere = 1;
		}
		if (data.n_philo <= 0 || data.t_die <= 0 || data.t_eat <= 0 || data.t_sleep <= 0)
			return (0);
		//	return (throw_error());
		sem_open(data.lock, 0);
	//	if (pthread_mutex_init(&data.lock, NULL) != 0)
	//		return (0);
		init_forkes(&data);
		if (!create_philosophers(&data))
			return (0);
		if (!create_processes(&data))
			return (0);
	//	sf_salina(&data);
		
	//	pthread_mutex_init(&data.lock, NULL);
	//	printf("hi\n");
	//	printf("time %ld\n", get_time());
	//	printf("ft_time %ld\n", ft_time());
	}
	else
		return (0);
//		return (throw_error());
	
}