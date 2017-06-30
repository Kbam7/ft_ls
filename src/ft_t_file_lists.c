/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_t_file_lists.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbamping <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/17 18:00:22 by kbamping          #+#    #+#             */
/*   Updated: 2016/06/19 16:15:23 by kbamping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	init_t_file(t_file **new_list)
{
	ft_memset((*new_list)->permissions, 0, 11);
	(*new_list)->nlinks = 0;
	(*new_list)->u_name = "";
	(*new_list)->g_name = "";
	(*new_list)->byte_size = 0;
	(*new_list)->block_size = 0;
	(*new_list)->date = 0;
	(*new_list)->name = "";
	(*new_list)->path = "";
	(*new_list)->linkto = "";
	(*new_list)->next = NULL;
}

void	add_new_t_file(t_file **list, char *path, char *name)
{
	t_file	*new;
	t_file	*tmp;

	new = (t_file*)malloc(sizeof(t_file));
	if (new)
	{
		init_t_file(&new);
		new->path = ft_strjoin(new->path, path);
		new->name = ft_strjoin(new->name, name);
	}
	if (*list == NULL)
		*list = new;
	else
	{
		tmp = *list;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
		tmp = NULL;
		free(tmp);
	}
}

void	lstdel_t_file(t_file **list)
{
	t_file	*tmp;

	while (*list)
	{
		tmp = *list;
		*list = (*list)->next;
		free(tmp);
	}
}
