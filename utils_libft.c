/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_libft.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbueno-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 10:37:37 by mbueno-g          #+#    #+#             */
/*   Updated: 2021/10/12 14:01:47 by mbueno-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	cont;
	int	num;

	i = 0;
	cont = 1;
	num = 0;
	while ((str[i] == ' ') || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			cont = -cont;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + str[i] - '0';
		i++;
	}
	return (num * cont);
}

void    ft_lstadd_back(t_list **lst, t_list *new)
{
    if (!*lst)
        *lst = new;
    else
        ft_lstlast(*lst)->next = new;
}

t_list    *ft_lstlast(t_list *lst)
{
    int    len;

    len = ft_lstsize(lst);
    while (len > 1)
    {
        len--;
        lst = lst->next;
    }
    return (lst);
}

int    ft_lstsize(t_list *lst)
{
    int    len;

    len = 0;
    while (lst)
    {
        len++;
        lst = lst->next;
    }
    return (len);
}

t_list    *ft_lstnew(void *content)
{
    t_list    *lst;

    lst = malloc(sizeof(t_list));
    if (!lst)
        return (NULL);
    lst->content = content;
    lst->next = NULL;
    return (lst);
}
