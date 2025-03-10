/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maavalya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 12:34:50 by maavalya          #+#    #+#             */
/*   Updated: 2024/02/07 16:24:43 by maavalya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_format(va_list arg_ptr, const char *format, size_t *count)
{
	if (*format == 'c')
		printf_c(va_arg(arg_ptr, int), count);
	else if (*format == 's')
		printf_s(va_arg(arg_ptr, char *), count);
	else if (*format == 'p')
		printf_p(va_arg(arg_ptr, void *), count);
	else if (*format == 'd' || *format == 'i')
		printf_di(va_arg(arg_ptr, int), count);
	else if (*format == 'u')
		printf_u(va_arg(arg_ptr, unsigned int), count);
	else if (*format == 'x')
		printf_x(va_arg(arg_ptr, unsigned int), count);
	else if (*format == 'X')
		printf_upx(va_arg(arg_ptr, unsigned int), count);
	else if (*format == '%')
		printf_c(*format, count);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg_ptr;
	size_t	count;

	if (!format)
		return (0);
	count = 0;
	va_start(arg_ptr, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			check_format(arg_ptr, format, &count);
		}
		else
			printf_c(*format, &count);
		format++;
	}
	va_end(arg_ptr);
	return (count);
}

//#include "limits.h"
//int main(void)
//{
//	ft_printf("    %x", 45);
//}