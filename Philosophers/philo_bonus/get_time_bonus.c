/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 20:37:59 by ael-asri          #+#    #+#             */
/*   Updated: 2022/04/21 23:55:38 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	ft_usleep(long lmeal, int t)
{
	while ((get_time() - lmeal) < t)
		usleep(10);
}

long	get_time(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return ((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
}
