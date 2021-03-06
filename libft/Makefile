# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kbamping <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/28 14:01:24 by kbamping          #+#    #+#              #
#    Updated: 2016/06/19 14:41:15 by kbamping         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -Wall -Wextra -Werror

SRCS = src/ft_atoi.c src/ft_bzero.c src/ft_isalnum.c \
	src/ft_isalpha.c src/ft_isascii.c src/ft_isdigit.c \
	src/ft_islower.c src/ft_isprint.c src/ft_isupper.c \
	src/ft_itoa_base.c src/ft_itoa.c src/ft_memalloc.c \
	src/ft_memccpy.c src/ft_memchr.c src/ft_memcmp.c \
	src/ft_memcpy.c src/ft_memdel.c src/ft_memmove.c \
	src/ft_memset.c src/ft_putchar.c src/ft_putchar_fd.c \
	src/ft_putendl.c src/ft_putendl_fd.c src/ft_putnbr.c \
	src/ft_putnbr_fd.c src/ft_putstr.c src/ft_putstr_fd.c \
	src/ft_strcat.c src/ft_strchr.c src/ft_strclr.c \
	src/ft_strcmp.c src/ft_strcpy.c src/ft_strdel.c \
	src/ft_strdup.c src/ft_strequ.c src/ft_striter.c \
	src/ft_striteri.c src/ft_strjoin.c src/ft_strlcat.c \
	src/ft_strlen.c src/ft_strmap.c src/ft_strmapi.c \
	src/ft_strncat.c src/ft_strncmp.c src/ft_strncpy.c \
	src/ft_strnequ.c src/ft_strnew.c src/ft_strnjoin.c \
	src/ft_strnstr.c src/ft_strrchr.c src/ft_strrev.c \
	src/ft_strsplit.c src/ft_strstr.c src/ft_strsub.c \
	src/ft_strtrim.c src/ft_tolower.c src/ft_toupper.c \
	src/ft_uitoa.c src/ft_uitoa_base.c src/ft_ctostr.c \
	src/ft_gnl.c src/ft_lstadd.c src/ft_lstclear.c \
	src/ft_lstdel.c src/ft_lstdelone.c src/ft_lstiter.c \
	src/ft_lstlen.c src/ft_lstmap.c src/ft_lstnclear.c \
	src/ft_lstnew.c src/ft_lstpushback.c src/ft_lstrev.c \
	src/ft_printf/ft_printf.c src/ft_printf/ft_add_args.c \
	src/ft_printf/ft_process.c src/ft_printf/ft_utils.c \
	src/ft_strchr_end.c \

OBJS = ft_atoi.o ft_bzero.o ft_isalnum.o \
	ft_isalpha.o ft_isascii.o ft_isdigit.o \
	ft_islower.o ft_isprint.o ft_isupper.o \
	ft_itoa_base.o ft_itoa.o ft_memalloc.o \
	ft_memccpy.o ft_memchr.o ft_memcmp.o \
	ft_memcpy.o ft_memdel.o ft_memmove.o \
	ft_memset.o ft_putchar.o ft_putchar_fd.o \
	ft_putendl.o ft_putendl_fd.o ft_putnbr.o \
	ft_putnbr_fd.o ft_putstr.o ft_putstr_fd.o \
	ft_strcat.o ft_strchr.o ft_strclr.o \
	ft_strcmp.o ft_strcpy.o ft_strdel.o \
	ft_strdup.o ft_strequ.o ft_striter.o \
	ft_striteri.o ft_strjoin.o ft_strlcat.o \
	ft_strlen.o ft_strmap.o ft_strmapi.o \
	ft_strncat.o ft_strncmp.o ft_strncpy.o \
	ft_strnequ.o ft_strnew.o ft_strnjoin.o \
	ft_strnstr.o ft_strrchr.o ft_strrev.o \
	ft_strsplit.o ft_strstr.o ft_strsub.o \
	ft_strtrim.o ft_tolower.o ft_toupper.o \
	ft_uitoa.o ft_uitoa_base.o ft_ctostr.o \
	ft_gnl.o ft_lstadd.o ft_lstclear.o \
	ft_lstdel.o ft_lstdelone.o ft_lstiter.o \
	ft_lstlen.o ft_lstmap.o ft_lstnclear.o \
	ft_lstnew.o ft_lstpushback.o ft_lstrev.o \
	ft_printf.o ft_add_args.o ft_process.o \
	ft_utils.o ft_strchr_end.o \

all: $(NAME)

$(NAME):
	@echo "\033[01;33mlibft -- \033[00;32mCompiling files...\033[0m"
	@gcc $(FLAGS) -c $(SRCS) -I include
	@echo "\033[01;33mlibft -- \033[00;32mMaking archive...\033[0m"
	@ar rc libft.a $(OBJS)
	@ranlib $(NAME)
	@echo "\033[01;33mlibft -- \033[00;32mMaking 'objs' directory...\033[0m"
	@mkdir -p objs
	@mv $(OBJS) objs/
	@echo "\033[01;33mlibft -- \033[00;32m obj files moved to 'objs' dir...\033[0m"

clean:
	@rm -rf objs/
	@echo "\033[01;33mlibft -- \033[00;32mRemoved 'objs' directory...\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[01;33mlibft -- \033[00;32mRemoved '$(NAME)' archive...\033[0m"

re: fclean all
