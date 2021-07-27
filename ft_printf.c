/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuklys <vkuklys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 19:04:23 by vkuklys           #+#    #+#             */
/*   Updated: 2021/07/23 16:35:53 by vkuklys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printf	*ft_initialise_tab(t_printf *tab)
{
	tab->length = 0;
	return (tab);
}

static void	ft_handle_alphanumeric(t_printf *tab, char c)
{
	int		di_args;
	int		u_arg;
	char	*s_arg;
	int		fd;

	fd = 1;
	if (c == 'd' || c == 'i')
	{
		di_args = va_arg(tab->args, int);
		ft_putnbr_fd(di_args, 1);
		tab->length += ft_get_digit_count(di_args);
	}
	else if (c == 'u')
	{
		u_arg = va_arg(tab->args, unsigned int);
		tab->length += ft_put_unsigned_int_fd(u_arg, fd);
	}
	else if (c == 's')
	{
		s_arg = va_arg(tab->args, char *);
		if (!s_arg)
			s_arg = "(null)";
		ft_putstr_fd(s_arg, 1);
		tab->length += ft_strlen(s_arg);
	}
}

static void	ft_handle_hexadecimal(t_printf *tab, char c)
{
	unsigned int	xX_args;
	unsigned long	p_arg;
	int				fd;

	fd = 1;
	if (c == 'x')
	{
		xX_args = (unsigned int)va_arg(tab->args, void *);
		tab->length += ft_puthexa_fd(xX_args, fd, 0);
	}
	else if (c == 'X')
	{
		xX_args = (unsigned int)va_arg(tab->args, void *);
		tab->length += ft_puthexa_fd(xX_args, fd, 1);
	}
	else if (c == 'p')
	{
		p_arg = (unsigned long)va_arg(tab->args, void *);
		ft_putstr_fd("0x", 1);
		tab->length += ft_puthexa_fd(p_arg, fd, 0) + 2;
	}
}

static int	ft_handle_format(t_printf *tab, char c, int index)
{
	char	c_arg;

	if (c == 'd' || c == 'i' || c == 'u' || c == 's')
		ft_handle_alphanumeric(tab, c);
	else if (c == 'x' || c == 'X' || c == 'p')
		ft_handle_hexadecimal(tab, c);
	else if (c == '%')
		tab->length += write(1, &c, 1);
	else if (c == 'c')
	{
		c_arg = va_arg(tab->args, int);
		tab->length += write(1, &c_arg, 1);
	}
	return (index + 1);
}

int	ft_printf(const char *fmt, ...)
{
	t_printf	*tab;
	int			i;
	int			len;

	tab = (t_printf *)malloc(sizeof(t_printf));
	if (!tab)
		return (-1);
	ft_initialise_tab(tab);
	va_start(tab->args, fmt);
	len = 0;
	i = 0;
	while (fmt[i] != '\0')
	{
		if (fmt[i] == '%')
			i = ft_handle_format(tab, fmt[i + 1], i);
		else
			len += write(1, &fmt[i], 1);
		i++;
	}
	va_end(tab->args);
	len += tab->length;
	free(tab);
	return (len);
}
