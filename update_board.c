/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_board.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukyane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 14:31:16 by alukyane          #+#    #+#             */
/*   Updated: 2018/03/10 14:31:19 by alukyane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				sum_matches(t_list *str_match)
{
	int sum;

	sum = 0;
	while (str_match->next)
	{
		sum += str_match->num;
		str_match = str_match->next;
	}
	return (sum);
}

static void		print_view(int count)
{
	write(1, CYN, 6);
	ft_putnbr(count);
	write(1, " MATCHES", 8);
	write(1, " WERE TAKEN\n", 12);
	write(1, RES, 5);
}

static t_list	*magic(t_list *str_match)
{
	while (str_match->next)
		str_match = str_match->next;
	if (str_match->prev)
		str_match = str_match->prev;
	return (str_match);
}

static t_list	*make_cloud(t_list *str_match)
{
	str_match->prev->next = (t_list *)malloc(sizeof(t_list));
	str_match->prev->next->prev = str_match->prev;
	str_match->prev->next->num = 0;
	str_match->prev->next->next = NULL;
	return (str_match);
}

t_list			*update_board(t_list *str_match, int count)
{
	int		res;
	t_list	*head;

	head = str_match;
	print_view(count);
	str_match = magic(str_match);
	res = str_match->num - count;
	if (res)
		str_match->num = res;
	else
	{
		free(str_match->next);
		if (str_match->prev)
		{
			str_match = make_cloud(str_match);
			free(str_match);
		}
		else
		{
			free(str_match);
			head = NULL;
		}
	}
	return (head);
}
