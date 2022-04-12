/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 14:09:09 by ael-asri          #+#    #+#             */
/*   Updated: 2022/04/12 01:30:29 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_BONUS
# define PHILOSOPHERS_BONUS

# include "unistd.h"
# include "stdio.h"
# include "stdlib.h"
# include "pthread.h"
# include "fcntl.h"
# include "semaphore.h"
# include "sys/time.h"

typedef struct s_philo
{
	//////////////////
	int				n;
	int				t_die;
	int				t_sleep;
	int				t_eat;
	int				n_meals;
	//////////////////
	int		id;
	sem_t	*r_fork;
	sem_t	*l_fork;
	pid_t	pid;
	int				meals;
	long			last_meal;
	sem_t			lock;
//	pthread_mutex_t	output;
	int				is_dead;
	int				start_time;
}					t_philo;

typedef struct s_data
{
	pthread_t		*t;
	pid_t			*pid;
	int				n_philo;
	int				t_die;
	int				t_sleep;
	int				t_eat;
	int				n_meals;
	int				nm_ishere;
	t_philo			*philo;
	sem_t	*forks;
	sem_t	*lock;
	pthread_mutex_t	gg;
}					t_data;

//	-------- routine
void	*routine(void *p);

//// ----- utils
int	ft_atoi(const char	*str);

//	------ philosophing
int	create_philosophers(t_data *data);

// ------ forking
int	init_processes(t_data *data);

//	-------- processing
int	create_processes(t_data *data);

//	-------- time
long	get_time();
long	ft_time(void);
//	-------- actions
void	take_forks(t_philo *philo);
void	eating(t_philo *philo);
void	sleeping(t_philo *philo);
void	thinking(t_philo *philo);
void	died(t_philo *philo);
//void	check_dead(t_philo *philo);
int	check_deadd(t_data *data);
int	sf_salina(t_data *data);

#endif