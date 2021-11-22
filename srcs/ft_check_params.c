/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlucie <hlucie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 11:52:11 by hlucie            #+#    #+#             */
/*   Updated: 2021/09/06 11:52:12 by hlucie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include.h"

void	ft_free_tab(int **tab)
{
	free(*tab);
	tab = NULL;
}

t_nb_list	*ft_parse_string_arg(char *str, t_nb_list *list)
{
	int	i;

	i = 0;
	while (str[i] && ft_is_in_str("-0123456789 ", str[i]))
	{
		while (str[i] == ' ')
			i++;
		ft_nb_lstadd_back(&list, ft_nb_lstnew(ft_atoi_custom(&(str[i]),
					&list)));
		while (str[i] && ft_is_in_str("-0123456789", str[i]))
			i++;
		while (str[i] == ' ')
			i++;
	}
	return (list);
}

int	ft_pars_arg(char **str, int nb_param)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < nb_param)
	{
		if (*str[i] == '\0')
			return (0);
		if (str[i][0] == '-')
			j++;
		while (str[i][j])
		{
			if (!ft_is_in_str("0123456789", str[i][j]))
				return (0);
			j++;
		}
		i++;
		j = 0;
	}
	return (1);
}

int	ft_check_double_params(t_nb_list *list)
{
	t_nb_list	*current_node;
	t_nb_list	*tmp_node;

	current_node = list;
	tmp_node = list->next;
	while (current_node->next)
	{
		while (tmp_node)
		{
			if (current_node->nb == tmp_node->nb)
			{
				ft_putstr_fd("Error\n", 2);
				return (0);
			}
			else
				tmp_node = tmp_node->next;
		}
		current_node = current_node->next;
		tmp_node = current_node->next;
	}
	return (1);
}

int	ft_check_sort(t_nb_list *list)
{
	while (list->next)
	{
		if (list->nb > list->next->nb)
			return (0);
		else
			list = list->next;
	}
	return (1);
}
