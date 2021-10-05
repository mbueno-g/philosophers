
#ifndef PHILO_H
#define PHILO_H

# include <pthread>

typedef struct s_philos
{
	unsigned long	num_philos;
	unsigned long	time_to_eat;
	unsigned long	time_to_sleep;
	unsigned long	time_to_die;
	unsigned long	num_eat;
	
}							t_philos;




/*
 * ==========================================
 *Libft functions
 * =========================================
*/

void	ft_putendl_fd(char *s, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
int		ft_atoi(const char *str);






#endif
