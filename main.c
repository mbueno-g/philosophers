


void	error(char *message)
{
	ft_putendl_fd(message);
	exit(0);
}

void	init_t_philos(t_philos *p char **argv, int argc)
{
	p->num_philos = ft_atoi(argv[1]);
	p->time_to_eat = ft_atoi(argv[2]);
	p->time_to_sleep = ft_atoi(atgv[3]);
	p->time_to_die = ft_atoi(argv[4]);
	p->num_eat = 0;
	if (argc == 6)
		p->num_eat = ft_atoi(argv[5]);
	if (p->num_philos < 2 || p->time_to_eat < 0 || p->time_to_sleep < 0 || p->time_to_die < 0 || p->num_eat < 0)
		error("Invalid arguments");
}


int	main(int argc, char **argv)
{
	t_philos p;
	
	if (argc < 5 || argc > 6)
		error("Not enough arguments");
	init_t_philos(&p, argv);
}
