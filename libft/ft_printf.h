/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gualvare <gualvare@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 14:11:43 by gualvare          #+#    #+#             */
/*   Updated: 2024/07/18 14:33:42 by gualvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int			ft_printf(char const *str, ...);
int			format_parser(char type, va_list arg, int *count);
int			type_c(int c, int *count);
int			type_s(char *str, int *count);
void		type_di(int nb, int *count);
void		type_u(unsigned int nb, int *count);
void		type_x(unsigned int nb, const char type, int *count);
void		type_p(unsigned long ptr, int *count);
void		type_x_ptr(unsigned long ptr, int *count);

#endif
