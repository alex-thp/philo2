/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-temm <ade-temm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 15:27:41 by ade-temm          #+#    #+#             */
/*   Updated: 2021/11/19 16:28:57 by ade-temm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_doc	*doc;

	if (!(ac > 4 && ac < 7))
	{
		printf("Erreur lors de la saisie des parametres\n");
		return (0);
	}
	doc = parse_doc(av, ac);
	if (check_params(*doc) == 1)
	{
		printf("Erreur lors de la saisie des parametres\n");
		return (0);
	}
	run(doc);
	free(doc);
	return (0);
}
