/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 16:26:21 by ael-asri          #+#    #+#             */
/*   Updated: 2022/04/02 21:21:15 by ael-asri         ###   ########.fr       */
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
	
	int				id;
	int				r_fork;
	int				l_fork;
	int				meals;
	long			last_meal;
	pthread_mutex_t	lock;
}				t_philo;

typedef struct s_data
{
	pthread_t		*t;
	int				n_philo;
	long			t_die;
	int				t_sleep;
	int				t_eat;
	int				n_meals;
	t_philo			*philo;
	pthread_mutex_t	*forks;
	pthread_mutex_t	output;
}					t_data;

//	-------- routine
void	*routine(void *p);

//// ----- utils
int	ft_atoi(const char	*str);

//	------ philosophing
int	create_philosophers();

// ------ forking
int	init_forkes(t_data *data);

//	-------- threading
int	create_threads(t_data *data);

//	-------- time
long	get_time();
long	ft_time(void);
//	-------- actions
void	eating(t_data *data, int i);
void	sleeping(t_data *data, int i);
void	thinking(t_philo *philo);
void	died(t_philo *philo);

#endif