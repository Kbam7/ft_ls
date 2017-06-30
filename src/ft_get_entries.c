/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_entries.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbamping <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/17 18:02:45 by kbamping          #+#    #+#             */
/*   Updated: 2016/06/21 12:37:22 by kbamping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file	*ft_get_entries(char *path, t_lsdat **data, t_file *entlst)
{
	DIR				*dir;
	struct dirent	*ent;

	dir = opendir(path);
	if (dir == NULL)
	{
		ft_printf("ft_ls: cannot open directory '%s': %s\n", \
													path, strerror(errno));
		return (NULL);
	}
	while ((ent = readdir(dir)) != NULL)
	{
		if ((*data)->a == 0 && ent->d_name[0] == '.')
			continue;
		add_new_t_file(&entlst, new_path(path, ent->d_name), ent->d_name);
	}
	closedir(dir);
	if ((*data)->l)
		get_stat(data, &entlst);
	entlst = sort_file_lst(entlst, **data);
	return (entlst);
}

char	*new_path(char *curr, char *ent_name)
{
	int		i;

	if (*curr && *ent_name)
	{
		i = ft_strlen(curr) - 1;
		if (!(ft_strchr_end(curr, '/')))
			curr = ft_strjoin(curr, "/");
		if (curr[i] == '/' && curr[i - 1] == '/')
			curr = remove_slashes(curr);
		curr = ft_strjoin(curr, ent_name);
	}
	return (curr);
}

char	*remove_slashes(char *path)
{
	int		i;

	if (*path)
	{
		i = ft_strlen(path) - 1;
		while (path[i] == '/' && path[i - 1] == '/')
		{
			path[i] = '\0';
			--i;
		}
	}
	return (path);
}
