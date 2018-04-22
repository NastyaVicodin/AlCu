/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukyane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 14:31:16 by alukyane          #+#    #+#             */
/*   Updated: 2018/03/10 14:31:19 by alukyane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			who_first(void)
{
	char	*line;
	int		res;

	write(1, "Who will go first?\n1 - Player 1\n2 - Player 2\n", 45);
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
	free(line);
	if (res == 1)
		return (0);
	else
		return (1);
}

static int	calc_count(t_list *str_match, int move_num, int players)
{
	int		count_match;

	if (move_num % 2 == 0 || players == 2)
		count_match = ask(str_match);
	else
		count_match = bot(str_match);
	return (count_match);
}

static void	print_menu(t_list *str_match, int move_num)
{
	if (move_num % 2 == 0)
	{
		write(1, GRN, 6) && write(1, "-------\n", 8);
		write(1, " ROUND \n", 8);
		write(1, "-------\n", 8);
		write(1, RES, 5);
	}
	write(1, MAG, 6) && write(1, "BOARD:\n", 8) && write(1, RES, 5);
	print_board(str_match);
	write(1, MAG, 6);
	if (move_num % 2 == 0)
		write(1, "...Player 1 move...\n", 20);
	else
		write(1, "...Player 2 move...\n", 20);
	write(1, RES, 5);
}

t_list		*game_process(t_list *str_match, int move_num, int players)
{
	int		count_match;
	int		sum;

	sum = sum_matches(str_match);
	while (sum)
	{
		print_menu(str_match, move_num);
		count_match = calc_count(str_match, move_num, players);
		str_match = update_board(str_match, count_match);
		sum -= count_match;
		move_num++;
	}
	print_result(move_num);
	return (str_match);
}

int			bot(t_list *str_match)
{
	int		count;

	while (str_match->next)
		str_match = str_match->next;
	str_match = str_match->prev;
	if (str_match->prev && str_match->prev->num % 4 == 1)
		count = str_match->num % 4 == 0 ? 1 : str_match->num % 4;
	else
	{
		if (str_match->num % 4 == 1)
			count = 1;
		else if (str_match->num % 4 == 0)
			count = 3;
		else
			count = str_match->num % 4 - 1;
	}
	return (count);
}
