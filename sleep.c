/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-temm <ade-temm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 15:28:06 by ade-temm          #+#    #+#             */
/*   Updated: 2021/11/19 16:45:07 by ade-temm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	have_to_sleep(t_philo *philo)
{
	struct timeval	tv;
	long int		time;

	gettimeofday(&tv, NULL);
	time = get_msec(tv.tv_sec, tv.tv_usec);
	print_message(philo, "is sleeping");
	while (get_time(time) < philo->doc->time_to_sleep)
		usleep(250);
}

void	have_to_think(t_philo *philo)
{
	print_message(philo, "is thinking");
}
