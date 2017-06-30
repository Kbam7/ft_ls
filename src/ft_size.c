/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbamping <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/19 13:54:04 by kbamping          #+#    #+#             */
/*   Updated: 2016/06/19 16:43:34 by kbamping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_lsdat	*get_size_errorhandling(t_lsdat *data, struct stat *cur)
{
	if (getpwuid(cur->st_uid))
		data->size.userspace = (int)ft_strlen(getpwuid(cur->st_uid)->pw_name) \
			> data->size.userspace ? \
			(int)ft_strlen(getpwuid(cur->st_uid)->pw_name) \
			: data->size.userspace;
	else
		data->size.userspace = (int)ft_strlen(ft_itoa(cur->st_uid)) \
			> data->size.userspace ? (int)ft_strlen(ft_itoa(cur->st_uid)) \
			: data->size.userspace;
	if (getgrgid(cur->st_gid))
		data->size.groupspace = (int)ft_strlen(getgrgid(cur->st_gid)->gr_name)\
			> data->size.groupspace ? \
			(int)ft_strlen(getgrgid(cur->st_gid)->gr_name) \
			: data->size.groupspace;
	else
		data->size.groupspace = (int)ft_strlen(ft_itoa(cur->st_gid)) \
			> data->size.groupspace ? (int)ft_strlen(ft_itoa(cur->st_gid)) \
			: data->size.groupspace;
	return (data);
}

t_lsdat	*get_size_quick(t_lsdat *data, struct stat *cur)
{
	data->size.linkspace = (int)ft_strlen(ft_itoa(cur->st_nlink)) > \
		data->size.linkspace ? (int)ft_strlen(ft_itoa(cur->st_nlink)) \
		: data->size.linkspace;
	data->size.size = (int)ft_strlen(ft_itoa(cur->st_size)) > \
		data->size.size ? (int)ft_strlen(ft_itoa(cur->st_size)) \
		: data->size.size;
	data->size.total += cur->st_blocks;
	return (data);
}

t_lsdat	*get_sizes(t_lsdat *data, t_file *ent, struct stat *sb)
{
	if (!(data->a == 0 && ent->name[0] == '.'))
	{
		data = get_size_quick(data, sb);
		data = get_size_errorhandling(data, sb);
	}
	return (data);
}
