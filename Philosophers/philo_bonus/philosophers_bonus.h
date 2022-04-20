/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 16:26:21 by ael-asri          #+#    #+#             */
/*   Updated: 2022/04/19 18:19:01 by ael-asri         ###   ########.fr       */
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
	//////////////////
	pthread_t		tid;
	int				n;
	int				t_die;
	int				t_sleep;
	int				t_eat;
	int				n_meals;
	//////////////////
	int				id;
//	sem_t	*r_fork;
//	sem_t	*fork;
	int				meals;
	long		last_meal;
//	sem_t	lock;
//	pthread_mutex_t	output;
	int				is_dead;
	long				start_time;
	
}					t_philo;

typedef struct s_data
{
	pthread_t		tid;
	int				n_philo;
	int				t_die;
	int				t_sleep;
	int				t_eat;
	int				n_meals;
	int				nm_ishere;
	int				start_time;
	t_philo			philo;
	pid_t	*pid;

sem_t		*write_sem;
	sem_t		*fork_sem;
	sem_t		*stop;
//	sem_t		*eat_enough;
	sem_t		*done_eating;
	sem_t	*forks;
	sem_t	*lock;
	sem_t	*sos;
//	sem_t		*eat_enough;
}					t_data;

//	-------- routine
void	*routine(void *data);

//// ----- utils
int	ft_atoi(const char	*str);

//	------ philosophing
int	create_philosophers(t_data *data);

// ------ forking
//int	init_semaphores(t_data *data);
int	init_semaphores(t_data *data);
//	-------- threading
int	create_threads(t_data *data);

//	-------- time
long	get_time();
long	ft_time(void);
//	-------- actions
//void	take_forks(t_data *data);
void	eating(t_data *data);
void	sleeping_thinking(t_data *data);

//void	ft_sleeping_thinking(t_data *data);
//void	ft_taking_forks_eating(t_data *data);

//void	thinking(t_data *data);
void	died(t_data *data);
//void	check_dead(t_philo *philo);
//void	*check_dead(void *data);
int	sf_salina(t_data *data);
int	init_done_eating(t_data *data);
void	*ft_eating_checker(void *d);
/////////////
void	*chh(void *p);

#endif