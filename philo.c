
#include "philo.h"

int	print_status(t_list *philo, char *status)
{
	t_philo		*philos;
	useconds_t	t;

	philos = philo->content;
	t = ft_time() - philos->data->time_o;
	pthread_mutex_lock(&philos->data->times_eat_lock);
	if (philos->data->num_eat * philos->data->num_philos \
		!= philos->data->times_eat)
		printf("\033[1;39m{%06u\033[0;39m}  %03d  ➤ \033[0;39m%s\n", \
			t, philos->id, status);
	if (!ft_strncmp(status, EAT, ft_strlen(status)))
		philos->data->times_eat++;
	pthread_mutex_unlock(&philos->data->times_eat_lock);
	return (0);
}

int	check_philos(t_list	*philos)
{
	t_philo	*aux;

	while (1)
	{
		aux = philos->content;
		pthread_mutex_lock(&aux->data->times_eat_lock);
		if (aux->data->num_eat * aux->data->num_philos == aux->data->times_eat)
		{
			pthread_mutex_lock(&aux->data->death_lock);
			aux->data->death = 1;
			pthread_mutex_unlock(&aux->data->death_lock);
			return (0);
		}
		pthread_mutex_unlock(&aux->data->times_eat_lock);
		pthread_mutex_lock(&aux->last_eat_lock);
		if (ft_time() - aux->last_eat - aux->data->time_o >= \
			aux->data->time_to_die)
		{
			pthread_mutex_lock(&aux->data->death_lock);
			aux->data->death = 1;
			pthread_mutex_unlock(&aux->data->death_lock);
			return (print_status(philos, DEAD));
		}
		pthread_mutex_unlock(&aux->last_eat_lock);
		philos = philos->next;
	}
}

void	*living_philo(void *philo)
{
	t_philo	*fork1;
	t_philo	*fork2;
	int		i;

	i = -1;
	fork1 = ((t_list *)philo)->content;
	fork2 = ((t_list *)philo)->next->content;
	ft_usleep(!(fork1->id % 2) * 2);
	while ((++i < fork1->data->num_eat || fork1->data->num_eat == -1) \
		&& !fork1->data->death)
	{
		pthread_mutex_lock(&fork1->fork_lock);
		print_status((t_list *)philo, FORK1);
		pthread_mutex_lock(&fork2->fork_lock);
		print_status((t_list *)philo, FORK2);
		pthread_mutex_lock(&fork1->last_eat_lock);
		fork1->last_eat = ft_time() - fork1->data->time_o;
		pthread_mutex_unlock(&fork1->last_eat_lock);
		print_status((t_list *)philo, EAT);
		ft_usleep(fork1->data->time_to_eat);
		print_status((t_list *)philo, SLEEP);
		pthread_mutex_unlock(&fork2->fork_lock);
		pthread_mutex_unlock(&fork1->fork_lock);
		ft_usleep(fork1->data->time_to_sleep);
		print_status((t_list *)philo, THINK);
	}
	return (NULL);
}

int	init_threads(t_data d, t_list *philos)
{
	t_list	*aux;
	t_philo	*p;
	int		i;

	i = 0;
	aux = philos;
	while (i < d.num_philos)
	{
		p = aux->content;
		if (pthread_create(&p->id_thread, NULL, living_philo, (void *)aux))
		{
			printf("Error creating thread\n");
			return (1);
		}
		aux = aux->next;
		i++;
	}
	check_philos(philos);
	return (0);
}
