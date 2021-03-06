/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 16:26:21 by ael-asri          #+#    #+#             */
/*   Updated: 2022/04/23 16:44:07 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include "unistd.h"
# include "stdio.h"
# include "stdlib.h"
# include "pthread.h"
# include "sys/time.h"

typedef struct s_philo
{
	int				n;
	int				t_die;
	int				t_sleep;
	int				t_eat;
	int				n_meals;
	int				id;
	int				alive;
	int				done_eating;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	int				meals;
	long			last_meal;
	pthread_mutex_t	lock;
	pthread_mutex_t	output;
	int				is_dead;
	long			start_time;
}					t_philo;

typedef struct s_data
{
	pthread_t		*t;
	int				n_philo;
	int				t_die;
	int				t_sleep;
	int				t_eat;
	int				n_meals;
	int				nm_ishere;
	t_philo			*philo;
	pthread_mutex_t	*forks;
	pthread_mutex_t	lock;
	pthread_mutex_t	time;
	pthread_mutex_t	gg;
}					t_data;

//	-------- routine
void	*routine(void *p);

//// ----- utils
int		ft_atoi(const char	*str);
int		just_allocate(t_data *data);

//	------ philosophing
void	create_philosophers(t_data *data);

// ------ forking
int		init_forkes(t_data *data);

//	-------- threading
int		create_threads(t_data *data);

//	-------- time
long	get_time(void);
long	ft_time(void);
void	ft_usleep(long time, int t);
void	ft_gg(long n);
//	-------- actions
void	take_forks(t_philo *philo);
void	eating(t_philo *philo);
void	sleeping(t_philo *philo);
void	thinking(t_philo *philo);
void	died(t_philo *philo);
//void	check_dead(t_philo *philo);
int		check_dead(t_data *data);
int		check_meals(t_data *data);
void	give_it(t_data *data);
void	sf_salina(t_data *data);
void	ft_free(t_data *data);
void	finish_them(t_data *data);

#endif