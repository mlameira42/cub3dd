/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsilva-n <nsilva-n@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:14:35 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/03/10 13:41:00 by nsilva-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_put_sizet(size_t n, char sign, int fd)
{
	char		*s_hex;
	char		*b_hex;
	size_t		base;

	s_hex = "0123456789abcdef";
	b_hex = "0123456789ABCDEF";
	base = 16;
	if (sign == 'u')
		base = 10;
	if (n > base - 1)
	{
		ft_put_sizet(n / base, sign, fd);
		ft_put_sizet(n % base, sign, fd);
	}
	else
	{
		if (sign == 'x' || sign == 'p')
			ft_putchar_fd(s_hex[n], fd);
		else if (sign == 'X')
			ft_putchar_fd(b_hex[n], fd);
		else
			ft_putchar_fd(n + '0', fd);
	}
}

static int	ft_printf_sizet(size_t n, char sign, int fd)
{
	int	len;

	len = 0;
	if (sign == 'x' || sign == 'X' || sign == 'u')
		n = (unsigned int)n;
	if (!n)
	{
		if (sign == 'p')
			return (ft_putstr_fd("(nil)", fd), 5);
		return (ft_putchar_fd('0', fd), 1);
	}
	if (sign == 'p')
	{
		len = 2;
		ft_putstr_fd("0x", fd);
	}
	ft_put_sizet((size_t)n, sign, fd);
	while (n && len++ >= -10)
	{
		if (sign == 'u')
			n /= 10;
		else
			n /= 16;
	}
	return (len);
}

static int	ft_printf_int(int n, int fd)
{
	int	len;

	len = 0;
	if (n < 0)
		len++;
	ft_putnbr_fd(n, fd);
	if (!n)
		return (1);
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static int	ft_print_triage(const char *to_print, va_list lst, int fd)
{
	int		len;
	char	*str;

	len = 0;
	if (to_print[1] == 'c')
		return (ft_putchar_fd(va_arg(lst, int), fd), 1);
	else if (to_print[1] == 'd' || to_print[1] == 'i')
		len += ft_printf_int(va_arg(lst, int), fd);
	else if (to_print[1] == 'p' || to_print[1] == 'x' || to_print[1] == 'X'
		|| to_print[1] == 'u')
		len += ft_printf_sizet(va_arg(lst, size_t), to_print[1], fd);
	else if (to_print[1] == '%')
		return (ft_putchar_fd('%', fd), 1);
	else if (to_print[1] == 's')
	{
		str = va_arg(lst, char *);
		if (!str)
			return (ft_putstr_fd("(null)", fd), 6);
		len += write(fd, str, ft_strlen(str));
	}
	return (len);
}

int	ft_fprintf(int fd, char *to_print, ...)
{
	va_list	lst;
	int		len;

	len = 0;
	if (!to_print)
		return (-1);
	va_start(lst, to_print);
	while (*to_print)
	{
		if (*to_print == '%' && !to_print[1])
			return (ft_print_triage("%", lst, fd), -1);
		else if (*to_print == '%' && ft_strchr("cspdiuxX%", to_print[1]))
			len += ft_print_triage(to_print++, lst, fd);
		else
		{
			ft_putchar_fd(to_print[0], fd);
			len++;
		}
		to_print++;
	}
	va_end(lst);
	return (len);
}
