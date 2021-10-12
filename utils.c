/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbueno-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 12:26:29 by mbueno-g          #+#    #+#             */
/*   Updated: 2021/10/12 17:01:18 by mbueno-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

useconds_t	ft_time(void)
{
	struct timeval t;

	gettimeofday(&t, NULL);
	return (t.tv_sec * 1000 + t.tv_usec / 1000);
}

t_philo	*new_philo(t_data *d, int i)
{
	t_philo *new;

	new = malloc(sizeof(t_philo)); //controlar error
	if (!new)
		return(NULL);
	new->id = i;
	new->id_thread = 0;
	new->last_eat = 0;
	new->data = d;
	return (new);
}
