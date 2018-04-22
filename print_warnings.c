/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_warnings.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukyane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 14:31:16 by alukyane          #+#    #+#             */
/*   Updated: 2018/03/10 14:31:19 by alukyane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_try_again(void)
{
	write(1, YEL, 6);
	write(1, "Number can be between 1 and 3. Try again ;)\n", 44);
	write(1, RES, 5);
}

void	print_angry(void)
{
	write(1, YEL, 6);
	write(1, "BETWEEN 1 and 3 means '1', '2' or '3'!!!\n", 41);
	write(1, RES, 5);
}

void	print_super_angry(void)
{
	write(1, RED, 6);
	write(1, "This game is too HARD for you...\n", 33);
	write(1, "+-+ +-+ +-+ +-+ +-+   +-+ +-+ +-+ +-+ +-+   +-+ +-+ +-+\n", 56);
	write(1, " T   H   I   N   K     A   B   O   U   T     I   T   ! \n", 56);
	write(1, "+-+ +-+ +-+ +-+ +-+   +-+ +-+ +-+ +-+ +-+   +-+ +-+ +-+\n", 56);
	write(1, "Or try again =/\n", 16);
	write(1, RES, 5);
}

void	print_mistake(void)
{
	write(1, YEL, 6);
	write(1, "Number must be less than matches in line\n", 41);
	write(1, RES, 5);
}

void	print_result(int move_number)
{
	if (move_number % 2 == 0)
	{
		write(1, GRN, 6);
		write(1, "***********************\n", 24);
		write(1, "* PLAYER 1 IS WINNER! *\n", 24);
		write(1, "***********************\n", 24);
	}
	else
	{
		write(1, RED, 6);
		write(1, "***********************\n", 24);
		write(1, "* PLAYER 2 IS WINNER! *\n", 24);
		write(1, "***********************\n", 24);
	}
	write(1, RES, 5);
}
