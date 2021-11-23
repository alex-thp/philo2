/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-temm <ade-temm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 15:27:27 by ade-temm          #+#    #+#             */
/*   Updated: 2021/11/19 16:34:28 by ade-temm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_message(t_philo *philo, char *str)
{
	pthread_mutex_lock(&philo->doc->print);
	printf("%ld %d %s\n", get_time(philo->doc->start), philo->nb + 1, str);
	if (philo->status == 1)
		pthread_mutex_unlock(&philo->doc->print);
}
