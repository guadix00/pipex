/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gualvare <gualvare@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 13:39:49 by gualvare          #+#    #+#             */
/*   Updated: 2024/07/18 14:26:04 by gualvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_parser(char type, va_list arg, int *count)
{
	if (type == 'c')
		type_c(va_arg(arg, int), count);
	else if (type == 's')
		type_s(va_arg(arg, char *), count);
	else if (type == 'd' || type == 'i')
		type_di(va_arg(arg, int), count);
	else if (type == '%')
		type_c('%', count);
	else if (type == 'u')
		type_u(va_arg(arg, unsigned int), count);
	else if (type == 'x' || type == 'X')
		type_x(va_arg(arg, unsigned int), type, count);
	else if (type == 'p')
		type_p(va_arg(arg, unsigned long), count);
	else
	{
		type_c('%', count);
		type_c(type, count);
	}
	return (0);
}

int	ft_printf(char const *str, ...)
{
	int			i;
	int			count;
	va_list		arg;

	i = 0;
	count = 0;
	va_start(arg, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == '\0')
				return (count);
			format_parser(str[i], arg, &count);
		}
		else
			type_c(str[i], &count);
		i++;
	}
	va_end(arg);
	return (count);
}

/*int main(void)
{
ft_printf("%d\n", ft_printf("probando mi printf:
%c\n %s\n %i\n %d\n %u\n %x\n %p\n %% %\n", 'a', "hola", 42, 42, -42, 42, 42));
printf("%d\n", printf("probando mi printf:
%c\n %s\n %i\n %d\n %u\n %x\n %p\n %% %\n", 'a', "hola", 42, 42, -42, 42, 42));

}*/
