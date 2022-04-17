/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 17:11:57 by ael-asri          #+#    #+#             */
/*   Updated: 2022/04/17 16:13:28 by ael-asri         ###   ########.fr       */
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
	
}*/

int	throw_error(void)
{
	printf("opps error\n");
	return(0);
}
/*
void	*chh(void *p)
{
	t_philo *philo;
//	t_data	*data=NULL;
//	int	i;

	philo = p;
//	printf("tfo %d\n", philo->id);	
	return(NULL);
}

void	*gg(void *d)
{
	t_data *data;
	unsigned long long	tim;

	data = (t_data*)d;
	while (1)
	{
		tim = get_time();
	//	printf("tim %llu \n", tim);
	//	usleep(1000);
	//	printf("last meal %llu \n", get_time() - tim);
		// printf("tim %ld \n", tim);
	//	printf("tim-- %llu \n", tim - data->philo.last_meal);
		int	gg = get_time() - data->philo.last_meal;
	//	printf("gg %d\n", gg);
		if (gg > data->t_die)
		{
			sem_wait(data->lock);
			printf("died\n");
			sem_post(data->lock);
			exit(0);	
		}
	}
	return (NULL);
}
*/
int	check_mealsss(t_data *data)
{
	int	i;

	i = 0;
	// while (i < data->n_philo)
	// {
	//	printf("meals %d\n", data->philo.id);
		if (data->philo.meals < data->n_meals)
		{
		//	data->philo.done_eating = 1;
			return (0);
		}
		i++;
//	}
//	printf("wewweew\n");
	return (1);
}

void	*ft_routine(void *d)
{
	t_data	*data;

	data = (t_data *)d;
	data->start_time = get_time();
	
	while (1)
	{
		eating(data);
		sleeping_thinking(data);
	}
	return (NULL);
}

void	*ft_check(void *d)
{
	t_data	*data;
	long	tim;

	data = d;
	
	while (1)
	{
		tim = get_time();
		if ((tim - data->philo.last_meal) > data->t_die)
		{
			died(data);
			sem_post(data->sos);
			exit(0);
		}
		if (data->nm_ishere && check_mealsss(data))
		{
			data->philo.is_dead = 1;
			died(data);
			sem_post(data->sos);
			exit(0);
		}
	}
	
	return (NULL);
}

int	ft_init(t_data *data)
{
	data->philo.last_meal = get_time();
	if (pthread_create(&data->tid, NULL, &ft_check, data) != 0)
		return (0);
	pthread_detach(data->tid);
//	if (pthread_join(data->tid, NULL) != 0)
//		return (0);
	return(1);
}

int ft_philo(t_data *data)
{
	int	i;

	i = 0;
	data->start_time = get_time();
    while (i < data->n_philo)
	{
		data->philo.meals = 0;
		data->philo.is_dead = 0;
		data->philo.done_eating = 0;
		if (data->nm_ishere)
			data->philo.n_meals = data->n_meals;
		data->philo.id = i+1;
		data->pid[i] = fork();
		if (data->pid[i] == 0)
		{
            ft_init(data);
			ft_routine(data);
		}
		i++;
	}
	sem_wait(data->sos);
	return(1);
}

void	kill_them(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philo)
	{
		kill(data->pid[i], SIGKILL);
		i++;
	}
}

int main(int ac, char **av)
{
	t_data data;

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
		init_semaphores(&data);
		ft_philo(&data);
		kill_them(&data);
	}
	else
		return (throw_error());
	
}