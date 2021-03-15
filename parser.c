/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epilar <epilar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 17:24:43 by epilar            #+#    #+#             */
/*   Updated: 2020/12/12 18:02:36 by epilar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		getparam(const char *format, int pos)
{
	int	num;

	num = 0;
	while (ft_isdigit(format[pos]))
	{
		num = num * 10 + (format[pos] - 48);
		pos++;
	}
	return (num);
}

void	modifiers(const char *format, t_struct *list, va_list *ap, int pos)
{
	while (ft_strchr("-.*0123456789", format[pos]))
	{
		if (format[pos] == '-')
			list->minus = 1;
		if (format[pos] == '0' && !list->minus && !list->width)
			list->zero = 1;
		if (format[pos] == '*')
			list->width = va_arg(*ap, int);
		checknegwidth(list);
		if (ft_isdigit(format[pos]) && !list->width && !list->dot)
			list->width = getparam(format, pos);
		if (format[pos] == '.')
		{
			pos++;
			list->dot = 1;
			if (format[pos] == '*')
				list->prec = va_arg(*ap, int);
			else if (ft_isdigit(format[pos]) && !list->prec)
				list->prec = getparam(format, pos);
			else
				pos--;
		}
		pos++;
		list->i = pos;
	}
}

void	conversions(char c, t_struct *list, va_list *ap)
{
	if (c == 'c')
		ifchar(list, ap);
	if (c == 's')
		ifstring(list, va_arg(*ap, char *));
	if (c == 'p')
		ifpointer(list, va_arg(*ap, unsigned long));
	if (c == 'd' || c == 'i')
		ifdecint(list, va_arg(*ap, int));
	if (c == 'u')
		ifunsign(list, va_arg(*ap, unsigned int));
	if (c == 'x' || c == 'X')
		ifhex(list, va_arg(*ap, unsigned int), c);
	if (c == '%')
		ifpercent(list);
}

int		parser(char *format, t_struct *list, va_list *ap, int pos)
{
	list->i = pos;
	if (!ft_strchr("cspdiuxX%", format[pos]))
		modifiers(format, list, ap, pos);
	else if (ft_strchr("cspdiuxX%", format[pos]))
	{
		conversions(format[pos], list, ap);
		clearstruct(list);
	}
	return (list->i - 1);
}
