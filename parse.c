/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-temm <ade-temm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 15:28:14 by ade-temm          #+#    #+#             */
/*   Updated: 2021/11/23 12:06:08 by ade-temm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_doc	*parse_doc(char **av, int ac)
{
	t_doc	*result;

	result = malloc(sizeof(t_doc));
	result->status = malloc(sizeof(int));
	*(result->status) = ft_atoi(av[1]);
	if (pthread_mutex_init(&(result->print), NULL) != 0)
		printf("\n mutex init of doc->print failed\n");
	if (pthread_mutex_init(&(result->finish), NULL) != 0)
		printf("\n mutex init of doc->finish failed\n");
	result->nb_philo = ft_atoi(av[1]);
	result->time_to_die = ft_atoi(av[2]);
	result->time_to_eat = ft_atoi(av[3]);
	result->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		result->option = 1;
	else
		result->option = 0;
	if (result->option)
		result->nb_time_philo_eat = ft_atoi(av[5]);
	else
		result->nb_time_philo_eat = 2147483647;
	return (result);
}
