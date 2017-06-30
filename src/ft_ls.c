/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbamping <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/17 17:57:34 by kbamping          #+#    #+#             */
/*   Updated: 2016/06/19 16:22:02 by kbamping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_ls(t_lsdat *data, t_list **paths)
{
	t_list	*tmp;

	if (data->f)
		data->r = 0;
	if (data->r)
		ft_lstrev(paths);
	tmp = *paths;
	while (tmp != NULL)
	{
		ft_recur(data, tmp->content);
		tmp = tmp->next;
	}
	free(tmp);
	ft_lstdel(paths, ft_bzero);
}

int		main(int ac, char **av)
{
	int		i;
	t_lsdat	data;
	t_list	*paths;

	i = 0;
	data = (t_lsdat){0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, {0, 0, 0, 0, 0}};
	paths = NULL;
	if (ac > 1)
	{
		while (++i < ac)
			if (find_args(av[i]))
				(get_args(av[i], &data) != 0) ? NULL : exit(0);
			else
			{
				data.n_path += find_dirs(av[i], &paths);
				(data.n_path != 0) ? NULL : exit(0);
			}
	}
	if (paths == NULL)
		ft_lstpushback(&paths, ".", 1);
	ft_ls(&data, &paths);
	return (0);
}
