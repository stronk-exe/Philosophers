/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 16:26:21 by ael-asri          #+#    #+#             */
/*   Updated: 2022/03/14 21:58:29 by ael-asri         ###   ########.fr       */
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
	int				n_philo;
	long			t_die;
	int				t_sleep;
	int				t_eat;
	int				t_think;
	int				*n;
	int				meal;
	pthread_mutex_t	*fork;
}					t_philo;

//// ----- utils
int	ft_atoi(const char	*str);

#endif
