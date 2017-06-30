/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbamping <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/17 18:08:41 by kbamping          #+#    #+#             */
/*   Updated: 2016/06/19 17:02:29 by kbamping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "../libft/include/libft.h"
# include <stdio.h>
# include <errno.h>
# include <dirent.h>
# include <sys/stat.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>

/*
** Colour definitions
*/
# define FTLS_DIR "\033[01;34m"
# define FTLS_LINK "\033[01;36m"
# define FTLS_FIFO "\033[40;33m"
# define FTLS_SOCK "\033[01;35m"
# define FTLS_BLK "\033[01;40;33m"
# define FTLS_CHR "\033[01;40;33m"
# define FTLS_EXEC "\033[01;32m"

/*
** Checks what system is being used to compile
*/
# ifdef __APPLE__
#  include "TargetConditionals.h"
#  if TARGET_OS_MAC
#   define TOTAL_DIV 1
#  else
#   error "Unknown Apple platform"
#  endif
# elif __linux__
#  define TOTAL_DIV 2
# elif __unix__
#  define TOTAL_DIV 1
# elif defined(_POSIX_VERSION)
#  define TOTAL_DIV 1
# else
#  error "Unknown compiler"
# endif

typedef struct	s_size
{
	int	total;
	int	size;
	int	groupspace;
	int	userspace;
	int	linkspace;
}				t_size;

typedef struct	s_lsdat
{
	int		a;
	int		d;
	int		f;
	int		g;
	int		l;
	int		r;
	int		up_r;
	int		t;
	int		u;
	int		up_u;
	int		n_path;
	t_size	size;
}				t_lsdat;

typedef struct	s_file_stats
{
	char				permissions[11];
	int					nlinks;
	char				*u_name;
	char				*g_name;
	int					byte_size;
	int					block_size;
	time_t				date;
	char				*name;
	char				*path;
	char				*linkto;
	struct s_file_stats	*next;
}				t_file;

void			ft_ls(t_lsdat *data, t_list **paths);
int				find_args(char *args);
int				get_args(char *arg_str, t_lsdat *data);
int				find_dirs(char *av, t_list **paths);
void			ft_recur(t_lsdat *data, char *path);
t_file			*ft_do_ls(char *path, t_lsdat **data, t_file *ent);
t_file			*ft_get_entries(char *path, t_lsdat **data, t_file *entlst);
char			*set_color(t_file *cur);
void			init_t_file(t_file **new_list);
void			add_new_t_file(t_file **list, char *path, char *name);
void			lstdel_t_file(t_file **list);
void			get_stat(t_lsdat **data, t_file **entlst);
void			ft_assign_stats(t_lsdat **data, t_file *ent, struct stat *sb);
void			get_perm(struct stat *sb, char *perm_arr);
t_lsdat			*get_sizes(t_lsdat *data, t_file *ent, struct stat *sb);
char			*ft_add_linkto(char *path);
char			*new_path(char *curr, char *ent_name);
char			*remove_slashes(char *path);
/*
** Print funcs
*/
void			print_t_file(t_file *list);
void			print_t_file_l(t_file *list, t_lsdat *data);
void			print_int(int nbr, int spacemax);
void			ft_ls_print_date(time_t date);
char			*ft_substr(int start, int len, char *str);
/*
** Sort funcs
*/
t_file			*sort_file_lst(t_file *list, t_lsdat data);
void			ft_ls_sort(t_file **list, int (*cmp)(t_file *, t_file *));
int				cmp_alpha(t_file *node1, t_file *node2);
int				cmp_time(t_file *node1, t_file *node2);
void			ft_ls_swap(t_file **node1, t_file **node2);
void			node_copy(t_file **src, t_file *cpy);
void			ft_rev_sort(t_file **list);

#endif
