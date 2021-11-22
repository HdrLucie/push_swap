/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlucie <hlucie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 11:53:01 by hlucie            #+#    #+#             */
/*   Updated: 2021/09/06 11:53:02 by hlucie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include.h"

void	ft_push_a(t_nb_list **first_list, t_nb_list **sec_list)
{
	if (*sec_list)
		ft_push(sec_list, first_list);
	ft_putstr_fd("pa\n", 1);
}

void	ft_push_b(t_nb_list **first_list, t_nb_list **sec_list)
{
	if (*first_list)
		ft_push(first_list, sec_list);
	ft_putstr_fd("pb\n", 1);
}

void	ft_print_int_tab(int *tab, t_nb_list *list)
{
	int	i;
	int	nb_elem;

	nb_elem = ft_check_nb(list);
	i = 0;
	while (i < nb_elem)
	{
		printf("%d\n", tab[i]);
		i++;
	}
}

void	ft_print_utils(t_nb_list *first_list, t_nb_list *second_list)
{
	while (first_list || second_list)
	{
		if (first_list)
		{
			printf("%d", first_list->nb);
			first_list = first_list->next;
		}
		printf(" | ");
		if (second_list)
		{
			printf("second : %d", second_list->nb);
			second_list = second_list->next;
		}
		printf("\n");
	}
}
