/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlucie <hlucie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 11:52:07 by hlucie            #+#    #+#             */
/*   Updated: 2021/09/06 11:52:08 by hlucie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include.h"

int	ft_find_min_value(t_nb_list *list, int value)
{
	while (list)
	{
		if (list->nb < value)
			value = list->nb;
		else
			list = list->next;
	}
	return (value);
}

int	find_max_value(t_nb_list *list, int value)
{
	while (list)
	{
		if (list->nb > value)
			value = list->nb;
		else
			list = list->next;
	}
	return (value);
}

int	ft_find_median(int *tab, int nb_elem)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = 0;
	while (i < nb_elem - 1)
	{
		if (tab[i] > tab[i + 1])
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
	if (nb_elem >= 100)
		return (tab[nb_elem / 4]);
	else
		return (tab[nb_elem / 2]);
}

int	ft_check_median(t_nb_list *list)
{
	int	*tab;
	int	median;
	int	nb_elem;

	nb_elem = ft_check_nb(list);
	tab = ft_create_tab(list);
	median = ft_find_median(tab, nb_elem);
	free(tab);
	tab = NULL;
	return (median);
}

t_nb_list	*ft_calc_last(t_nb_list *list)
{
	t_nb_list	*last;

	last = list;
	while (last->next)
		last = last->next;
	return (last);
}
