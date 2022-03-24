/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 16:26:21 by ael-asri          #+#    #+#             */
/*   Updated: 2022/03/24 18:53:57 by ael-asri         ###   ########.fr       */
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
	
	int	id;
	int	r_fork;
	int	l_fork;
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
	pthread_mutex_t		*forks;
	pthread_mutex_t	lock;
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

//	-------- actions
void	eating(t_data *data, t_philo *philo);
void	sleeping(t_data *data, t_philo *philo);
void	thinking(t_philo *philo);
void	died(t_data *data);

#endif
