/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_which_algo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlucie <hlucie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 11:53:14 by hlucie            #+#    #+#             */
/*   Updated: 2021/09/06 11:53:15 by hlucie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include.h"

int	ft_simple_operation(t_nb_list **list, t_nb_list *last)
{
	if ((*list)->nb > (*list)->next->nb && (*list)->next->nb < last->nb
		&& (*list)->nb < last->nb)
	{
		ft_swap_first(*list, 'a');
		return (1);
	}
	else if ((*list)->nb > (*list)->next->nb && (*list)->next->nb < last->nb
		&& (*list)->nb > last->nb)
	{
		(*list) = ft_rotate(*list, 'a');
		return (1);
	}
	else if ((*list)->nb < (*list)->next->nb && (*list)->next->nb > last->nb
		&& (*list)->nb > last->nb)
	{
		(*list) = ft_reverse(*list, 'a');
		return (1);
	}
	return (0);
}

int	ft_double_operation(t_nb_list **list, t_nb_list *last)
{
	if ((*list)->nb > (*list)->next->nb && (*list)->next->nb > last->nb)
	{
		ft_swap_first(*list, 'a');
		(*list) = ft_reverse(*list, 'a');
		return (1);
	}
	else if ((*list)->nb < (*list)->next->nb && (*list)->next->nb > last->nb
		&& (*list)->nb < last->nb)
	{
		ft_swap_first(*list, 'a');
		(*list) = ft_rotate(*list, 'a');
		return (1);
	}
	return (0);
}

int	ft_choose_case(t_nb_list **first_list, t_nb_list **sec_list)
{
	int			counter;
	t_nb_list	*last;

	last = ft_calc_last(*first_list);
	counter = ft_check_nb((*first_list));
	if (counter == 2)
	{
		if ((*first_list)->nb > (*first_list)->next->nb)
		{
			ft_swap_first(*first_list, 'a');
			ft_free_lst(first_list);
			exit (0);
		}
	}
	else if (counter == 3)
	{
		if (ft_simple_operation(first_list, last))
			return (1);
		else if (ft_double_operation(first_list, last))
			return (1);
	}
	else
		ft_median_sort(first_list, sec_list);
	return (0);
}
