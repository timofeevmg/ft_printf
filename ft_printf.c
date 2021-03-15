/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epilar <epilar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 09:44:37 by epilar            #+#    #+#             */
/*   Updated: 2020/12/14 17:30:04 by epilar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	preparser(const char *format, t_struct *list, va_list *ap, int i)
{
	while (format[i] != '\0')
	{
		if (format[i] != '%')
			list->printed += write(1, &format[i], 1);
		else if (format[i] == '%')
		{
			if (!ft_strchr(ALLSYMBOLS, format[i + 1]))
				break ;
			while (ft_strchr(ALLSYMBOLS, format[i + 1]))
			{
				i++;
				if (ft_strchr("cspdiuxX%", format[i]))
				{
					i = parser((char *)format, list, ap, i) + 2;
					break ;
				}
				else
					i = parser((char *)format, list, ap, i);
			}
			continue;
		}
		i++;
	}
}

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	t_struct	list;
	int			i;

	va_start(ap, format);
	initstruct(format, &list);
	i = 0;
	preparser(format, &list, &ap, i);
	va_end(ap);
	return (list.error ? -1 : list.printed);
}
