/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlucie <hlucie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 11:53:18 by hlucie            #+#    #+#             */
/*   Updated: 2021/09/13 11:07:55 by hlucie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include.h"

int	ft_manage_negative(t_nb_list *list, char *str, int i)
{
	if (str[i] == '-')
	{
		if (ft_isdigit(str[i + 1]) && (i == 0 || str[i - 1] == ' '))
			i++;
		else
		{
			ft_putstr_fd("Error\n", 2);
			ft_free_lst(&list);
			exit (0);
		}
	}
	return (i);
}

t_nb_list	*ft_extrac_arg(char **str, t_nb_list *list, int nb_param)
{
	int	i;

	i = 1;
	if (!ft_pars_arg(str, nb_param))
	{
		ft_free_lst(&list);
		ft_putstr_fd("Error\n", 2);
		exit (0);
	}
	while (i < nb_param)
	{
		ft_nb_lstadd_back(&list, ft_nb_lstnew(ft_atoi_custom(str[i], &list)));
		i++;
	}
	return (list);
}

t_nb_list	*ft_extract_string_arg(char *str, t_nb_list *list)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		i = ft_manage_negative(list, str, i);
		if (!ft_is_in_str("0123456789 ", str[i]))
		{
			ft_free_lst(&list);
			ft_putstr_fd("Error\n", 2);
			exit (0);
		}
	}
	list = ft_parse_string_arg(str, list);
	return (list);
}

int	ft_create_lst(char **str, int nb_param)
{
	t_nb_list	*first_list;
	t_nb_list	*second_list;

	first_list = NULL;
	second_list = NULL;
	if (str[1][0] == '\0')
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	if (nb_param == 2)
		first_list = ft_extract_string_arg(str[1], first_list);
	else
		first_list = ft_extrac_arg(str, first_list, nb_param);
	if (!ft_check_double_params(first_list) || ft_check_sort(first_list))
	{
		ft_free_lst(&first_list);
		return (1);
	}
	else
		ft_choose_case(&first_list, &second_list);
	ft_free_lst(&first_list);
	return (1);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	if (!(ft_create_lst(argv, argc)))
		return (0);
	return (0);
}
