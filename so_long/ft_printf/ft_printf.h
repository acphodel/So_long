/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maavalya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 12:54:41 by maavalya          #+#    #+#             */
/*   Updated: 2024/02/07 16:26:01 by maavalya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "stdarg.h"
# include "stdlib.h"
# include "unistd.h"

# define HEX_UP "0123456789ABCDEF"
# define HEX_LOW "0123456789abcdef"

int		ft_printf(const char *format, ...);
void	printf_c(char c, size_t *count);
void	printf_s(char *str, size_t *count);
void	printf_x(unsigned int num, size_t *count);
char	*change_base(unsigned long long num, char *base);
void	printf_upx(unsigned int num, size_t *count);
void	printf_p(void *arg, size_t *count);
void	printf_di(int n, size_t *count);
void	printf_u(unsigned int n, size_t *count);

#endif