/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbueno-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 10:28:48 by mbueno-g          #+#    #+#             */
/*   Updated: 2021/10/12 14:01:32 by mbueno-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdlib.h>

typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

typedef struct s_data
{
	int					num_philos; //max num de hilos
	unsigned long long	time_to_eat; //mirar limite gettimeofday
	unsigned long long	time_to_sleep;
	unsigned long long	time_to_die;
	unsigned long long	num_eat;
	useconds_t			time_o;

}			t_data;

typedef struct s_philo
{
	int					id;
	pthread_t			id_thread;
	useconds_t			last_eat;
	struct	s_data		*data;	
}			t_philo;


useconds_t	ft_time(void);
t_philo		*new_philo(t_data *d, int i);
t_list    *ft_lstnew(void *content);




/*
 * ==========================================
 *Libft functions
 * =========================================
*/

void	ft_putendl_fd(char *s, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
int		ft_atoi(const char *str);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);


#endif
