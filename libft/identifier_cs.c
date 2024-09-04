/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identifier_cs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gualvare <gualvare@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 16:05:43 by gualvare          #+#    #+#             */
/*   Updated: 2024/07/14 17:53:57 by gualvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	type_c(int c, int *count)
{
	if (write(1, &c, 1) != 1)
	{
		*count = -1;
		return (*count);
	}
	(*count)++;
	return (*count);
}

int	type_s(char *s, int *count)
{
	int	i;

	if (s == NULL)
	{
		return (type_s("(null)", count));
	}
	i = 0;
	while (s[i])
	{
		if (type_c(s[i], count) == -1)
			return (*count);
		i++;
	}
	return (*count);
}
