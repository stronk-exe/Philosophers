/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 23:13:37 by ael-asri          #+#    #+#             */
/*   Updated: 2022/04/21 23:30:37 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	*ft_routine(t_data *data)
{
	data->start_time = get_time();
	while (1)
	{
		eating(data);
		sleeping_thinking(data);
	}
	return (NULL);
}
