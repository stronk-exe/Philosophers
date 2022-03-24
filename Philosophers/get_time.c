/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 20:37:59 by ael-asri          #+#    #+#             */
/*   Updated: 2022/03/24 21:27:11 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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
}