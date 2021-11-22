#ifndef INCLUDE_H
# define INCLUDE_H

# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_nb_list
{
	int					nb;
	struct s_nb_list	*next;
}					t_nb_list;

typedef struct s_value
{
	int	*first;
	int	*second;
	int	*last;
}					t_value;

int			ft_check_nb(t_nb_list *list);
void		ft_nb_lstadd_back(t_nb_list **alst, t_nb_list *new);
t_nb_list	*ft_nb_lstlast(t_nb_list *lst);
t_nb_list	*ft_nb_lstnew(int nb);
int			ft_find_median_list(t_nb_list *list);
int			ft_simple_operation(t_nb_list **list, t_nb_list *last);
int			ft_double_operation(t_nb_list **list, t_nb_list *last);
int			ft_atoi_custom(char *nptr, t_nb_list **list);
t_nb_list	*ft_parse_string_arg(char *str, t_nb_list *list);

t_nb_list	*ft_create_tmp_lst(t_nb_list *list);
void		ft_print_int_tab(int *tab, t_nb_list *list);
void		ft_print_utils(t_nb_list *first_list, t_nb_list *second_list);
int			*ft_create_tab(t_nb_list *list);
void		ft_free_lst(t_nb_list **list);

void		ft_push(t_nb_list **donnor, t_nb_list **receiver);
void		ft_push_a(t_nb_list **first_list, t_nb_list **sec_list);
void		ft_push_b(t_nb_list **first_list, t_nb_list **sec_list);
void		ft_swap_nb(t_nb_list *lst1, t_nb_list *lst2);
void		ft_swap_first(t_nb_list *list, char c);
t_nb_list	*ft_rotate(t_nb_list *lst, char c);
t_nb_list	*ft_reverse(t_nb_list *lst, char c);

void		ft_sort_five(t_nb_list **first_list, t_nb_list **sec_list);
int			ft_choose_case(t_nb_list **first_list, t_nb_list **sec_list);
t_nb_list	*ft_median_sort(t_nb_list **first_list, t_nb_list **sec_list);
int			ft_choose_multi_case(t_nb_list **f_list,
				t_nb_list **s_list, t_nb_list *l);

int			find_max_value(t_nb_list *list, int value);
int			ft_find_median(int *tab, int nb_elem);
int			ft_check_median(t_nb_list *list);
t_nb_list	*ft_calc_last(t_nb_list *list);
int			ft_check_median_tab(t_nb_list **list, int median);
int			ft_check_sort(t_nb_list *list);
int			ft_check_double_params(t_nb_list *list);
int			ft_pars_arg(char **str, int nb_param);
int			ft_find_min_value(t_nb_list *list, int value);

#endif
