# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kbamping <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/16 07:43:07 by kbamping          #+#    #+#              #
#    Updated: 2016/06/19 16:10:59 by kbamping         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

ERR_FLAGS = -Wall -Wextra -Werror

SRCS = src/ft_args.c src/ft_ls_print.c src/ft_ls.c \
		src/ft_ls_recur.c src/ft_get_entries.c src/ft_t_file_lists.c \
		src/ft_get_stats.c src/ft_set_color.c src/ft_size.c \
		src/ft_ls_sort.c src/ft_ls_sort_funcs.c \

OBJS = ft_args.o ft_ls_print.o ft_ls.o ft_ls_recur.o ft_get_entries.o \
		ft_t_file_lists.o ft_get_stats.o ft_set_color.o ft_size.o \
		ft_ls_sort.o ft_ls_sort_funcs.o \

all: $(NAME)

$(NAME):
	@make all -C ./libft
	@gcc $(ERR_FLAGS) -I include/ $(SRCS) -L./libft/ -lft -o $(NAME)
	@echo "\033[01;33m$(NAME) -- \033[00;32mCreated '$(NAME)' executable..\033[0m"

run:
	rm -f $(NAME)
	@$(MAKE) all


clean: lib_clean

fclean: lib_fclean
	@rm -f $(NAME)
	@echo "\033[01;33m$(NAME) -- \033[00;32mRemoved '$(NAME)' executable...\033[0m"

re: fclean all

lib_clean:
	@make clean -C ./libft

lib_fclean:
	@make fclean -C ./libft

lib_re: lib_fclean lib_all
