/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlucie <hlucie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 11:52:19 by hlucie            #+#    #+#             */
/*   Updated: 2021/09/06 11:52:20 by hlucie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include.h"

void	ft_push(t_nb_list **donnor, t_nb_list **receiver)
{
	t_nb_list	*tmp;
	t_nb_list	*tmp2;

	tmp2 = (*donnor)->next;
	tmp = *receiver;
	*receiver = *donnor;
	(*receiver)->next = tmp;
	*donnor = tmp2;
}

void	ft_swap_nb(t_nb_list *lst1, t_nb_list *lst2)
{
	int	tmp;

	tmp = lst1->nb;
	lst1->nb = lst2->nb;
	lst2->nb = tmp;
}

void	ft_swap_first(t_nb_list *list, char c)
{
	ft_swap_nb(list, list->next);
	if (c == 'a')
		ft_putstr_fd("sa\n", 1);
	else if (c == 'b')
		ft_putstr_fd("sb\n", 1);
}

t_nb_list	*ft_reverse(t_nb_list *lst, char c)
{
	t_nb_list	*new_top;
	t_nb_list	*old_top;

	new_top = NULL;
	old_top = lst;
	while (lst->next->next)
		lst = lst->next;
	new_top = lst->next;
	lst->next = NULL;
	new_top->next = old_top;
	if (c == 'a')
		ft_putstr_fd("rra\n", 1);
	else if (c == 'b')
		ft_putstr_fd("rrb\n", 1);
	return (new_top);
}

t_nb_list	*ft_rotate(t_nb_list *lst, char c)
{
	t_nb_list	*tmp;
	t_nb_list	*last;

	last = lst;
	while (last->next)
		last = last->next;
	tmp = lst->next;
	last->next = lst;
	lst->next = NULL;
	if (c == 'a')
		ft_putstr_fd("ra\n", 1);
	else if (c == 'b')
		ft_putstr_fd("rb\n", 1);
	return (tmp);
}
