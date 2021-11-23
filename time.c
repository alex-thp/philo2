/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-temm <ade-temm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 15:27:32 by ade-temm          #+#    #+#             */
/*   Updated: 2021/11/19 17:29:09 by ade-temm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long int	get_msec(time_t tv_sec, suseconds_t tv_usec)
{
	return ((tv_sec * 1000000 + tv_usec) / 1000);
}

long int	get_time(long int start)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (get_msec(tv.tv_sec, tv.tv_usec) - start);
}

long int	get_time_since_last_meal(t_philo *philo)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (get_msec(tv.tv_sec, tv.tv_usec) - philo->last_meal);
}

void	init_time(t_doc *doc)
{
	struct timeval		tv;

	gettimeofday(&tv, NULL);
	doc->start = get_msec(tv.tv_sec, tv.tv_usec);
}
