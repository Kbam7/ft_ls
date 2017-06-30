/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbamping <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/19 15:02:32 by kbamping          #+#    #+#             */
/*   Updated: 2016/06/19 16:15:23 by kbamping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file	*sort_file_lst(t_file *list, t_lsdat data)
{
	t_file	*new;

	if (!list)
		return (NULL);
	new = list;
	if (data.f == 0)
	{
		ft_ls_sort(&new, cmp_alpha);
		(data.t == 1 || data.u == 1) ? ft_ls_sort(&new, cmp_time) : NULL;
		data.r == 1 ? ft_rev_sort(&new) : NULL;
	}
	return (new);
}

void	ft_ls_sort(t_file **list, int (*cmp)(t_file *, t_file *))
{
	t_file	*node1;
	t_file	*node2;

	node1 = *list;
	while (node1)
	{
		node2 = node1->next;
		while (node2)
		{
			if (cmp(node1, node2) > 0)
				ft_ls_swap(&node1, &node2);
			node2 = node2->next;
		}
		node1 = node1->next;
	}
}
