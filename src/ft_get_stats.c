/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_stats.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbamping <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/17 18:02:31 by kbamping          #+#    #+#             */
/*   Updated: 2016/06/19 16:15:23 by kbamping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	get_stat(t_lsdat **data, t_file **entlst)
{
	struct stat		sb;
	t_file			*tmp;

	tmp = *entlst;
	(*data)->size = (t_size){0, 0, 0, 0, 0};
	while (tmp != NULL)
	{
		if (lstat(tmp->path, &sb) == -1)
		{
			perror("Error in get_stat");
			return ;
		}
		else
			ft_assign_stats(data, tmp, &sb);
		tmp = tmp->next;
	}
}

void	ft_assign_stats(t_lsdat **data, t_file *ent, struct stat *sb)
{
	get_perm(sb, ent->permissions);
	ent->nlinks = (int)sb->st_nlink;
	if ((*data)->g == 0)
	{
		if (getpwuid(sb->st_uid))
			ent->u_name = getpwuid(sb->st_uid)->pw_name;
		else
			ent->u_name = ft_itoa(sb->st_uid);
	}
	if (getgrgid(sb->st_gid))
		ent->g_name = getgrgid(sb->st_gid)->gr_name;
	else
		ent->g_name = ft_itoa(sb->st_gid);
	ent->byte_size = (int)sb->st_size;
	ent->block_size = (int)sb->st_blocks;
	ent->date = ((*data)->u == 1 ? sb->st_atime : sb->st_mtime);
	if (S_ISLNK(sb->st_mode))
		ent->linkto = ft_add_linkto(ent->path);
	*data = get_sizes(*data, ent, sb);
}

void	get_perm(struct stat *sb, char *perm_arr)
{
	perm_arr[0] = (S_ISREG(sb->st_mode)) ? '-' : perm_arr[0];
	perm_arr[0] = (S_ISFIFO(sb->st_mode)) ? 'p' : perm_arr[0];
	perm_arr[0] = (S_ISCHR(sb->st_mode)) ? 'c' : perm_arr[0];
	perm_arr[0] = (S_ISDIR(sb->st_mode)) ? 'd' : perm_arr[0];
	perm_arr[0] = (S_ISBLK(sb->st_mode)) ? 'b' : perm_arr[0];
	perm_arr[0] = (S_ISLNK(sb->st_mode)) ? 'l' : perm_arr[0];
	perm_arr[0] = (S_ISSOCK(sb->st_mode)) ? 's' : perm_arr[0];
	perm_arr[1] = (sb->st_mode & S_IRUSR) ? 'r' : '-';
	perm_arr[2] = (sb->st_mode & S_IWUSR) ? 'w' : '-';
	perm_arr[3] = (sb->st_mode & S_IXUSR) ? 'x' : '-';
	perm_arr[4] = (sb->st_mode & S_IRGRP) ? 'r' : '-';
	perm_arr[5] = (sb->st_mode & S_IWGRP) ? 'w' : '-';
	perm_arr[6] = (sb->st_mode & S_IXGRP) ? 'x' : '-';
	perm_arr[7] = (sb->st_mode & S_IROTH) ? 'r' : '-';
	perm_arr[8] = (sb->st_mode & S_IWOTH) ? 'w' : '-';
	perm_arr[9] = (sb->st_mode & S_IXOTH) ? 'x' : '-';
	perm_arr[10] = '\0';
}

char	*ft_add_linkto(char *path)
{
	char	*linkto;

	linkto = ft_strnew(4096);
	if ((readlink(path, linkto, 4096) == -1))
		perror("add_linkto Error");
	return (linkto);
}
