/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ending_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 00:22:50 by ael-asri          #+#    #+#             */
/*   Updated: 2022/04/21 16:39:11 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

int	throw_error(void)
{
	printf("opps error\n");
	return (0);
}

void	kill_them(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philo)
	{
		kill(data->pid[i], SIGKILL);
		i++;
	}
}
