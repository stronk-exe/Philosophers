/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 20:37:59 by ael-asri          #+#    #+#             */
/*   Updated: 2022/04/16 01:06:30 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "philosophers.h"
#include "_bonus/philosophers_bonus.h"
/*
int	get_time()
{
	struct timeval	current_time;
	int				time;

	time = gettimeofday(&current_time, NULL);
	return (time * 1000);
}

void	ft_usleep(int time)
{
	while (get_time() < time)
		usleep(10);
}*/

long	ft_time(void)
{
	struct timeval	tv;
	long			res;

	gettimeofday(&tv, NULL);
	res = 1000 * (size_t)tv.tv_sec + (size_t)tv.tv_usec / 1000;
	return (res);
}

unsigned long long	get_time()
{
	struct timeval	current_time;
//	int				time;

	gettimeofday(&current_time, NULL);
	return ((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
}
/*
void	ft_usleep(int time)
{
	while (get_time() < time)
		continue;
}
*/