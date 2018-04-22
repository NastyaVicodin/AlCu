#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alukyane <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/25 22:31:54 by alukyane          #+#    #+#              #
#    Updated: 2017/11/29 18:46:04 by alukyane         ###   ########.fr        #
#                                                                              #
#******************************************************************************#
NAME = alum1
SRCS = 	main.c 																	\
		ft_bzero.c 																\
		ft_lstnew.c 															\
		ft_memccpy.c 															\
		ft_memcpy.c 															\
		ft_memdel.c 															\
		ft_memmove.c 															\
		ft_memset.c 															\
		ft_strchr.c 															\
		ft_strclr.c 															\
		ft_strdup.c 															\
		ft_strjoin.c 															\
		ft_strlen.c 															\
		ft_strncat.c 															\
		ft_strnew.c ft_strrchr.c ft_strsub.c 									\
		get_next_line.c 														\
		f_valid.c 																\
		my_ft_setyourchar.c 													\
		ft_atoi.c 																\
		f_wright_exact_length.c 												\
		print_board.c make_struct.c 											\
		print_warnings.c 														\
		ft_putnbr.c 															\
		bot.c 																	\
		update_board.c

OBJS = $(SRCS:.c=.o)
all: $(NAME)

%.o:%.c
	$gcc -o $@ -c $<

$(NAME): $(OBJS)
	gcc -Wall -Wextra -Werror $(SRCS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
