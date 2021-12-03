/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbueno-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 10:37:25 by mbueno-g          #+#    #+#             */
/*   Updated: 2021/10/12 17:01:15 by mbueno-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_t_data(t_data *d, char **argv, int argc)
{
	d->num_philos = ft_atoi(argv[1]);
	d->time_to_eat = ft_atoi(argv[2]);
	d->time_to_sleep = ft_atoi(argv[3]);
	d->time_to_die = ft_atoi(argv[4]);
	d->num_eat = -1;
	d->time_o = ft_time();
	d->death = 0;
	d->times_eat = 0;
	pthread_mutex_init(&d->death_lock, NULL);
	pthread_mutex_init(&d->times_eat_lock, NULL);
	if (argc == 6)
	{
		d->num_eat = ft_atoi(argv[5]);
		if (d->num_eat < 0)
			return (printf("Incorrect number of times to eat\n"));
	}
	if (d->num_philos <= 0)
		return(printf("Invalid number of philos"));
	if (d->time_to_eat < 0)
		return(printf("Incorrect time to eat"));
	if (d->time_to_sleep < 0) 
		return(printf("Incorrect time to sleep"));
	if (d->time_to_die < 0)
		return(printf("Invalid arguments"));
	return (0);
}


int	init_cycled_t_list(t_list **philos, t_data *d)
{
	int i;
	t_list	*aux;

	i = 1;
	aux = NULL;
	while (i <= d->num_philos)
	{
		aux = ft_lstnew(new_philo(d,i));
		if (!aux || !aux->content)
			return(printf("Malloc failed\n"));
		ft_lstadd_back(philos, aux);
		i++;
	}
	ft_lstlast(*philos)->next = *philos;
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	d;
	t_list	*philos;
	
	philos = NULL;
	if (argc != 5 && argc != 6)
		return(printf("Incorrect number of arguments"));
	if (init_t_data(&d, argv, argc))
		return (1);
	//philos = NULL;
	if (init_cycled_t_list(&philos, &d)) //liberar memoria
	{
		ft_lstclear(&philos, free);
		return (1);
	}
	if (init_threads(d, philos)) //liberar memoria
	{
		ft_lstclear(&philos, free);
		return (1);
	}
	return (0);
}

