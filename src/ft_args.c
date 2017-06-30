/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbamping <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/17 17:59:52 by kbamping          #+#    #+#             */
/*   Updated: 2016/06/19 17:04:12 by kbamping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		find_args(char *args)
{
	if (args && args[0] == '-' && args[1])
		return (1);
	return (0);
}

int		get_args(char *arg_str, t_lsdat *data)
{
	int	i;

	i = 0;
	while (arg_str[i++])
		if (ft_strchr("-adfglrRtuU", arg_str[i]))
		{
			data->a = ((arg_str[i] == 'a' || arg_str[i] == 'f') ? 1 : data->a);
			data->d = (arg_str[i] == 'd' ? 1 : data->d);
			data->f = (arg_str[i] == 'f' ? 1 : data->f);
			data->g = (arg_str[i] == 'g' ? 1 : data->g);
			data->l = (arg_str[i] == 'l' ? 1 : data->l);
			data->r = (arg_str[i] == 'r' ? 1 : data->r);
			data->up_r = (arg_str[i] == 'R' ? 1 : data->up_r);
			data->t = (arg_str[i] == 't' ? 1 : data->t);
			data->u = (arg_str[i] == 'u' ? 1 : data->u);
			data->up_u = (arg_str[i] == 'U' ? 1 : data->up_u);
		}
		else
		{
			ft_putstr_fd("\nft_ls: Argument error! Invalid argument ", 2);
			ft_putendl_fd(arg_str, 2);
			return (0);
		}
	return (i);
}

int		find_dirs(char *av, t_list **paths)
{
	DIR	*dir;
	int	c;

	c = 0;
	if ((dir = opendir(av)) == NULL)
	{
		ft_putstr_fd("ft_ls: Cannot Access '", 2);
		ft_putstr_fd(av, 2);
		perror("'");
	}
	else
	{
		++c;
		ft_lstpushback(paths, av, ft_strlen(av));
		closedir(dir);
	}
	return (c);
}
