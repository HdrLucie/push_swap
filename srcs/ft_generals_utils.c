/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generals_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlucie <hlucie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 11:52:16 by hlucie            #+#    #+#             */
/*   Updated: 2021/09/09 12:41:11 by hlucie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include.h"

static int	ft_white_space(char *str)
{
	int		i;

	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
			|| str[i] == '\f' || str[i] == '\v' || str[i] == '\r'))
		i++;
	return (i);
}

void	ft_is_negative(long long int res, int negatif, t_nb_list **list)
{
	if (res * negatif < INT_MIN || res * negatif > INT_MAX)
	{
		ft_free_lst(list);
		ft_putstr_fd("Error\n", 2);
		exit (0);
	}
}

int	ft_atoi_custom(char *nptr, t_nb_list **list)
{
	int				i;
	long long int	res;
	int				negatif;

	i = ft_white_space(nptr);
	negatif = 1;
	res = 0;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			negatif = -1;
		i++;
	}
	while (nptr[i] && nptr[i] >= '0' && nptr[i] <= '9')
	{
		ft_is_negative(res, negatif, list);
		res = res * 10;
		res = res + (nptr[i] - '0');
		i++;
	}
	return (res * negatif);
}

int	ft_check_nb(t_nb_list *list)
{
	int	counter;

	counter = 1;
	while (list->next)
	{
		counter++;
		list = list->next;
	}
	return (counter);
}

int	ft_check_median_tab(t_nb_list **list, int median)
{
	int	i;
	int	*tab;
	int	nb_elem;

	i = 0;
	tab = ft_create_tab(*list);
	nb_elem = ft_check_nb(*list);
	while (i < nb_elem)
	{
		if (tab[i] < median)
		{
			free(tab);
			return (1);
		}
		i++;
	}
	free(tab);
	tab = NULL;
	return (0);
}
