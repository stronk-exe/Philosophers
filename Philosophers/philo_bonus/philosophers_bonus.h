/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 16:26:21 by ael-asri          #+#    #+#             */
/*   Updated: 2022/04/22 18:21:47 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_BONUS_H
# define PHILOSOPHERS_BONUS_H

# include "unistd.h"
# include "stdio.h"
# include "stdlib.h"
# include "pthread.h"
# include "sys/time.h"
# include "semaphore.h"
# include "fcntl.h"
# include "signal.h"
# include "string.h"

typedef struct s_philo
{
	pthread_t	tid;
	int			n;
	int			t_die;
	int			t_sleep;
	int			t_eat;
	int			n_meals;
	int			id;
	int			meals;
	long		last_meal;
	int			is_dead;
	long		start_time;
}					t_philo;

typedef struct s_data
{
	pthread_t	tid;
	int			n_philo;
	int			t_die;
	int			t_sleep;
	int			t_eat;
	int			n_meals;
	int			nm_ishere;
	long		start_time;
	t_philo		philo;
	pid_t		*pid;
	sem_t		*stop;
	sem_t		*done_eating;
	sem_t		*forks;
	sem_t		*lock;
}					t_data;

//	-------- routine
void	*ft_routine(t_data *data);

//// ----- utils
int		ft_atoi(const char	*str);

//	------ philosophing
int		create_philosophers(t_data *data);

// ------ forking
//int	init_semaphores(t_data *data);
int		init_semaphores(t_data *data);
//	-------- threading
int		create_threads(t_data *data);
int		ft_philo(t_data *data);
int		ft_init(t_data *data);
//	-------- time
long	get_time(void);
void	ft_usleep(long lmeal, int t);
//	-------- actions
void	take_forks(t_data *data);
void	eating(t_data *data);
void	sleeping(t_data *data);
void	thinking(t_data *data);

//void	ft_sleeping_thinking(t_data *data);
//void	ft_taking_forks_eating(t_data *data);

//void	thinking(t_data *data);
void	died(t_data *data);
//void	check_dead(t_philo *philo);
//void	*check_dead(void *data);
int		sf_salina(t_data *data);
int		init_done_eating(t_data *data);
void	*ft_eating_checker(void *d);
int		throw_error(void);
void	kill_them(t_data *data);

/////////////
void	*chh(void *p);

#endif