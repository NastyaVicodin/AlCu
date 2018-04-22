/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukyane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 14:31:16 by alukyane          #+#    #+#             */
/*   Updated: 2018/03/10 14:31:19 by alukyane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	reaction(int i)
{
	if (i < 3)
		print_try_again();
	else if (3 <= i && i <= 5)
		print_angry();
	else
		print_super_angry();
}

int			ask(t_list *str_match)
{
	int		count;
	char	*line;
	int		i;

	get_next_line(0, &line);
	i = 0;
	while (!check_answer(line))
	{
		free(line);
		reaction(i);
		get_next_line(0, &line);
		i++;
	}
	count = ft_atoi(line);
	free(line);
	while (count > find_num(str_match) || count < 1)
	{
		print_mistake();
		get_next_line(0, &line);
		count = ft_atoi(line);
		free(line);
	}
	return (count);
}

static int	get_players(void)
{
	char	*line;
	int		res;

	write(1, "Enter the number of players:\n", 29);
	get_next_line(0, &line);
	while (!check_answer(line) || (res = ft_atoi(line)) > 2)
	{
		free(line);
		write(1, YEL, 6);
		write(1, "Number of players can be 1 or 2.\n", 33);
		write(1, RES, 5);
		get_next_line(0, &line);
	}
	res = ft_atoi(line);
	res == 1 ? write(1, "Bot is Player 2 ;)\n", 19) : 0;
	free(line);
	return (res);
}

static void	my_free(t_list *str_match)
{
	t_list	*tmp;

	while (str_match->prev)
	{
		tmp = str_match->prev;
		free(str_match);
		str_match = tmp;
	}
	free(str_match);
}

int			main(int ac, char **av)
{
	int		move_num;
	t_list	*str_match;

	if (ac > 2)
	{
		write(1, RED, 6) && write(1, "ERROR\n", 6) && write(1, RES, 5);
		return (0);
	}
	str_match = (t_list *)malloc(sizeof(t_list));
	str_match->prev = NULL;
	str_match = make_struct(av[1], str_match);
	if (!(str_match->num) || str_match->num > 10000)
	{
		write(1, RED, 6) && write(1, "ERROR\n", 6) && write(1, RES, 5);
		my_free(str_match);
		return (0);
	}
	ac = get_players();
	move_num = who_first();
	str_match = game_process(str_match, move_num, ac);
	return (0);
}
