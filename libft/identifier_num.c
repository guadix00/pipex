/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identifier_num.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gualvare <gualvare@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 18:57:51 by gualvare          #+#    #+#             */
/*   Updated: 2024/07/16 13:56:17 by gualvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	type_di(int nb, int *count)
{
	if (nb == -2147483648)
	{
		type_s("-2147483648", count);
		return ;
	}
	if (nb < 0)
	{
		type_c('-', count);
		nb = nb * -1;
	}
	if (nb >= 10)
	{
		type_di((nb / 10), count);
		type_di((nb % 10), count);
	}
	else
		type_c((nb + '0'), count);
}

void	type_u(unsigned int nb, int *count)
{
	if (nb >= 10)
	{
		type_u((nb / 10), count);
	}
	type_c((nb % 10 + '0'), count);
}
