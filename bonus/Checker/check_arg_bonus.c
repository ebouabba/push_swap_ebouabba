/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouabba <ebouabba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 02:21:09 by ebouabba          #+#    #+#             */
/*   Updated: 2022/04/30 15:59:42 by ebouabba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

static	void	ft_check(t_list **lst, int n)
{
	t_list	*new_lst;

	new_lst = *lst;
	while ((new_lst)->next)
	{
		if (new_lst->content == n)
			print_error();
		new_lst = new_lst->next;
	}
}

void	check_arg_bonus(t_list **stack_a, char **av)
{
	char	**tab;
	int		i;
	int		len;

	len = 1;
	while (av[len])
	{
		tab = ft_split(av[len], ' ');
		if (tab[0] == NULL)
			print_error();
		i = 0;
		while (tab[i])
		{
			if ((tab[i][0] == '-' && !tab[i][1])
				|| (tab[i][0] == '+' && !tab[i][1]))
				print_error();
			ft_lstadd_back(stack_a, ft_lstnew(ft_atoi(tab[i])));
			ft_check(stack_a, ft_atoi(tab[i]));
			free(tab[i]);
			i++;
		}
		free(tab);
		len++;
	}
}
