/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_sort_funcs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbamping <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/19 16:12:33 by kbamping          #+#    #+#             */
/*   Updated: 2016/06/19 16:31:17 by kbamping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		cmp_alpha(t_file *node1, t_file *node2)
{
	return (ft_strcmp(node1->name, node2->name));
}

int		cmp_time(t_file *node1, t_file *node2)
{
	return (node1->date < node2->date);
}

void	ft_ls_swap(t_file **node1, t_file **node2)
{
	t_file	tmp;

	tmp = **node1;
	node_copy(node1, *node2);
	node_copy(node2, &tmp);
}

void	node_copy(t_file **src, t_file *cpy)
{
	ft_strcpy((*src)->permissions, cpy->permissions);
	(*src)->nlinks = cpy->nlinks;
	(*src)->u_name = cpy->u_name;
	(*src)->g_name = cpy->g_name;
	(*src)->byte_size = cpy->byte_size;
	(*src)->block_size = cpy->block_size;
	(*src)->date = cpy->date;
	(*src)->name = cpy->name;
	(*src)->path = cpy->path;
	(*src)->linkto = cpy->linkto;
}

void	ft_rev_sort(t_file **list)
{
	t_file	*tmp;
	t_file	*tmp1;
	t_file	*tmp2;

	tmp = *list;
	tmp1 = NULL;
	while (tmp)
	{
		tmp2 = tmp1;
		tmp1 = tmp;
		tmp = tmp->next;
		tmp1->next = tmp2;
	}
	*list = tmp1;
}
