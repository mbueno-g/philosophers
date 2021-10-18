

void	*lived_philo(void *philo)
{
		
}

int	init_thread(t_data d, t_list *philos)
{
	t_list	*aux;
	t_philo	*p;
	int			i;

	i = 0;
	aux = philos;
	while (i < d->num_philos)
	{
		p = aux->content;
		if (pthread_create(&p->id_thread, NULL, lived_philo, (void *)philo))
			return (1);
		aux = aux->next;
		i++;
	}
	//check_philos();

	return (0);
}


