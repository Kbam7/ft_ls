/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbamping <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/17 17:48:45 by kbamping          #+#    #+#             */
/*   Updated: 2016/06/19 16:15:23 by kbamping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*set_color(t_file *cur)
{
	struct stat sb;

	lstat(cur->path, &sb);
	if (S_ISDIR(sb.st_mode))
		return (ft_strjoin(ft_strjoin(FTLS_DIR, cur->name), C_NONE));
	else if (S_ISLNK(sb.st_mode))
		return (ft_strjoin(ft_strjoin(FTLS_LINK, cur->name), C_NONE));
	else if (S_ISFIFO(sb.st_mode))
		return (ft_strjoin(ft_strjoin(FTLS_FIFO, cur->name), C_NONE));
	else if (S_ISSOCK(sb.st_mode))
		return (ft_strjoin(ft_strjoin(FTLS_SOCK, cur->name), C_NONE));
	else if (S_ISBLK(sb.st_mode))
		return (ft_strjoin(ft_strjoin(FTLS_BLK, cur->name), C_NONE));
	else if (S_ISCHR(sb.st_mode))
		return (ft_strjoin(ft_strjoin(FTLS_CHR, cur->name), C_NONE));
	else if (cur->permissions[0] == '-' && ft_strchr(cur->permissions, 'x'))
		return (ft_strjoin(ft_strjoin(FTLS_EXEC, cur->name), C_NONE));
	else
		return (cur->name);
}
