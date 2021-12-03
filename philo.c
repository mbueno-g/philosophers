
#include "philo.h"


/*
Checkea cuanto tiempo ha tardado cada filósofo en comer
*/

int		check_philos(t_list	*philos)
{
	t_philo *aux;

	while (1)
	{
		aux = philos->content;
		pthread_mutex_lock(&aux->last_eat_lock);
		if (ft_time() - aux->last_eat - aux->data->time_o >= aux->data->time_to_die)
		{
			pthread_mutex_lock(&aux->data->death_lock);
			aux->death = 1;
			pthread_mutex_unlock(&aux->data->death_lock);
			return (printf("philo is dead"));
		}
		pthread_mutex_unlock(&aux->last_eat_lock);
		pthread_mutex_lock(&aux->times_eat_lock);
		if (aux->data->num_eat * aux->data->num_philos == aux->data->times_eat)
		{
			pthread_mutex_lock(&aux->data->death_lock);
			aux->death = 1;
			pthread_mutex_unlock(&aux->data->death_lock);
			return (0);
		}
		pthread_mutex_unlock(&aux->times_eat_lock);
		philos = philos->next;
	}
}

/*
Cuando un filosofo coge dos tenedores tiene que imprimir que esta comiendo, 
actualizar la ultima hora a la que ha comido y sumar uno al contador de numero de veces
que ha comido
*/
void	*living_philo(void *philo)
{
	t_philo *fork1;
	t_philo	*fork2;

	ft_usleep(!(((t_philo *)philo)->id % 2) * 2);
	fork1 = ((t_list *)philo)->content;
	fokk2 = ((t_list *)philo)->next->content;
	while (1)
	{
		pthread_mutex_lock(&fork1->fork_lock);
		printf(" %d   [Philo %d] has grabbed a fork (1/2)\n", ((t_philo *)philo)->last_eat, ((t_philo *)philo)->id);
		pthread_mutex_lock(&fork2->fork_lock);
		pthread_mutex_lock(&((t_philo *)philo)->last_eat_lock);
		((t_philo *)philo)->last_eat = ft_time() - ((t_philo *)philo)->data->time_o; 
		pthread_mutex_unlock(&((t_philo *)philo)->last_eat_lock);
		pthread_mutex_unlock(&((t_philo *)philo)->fork_lock); // es el ultimo porque no puede soltar los tenedores hasta que termine
	}
	return NULL;
}

int	init_threads(t_data d, t_list *philos)
{
	t_list	*aux;
	t_philo	*p;
	int			i;

	i = 0;
	aux = philos;
	while (i < d.num_philos)
	{
		p = aux->content;
		if (pthread_create(&p->id_thread, NULL, living_philo, (void *)philos))
		{
			printf("Error creating thread\n");
			return (1);
		}
		aux = aux->next;
		i++;
	}
	// check_philos(philos);
	// por que aux está en el primero philo
	i = 0;
	while (i < d.num_philos)
	{
		p = philos->content;
		pthread_join(p->id, NULL);
		philos = philos->next;
		i++;
	}
	return (0);
}


