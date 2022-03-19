/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 16:26:21 by ael-asri          #+#    #+#             */
/*   Updated: 2022/03/05 18:15:57 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include "unistd.h"
# include "stdio.h"
# include "stdlib.h"
# include "pthread.h"
# include "sys/time.h"

typedef struct s_massa2il
{
	int	t_die;
	int	t_sleep;
	int	t_eat;
	
}					t_massa2il;

typedef struct s_philosopher
{
	int	id;
	int	n_philo;
	int	meals;
	int	t_die;
	int	t_sleep;
	int	t_eat;
	int	all_alive;
	int	done_with_eating;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork_eat;
	pthread_mutex_t	*must_eat;
	t_massa2il 		massa2il;
}	t_philosopher;

//// ------ philosophing
void create_philosophers(t_philosopher *my_philo);

//// ------ forking
void create_forks(t_philosopher *my_philo);
void    take_forks(t_philosopher *my_philo);
void    let_forks(t_philosopher *my_philo);

////  ------ actions
int everything_ok(t_philosopher *my_philospher);
void    eating(t_philosopher *my_philo);
void    sleeping(t_philosopher *my_philo);
void    thinking(t_philosopher *my_philo);

//// ------ routine
void	*routine(void *p);

//// get time
void    get_time(long time, t_philosopher *my_philo);

//// ----- utils
int	ft_atoi(const char	*str);

#endif
