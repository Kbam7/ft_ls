/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_recur.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbamping <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/17 18:01:03 by kbamping          #+#    #+#             */
/*   Updated: 2016/06/19 16:16:13 by kbamping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_recur(t_lsdat *data, char *path)
{
	struct stat	sb;
	t_file		*ent;
	t_file		*tmp;

	ent = NULL;
	ent = ft_do_ls(path, &data, ent);
	tmp = ent;
	while (tmp != NULL && data->up_r)
	{
		if (lstat(tmp->path, &sb) == -1)
			ft_printf("ft_ls: cannot get info for '%s': %s\n", \
											tmp->path, strerror(errno));
		if (ft_strcmp(tmp->name, ".") != 0 && ft_strcmp(tmp->name, "..") != 0)
			if (S_ISDIR(sb.st_mode))
				ft_recur(data, tmp->path);
		tmp = tmp->next;
	}
	lstdel_t_file(&ent);
}

t_file	*ft_do_ls(char *path, t_lsdat **data, t_file *ent)
{
	ent = ft_get_entries(path, data, ent);
	if (ent == NULL)
		return (NULL);
	if ((*data)->up_r || ((*data)->n_path > 0))
		ft_printf("%s:\n", path);
	if ((*data)->l)
	{
		ft_printf("total %d\n", (*data)->size.total / TOTAL_DIV);
		print_t_file_l(ent, *data);
	}
	else
		print_t_file(ent);
	if ((*data)->up_r || ((*data)->n_path > 0))
		write(1, "\n", 1);
	return (ent);
}
