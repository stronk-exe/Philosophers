/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ending_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 00:22:50 by ael-asri          #+#    #+#             */
/*   Updated: 2022/04/23 18:01:38 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

int	throw_error(void)
{
	printf("Error\n");
	return (0);
}

void	kill_them(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philo)
	{
		if (data->pid[i] != 0)
			kill(data->pid[i], SIGKILL);
		i++;
	}
}
