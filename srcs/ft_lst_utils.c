/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlucie <hlucie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 11:52:53 by hlucie            #+#    #+#             */
/*   Updated: 2021/09/06 11:52:54 by hlucie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include.h"

t_nb_list	*ft_nb_lstlast(t_nb_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	ft_nb_lstadd_back(t_nb_list **alst, t_nb_list *new)
{
	t_nb_list	*tmp;

	tmp = NULL;
	tmp = ft_nb_lstlast(*alst);
	if (tmp == NULL)
		*alst = new;
	else
		tmp->next = new;
	new->next = NULL;
}

t_nb_list	*ft_nb_lstnew(int nb)
{
	t_nb_list	*list;

	list = malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->nb = nb;
	list->next = NULL;
	return (list);
}

void	ft_free_lst(t_nb_list **list)
{
	t_nb_list	*tmp;

	tmp = *list;
	if (list)
	{
		while (*list)
		{
			tmp = *list;
			(*list) = (*list)->next;
			free(tmp);
		}
	}
	*list = NULL;
}
