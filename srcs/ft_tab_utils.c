/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlucie <hlucie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 11:53:10 by hlucie            #+#    #+#             */
/*   Updated: 2021/09/06 11:53:10 by hlucie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include.h"

t_nb_list	*ft_create_tmp_lst(t_nb_list *list)
{
	t_nb_list	*tmp;
	int			*tab;
	int			i;
	int			nb_elem;

	tmp = NULL;
	nb_elem = ft_check_nb(list);
	tab = ft_create_tab(list);
	if (!tab)
		return (NULL);
	i = 0;
	while (i < nb_elem)
	{
		ft_nb_lstadd_back(&tmp, ft_nb_lstnew(tab[i]));
		i++;
	}
	free (tab);
	tab = NULL;
	return (tmp);
}

int	*ft_create_tab(t_nb_list *list)
{
	int	*tab;
	int	i;
	int	nb_elem;

	i = 0;
	nb_elem = ft_check_nb(list);
	tab = malloc(sizeof(int) * nb_elem);
	if (!tab)
		return (NULL);
	while (list->next)
	{
		tab[i] = list->nb;
		list = list->next;
		i++;
	}
	tab[i] = list->nb;
	return (tab);
}
