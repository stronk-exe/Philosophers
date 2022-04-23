/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 23:13:37 by ael-asri          #+#    #+#             */
/*   Updated: 2022/04/23 01:18:25 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	*ft_routine(t_data *data)
{
	while (1)
	{
		eating(data);
		sleeping_thinking(data);
		usleep(50);
	}
	return (NULL);
}
