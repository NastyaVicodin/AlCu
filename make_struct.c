/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmizin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 20:59:27 by nmizin            #+#    #+#             */
/*   Updated: 2018/03/10 20:59:33 by nmizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				find_num(t_list *str_match)
{
	int		res;

	while (str_match->next)
		str_match = str_match->next;
	if (str_match->prev)
		str_match = str_match->prev;
	res = str_match->num;
	return (res);
}

t_list			*read_from_file(char *str, t_list *list, t_list *head)
{
	int		fp;
	char	*line;

	fp = open(str, O_RDONLY);
	if (fp > 0)
	{
		while (get_next_line(fp, &line) > 0)
		{
			list->num = f_valid(line) ? ft_atoi(line) : 0;
			if (list->num < 1 || list->num > 10000)
			{
				free(line);
				list->next = NULL;
				return (list);
			}
			list->next = (t_list *)malloc(sizeof(t_list));
			list->next->prev = list;
			list = list->next;
			free(line);
		}
		list->next = NULL;
		return (head);
	}
	return (list);
}

static t_list	*make_next(t_list *list)
{
	list->next = (t_list *)malloc(sizeof(t_list));
	list->next->prev = list;
	list = list->next;
	list->next = NULL;
	return (list);
}

t_list			*make_struct(char *str, t_list *list)
{
	t_list	*head;
	char	*line;

	head = list;
	if (!str)
	{
		write(1, "Enter board's parameters and press ENTER:\n", 42);
		while (get_next_line(0, &line) && *line)
		{
			list->num = f_valid(line) ? ft_atoi(line) : 0;
			if (list->num < 1 || list->num > 10000)
			{
				free(line);
				return (list);
			}
			list = make_next(list);
			free(line);
		}
	}
	else
		return (read_from_file(str, list, head));
	free(line);
	return (head);
}
