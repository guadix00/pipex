/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identifier_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gualvare <gualvare@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 12:47:55 by gualvare          #+#    #+#             */
/*   Updated: 2024/07/18 14:21:26 by gualvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	type_x(unsigned int nb, const char type, int *count)
{
	char	*base;

	if (nb == 0)
		type_c('0', count);
	else
	{
		if (type == 'x')
			base = "0123456789abcdef";
		else
			base = "0123456789ABCDEF";
		if (nb >= 16)
		{
			type_x((nb / 16), type, count);
			type_x((nb % 16), type, count);
		}
		else
			type_c(base[nb], count);
	}
}

void	type_x_ptr(unsigned long ptr, int *count)
{
	char	*base;

	base = "0123456789abcdef";
	if (ptr >= 16)
		type_x_ptr((ptr / 16), count);
	type_c((base[ptr % 16]), count);
}

void	type_p(unsigned long ptr, int *count)
{
	if (ptr == '\0')
	{
		type_s("(nil)", count);
		return ;
	}
	else
	{
		type_s("0x", count);
		type_x_ptr(ptr, count);
	}
}
