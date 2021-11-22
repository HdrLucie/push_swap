/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_median_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlucie <hlucie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 11:52:57 by hlucie            #+#    #+#             */
/*   Updated: 2021/09/06 17:10:31 by hlucie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include.h"

int	ft_find_closer_side(t_nb_list *list, int median)
{
	int	size_lst;
	int	nb_up_coup;
	int	nb_down_coup;
	int	nb_coup;

	nb_up_coup = 0;
	nb_down_coup = 0;
	nb_coup = 0;
	size_lst = ft_check_nb(list);
	while (list)
	{
		nb_coup++;
		if (nb_coup <= size_lst / 3 && list->nb < median && nb_up_coup == 0)
			nb_up_coup = nb_coup;
		else if (nb_coup > size_lst / 3 && list->nb < median
			&& nb_down_coup == 0)
			nb_down_coup = size_lst - nb_coup;
		list = list->next;
	}
	if ((nb_up_coup != 0 && nb_up_coup <= nb_down_coup) || nb_down_coup == 0)
		return (1);
	else
		return (0);
}

int	ft_find_max_side(t_nb_list *list, int max)
{
	int	size_lst;
	int	nb_coup;

	nb_coup = 0;
	size_lst = ft_check_nb(list);
	while (list)
	{
		if (list->nb != max)
			nb_coup++;
		else
			return (nb_coup <= size_lst / 2);
		list = list->next;
	}
	return (-1);
}

void	ft_swap_med(t_nb_list **don, t_nb_list **rcvr, int med, t_nb_list *last)
{
	last = NULL;
	while (ft_check_nb(*don) >= 3)
	{
		last = ft_calc_last(*don);
		if (ft_find_closer_side(*don, med))
		{
			if ((*don)->nb < med)
				ft_push_b(don, rcvr);
			if ((*don)->nb >= med)
			{
				if (last->nb < med)
				{
					*don = ft_reverse(*don, 'a');
					ft_push_b(don, rcvr);
				}
				else if (ft_check_median_tab(don, med))
					*don = ft_rotate(*don, 'a');
				else
					return ;
			}
		}
		else
			*don = ft_reverse(*don, 'a');
	}
}

void	ft_fusion_lst(t_nb_list **don, t_nb_list **rec)
{
	t_nb_list	*last;

	last = ft_calc_last(*don);
	if (ft_check_nb(*don) >= 2)
	{
		if (ft_check_nb(*don) == 3 && (*don)->next->nb > (*don)->nb
			&& ((*don)->nb) > last->nb)
		{
			ft_swap_first(*don, 'b');
			ft_push_a(rec, don);
		}
		else if ((*don)->next->nb == find_max_value(*don, (*don)->next->nb))
			ft_swap_first(*don, 'b');
		if ((*don)->nb == find_max_value(*don, (*don)->nb))
			ft_push_a(rec, don);
		else if (!ft_find_max_side(*don, find_max_value(*don, (*don)->nb)))
			*don = ft_reverse(*don, 'b');
		else
			*don = ft_rotate(*don, 'b');
	}
}

t_nb_list	*ft_median_sort(t_nb_list **first_list, t_nb_list **sec_list)
{
	int			median;
	t_nb_list	*last;

	last = NULL;
	median = 0;
	while (ft_check_nb(*first_list) > 3)
	{
		median = ft_check_median(*first_list);
		ft_swap_med(first_list, sec_list, median, last);
	}
	last = ft_calc_last(*first_list);
	if (ft_check_nb(*first_list) == 3)
	{
		if (!ft_simple_operation(first_list, last))
			ft_double_operation(first_list, last);
	}
	else if ((*first_list)->nb > (*first_list)->next->nb)
		ft_swap_first(*first_list, 'a');
	while (ft_check_nb(*sec_list) > 1)
		ft_fusion_lst(sec_list, first_list);
	if (ft_check_nb(*sec_list) == 1)
		ft_push_a(first_list, sec_list);
	return (*sec_list);
}
