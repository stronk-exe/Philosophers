/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 16:26:21 by ael-asri          #+#    #+#             */
/*   Updated: 2022/04/14 02:06:52 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS
# define PHILOSOPHERS

# include "unistd.h"
# include "stdio.h"
# include "stdlib.h"
# include "pthread.h"
# include "sys/time.h"
# include "semaphore.h"
# include "fcntl.h"

typedef struct s_philo
{
	//////////////////
	int				n;
	int				t_die;
	int				t_sleep;
	int				t_eat;
	int				n_meals;
	//////////////////
	int				id;
	sem_t	*r_fork;
	sem_t	*l_fork;
	int				meals;
	long			last_meal;
	sem_t	lock;
//	pthread_mutex_t	output;
	int				is_dead;
	int				start_time;
	pthread_t		t;
}					t_philo;

typedef struct s_data
{
	
	int				n_philo;
	int				t_die;
	int				t_sleep;
	int				t_eat;
	int				n_meals;
	int				nm_ishere;
	t_philo			*philo;
	pid_t	*pid;
	sem_t	*forks;
	sem_t	*lock;
}					t_data;

//	-------- routine
int	routine(t_philo *philo);

//// ----- utils
int	ft_atoi(const char	*str);

//	------ philosophing
int	create_philosophers(t_data *data);

// ------ forking
int	init_semaphores(t_data *data);

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
//void	check_dead(t_philo *philo);
int	check_deadd(t_data *data);
int	sf_salina(t_data *data);

/////////////
void	*chh(void *p);

#endif