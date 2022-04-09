/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 16:26:21 by ael-asri          #+#    #+#             */
/*   Updated: 2022/04/08 16:25:40 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS
# define PHILOSOPHERS

# include "unistd.h"
# include "stdio.h"
# include "stdlib.h"
# include "pthread.h"
# include "sys/time.h"

typedef struct s_philo
{
	//////////////////
	int				n;
	int				t_die;
	int				t_sleep;
	int				t_eat;
	//////////////////
	int				id;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	int				meals;
	long			last_meal;
	pthread_mutex_t	lock;
	pthread_mutex_t	output;
	int				is_dead;
	int				start_time;
}					t_philo;

typedef struct s_data
{
	pthread_t		*t;
	int				n_philo;
	int				t_die;
	int				t_sleep;
	int				t_eat;
	int				n_meals;
	t_philo			*philo;
	pthread_mutex_t	*forks;
	pthread_mutex_t	lock;
	pthread_mutex_t	gg;
}					t_data;

//	-------- routine
void	*routine(void *p);

//// ----- utils
int	ft_atoi(const char	*str);

//	------ philosophing
int	create_philosophers(t_data *data);

// ------ forking
int	init_forkes(t_data *data);

//	-------- threading
int	create_threads(t_data *data);

//	-------- time
long	get_time();
long	ft_time(void);
//	-------- actions
void	take_forks(t_philo *philo);
void	eating(t_philo *philo);
void	sleeping(t_philo *philo);
void	thinking(t_philo *philo);
void	died(t_philo *philo);
void	check_dead(t_philo *philo);

#endif