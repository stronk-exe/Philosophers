/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 17:11:57 by ael-asri          #+#    #+#             */
/*   Updated: 2022/04/14 02:14:22 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"
/*
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
			data.n_meals = ft_atoi(av[5]);
	//	create_philosophers();
		pthread_mutex_init(&data.lock, NULL);
		printf("hi\n");
		init_forkes(&data);
		printf("hi\n");
		create_threads(&data);
	}
	else
		write(2, "error\n", 6);
	
}
*/
int	throw_error(void)
{
	printf("opps error\n");
	return(0);
}

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
			if (data.n_meals < 0)
				return (throw_error());
			data.nm_ishere = 1;
		}
		if (data.n_philo <= 0 || data.t_die <= 0 || data.t_eat <= 0 || data.t_sleep <= 0)
			return (throw_error());
	//	if (pthread_mutex_init(&data.lock, NULL) != 0)
	//		return (0);
		init_semaphores(&data);
		
		if (!create_philosophers(&data))
			return (0);
	//	printf("hii\n");
	//	if (!create_threads(&data))
	//		return (0);
	//	sf_salina(&data);
		
	//	pthread_mutex_init(&data.lock, NULL);
	//	printf("hi\n");
	//	printf("time %ld\n", get_time());
	//	printf("ft_time %ld\n", ft_time());
	}
	else
		return (throw_error());
	
}