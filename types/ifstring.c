/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ifstring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epilar <epilar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 16:26:52 by epilar            #+#    #+#             */
/*   Updated: 2020/12/12 16:46:21 by epilar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void		printstring(t_struct *list, char *s, int len)
{
	if (list->dot && !list->prec)
		return ;
	while (len > 0)
	{
		list->printed += write(1, &(*s), 1);
		s++;
		len--;
	}
}

void			ifstring(t_struct *list, char *s)
{
	int		len;

	if (s == NULL)
		s = "(null)";
	len = ft_strlen(s);
	if (list->prec >= 0 && list->dot)
		len = (len >= list->prec) ? list->prec : len;
	list->width = list->width - len;
	if (list->minus == 0)
	{
		printwidth(list);
		printstring(list, s, len);
	}
	else
	{
		printstring(list, s, len);
		printwidth(list);
	}
}
