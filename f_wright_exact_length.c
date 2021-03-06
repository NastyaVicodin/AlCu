/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_wright_exact_length.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmizin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 20:31:28 by nmizin            #+#    #+#             */
/*   Updated: 2018/02/25 20:31:35 by nmizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	f_w_e_l(char c, int length)
{
	int		i;
	char	buff[length];

	i = length;
	while (length)
		buff[--length] = c;
	buff[i] = '\0';
	write(1, &buff, i);
	return (i);
}
