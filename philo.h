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


#define FORK1 "\033[0;37mhas grabbed a fork 🥢\033[0;39m"
#define FORK2 "\033[0;37mhas grabbed a fork 🥢 🥢\033[0;39m"
#define EAT "\033[1;93mis eating 🍣\033[0;39m"
#define SLEEP "\033[1;32mis sleeping 💤\033[0;39m"
#define THINK "\033[1;96mis thinking ​💫​\033[0;39m"
#define DEAD "\033[1;41mis dead ⚰️\033[0;39m"

typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

typedef struct s_data
{
	int				num_philos; //max num de hilos
	long long		time_to_eat; //mirar limite gettimeofday
	long long		time_to_sleep;
	long long		time_to_die;
	long long		num_eat;
	int				death;
	long long		times_eat;
	useconds_t		time_o;
	pthread_mutex_t	times_eat_lock;
	pthread_mutex_t	death_lock;
}			t_data;

typedef struct s_philo
{
	int					id;
	pthread_t			id_thread;
	pthread_mutex_t		fork_lock;
	pthread_mutex_t		last_eat_lock;
	useconds_t			last_eat;
	struct	s_data		*data;	
}			t_philo;


useconds_t	ft_time(void);
t_philo		*new_philo(t_data *d, int i);
int			init_threads(t_data d, t_list *philos);
int			ft_usleep(useconds_t usec);

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
t_list	*ft_lstnew(void *content);
void	ft_lstclear(t_list **lst, void (*del)(void *));
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *str);

#endif
