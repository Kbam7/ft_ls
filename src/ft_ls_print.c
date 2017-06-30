/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbamping <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/17 17:58:25 by kbamping          #+#    #+#             */
/*   Updated: 2016/06/19 16:46:16 by kbamping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_t_file(t_file *list)
{
	t_file	*tmp;

	tmp = list;
	while (tmp)
	{
		ft_putstr(set_color(tmp));
		ft_putstr("    ");
		tmp = tmp->next;
	}
	write(1, "\n", 1);
}

void	print_t_file_l(t_file *list, t_lsdat *data)
{
	t_file	*tmp;

	tmp = list;
	while (tmp)
	{
		ft_putstr(tmp->permissions);
		write(1, " ", 1);
		print_int(tmp->nlinks, data->size.linkspace);
		write(1, " ", 1);
		ft_putstr(tmp->u_name);
		write(1, " ", 1);
		ft_putstr(tmp->g_name);
		write(1, " ", 1);
		print_int(tmp->byte_size, data->size.size);
		write(1, " ", 1);
		ft_ls_print_date(tmp->date);
		write(1, " ", 1);
		ft_putstr(set_color(tmp));
		if (ft_strlen(tmp->linkto))
			ft_printf(" -> %s", tmp->linkto);
		write(1, "\n", 1);
		tmp = tmp->next;
	}
}

void	print_int(int nbr, int spacemax)
{
	int		n;

	n = spacemax - ft_strlen(ft_itoa(nbr));
	while (n-- > 0)
		write(1, " ", 1);
	ft_putnbr(nbr);
}

void	ft_ls_print_date(time_t date)
{
	char	*str1;
	char	*str2;
	time_t	curr;

	curr = time(0);
	str1 = ctime(&date);
	if ((curr - 15778463) > date || curr < date)
	{
		str2 = ft_strnew(6);
		str2 = ft_strsub(str1, 20, 4);
		str1 = ft_strsub(str1, 4, 6);
		str1 = ft_strjoin(str1, "  ");
		str1 = ft_strjoin(str1, str2);
		free(str2);
	}
	else
		str1 = ft_strsub(str1, 4, 12);
	str1[12] = '\0';
	ft_putstr(str1);
	ft_putchar(' ');
	free(str1);
}

char	*ft_substr(int start, int len, char *str)
{
	char	*n_str;
	int		c;

	n_str = NULL;
	c = 0;
	if ((n_str = (char *)malloc(sizeof(char) * (len + 1))))
	{
		while (c < len && (str[start + c] != '\0'))
		{
			n_str[c] = str[start + c];
			c++;
		}
		n_str[c] = '\0';
	}
	return (n_str);
}
