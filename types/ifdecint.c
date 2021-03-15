/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ifdecint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epilar <epilar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 15:29:46 by epilar            #+#    #+#             */
/*   Updated: 2020/12/14 17:08:02 by epilar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void		preparewidth(t_struct *list, long num, int rank, int sign)
{
	if (num == 0 && list->dot && !list->prec)
		list->width++;
	list->width = sign ? (list->width - 1) : list->width;
	list->width = (list->width > rank) ? (list->width - rank) : 0;
}

static void		printdecimal(t_struct *list, long num, int rank, int sign)
{
	char	*s;
	int		i;

	if (num == 0 && list->dot && !list->prec)
		return ;
	if (!(s = (char *)malloc(sizeof(char) * (rank))))
	{
		list->error = 1;
		return ;
	}
	i = 0;
	while (i <= (rank - 1))
	{
		s[i] = num % 10 + 48;
		num /= 10;
		i++;
	}
	if (sign)
		list->printed += write(1, "-", 1);
	while (--i >= 0)
		list->printed += write(1, &s[i], 1);
	free(s);
}

void			ifdecint(t_struct *list, long num)
{
	int		sign;
	int		rank;
	int		base;

	base = 10;
	sign = (num < 0) ? 1 : 0;
	num = (num < 0) ? -num : num;
	rank = (num == 0) ? 1 : getrank(num, base);
	rank = (list->prec > rank) ? list->prec : rank;
	preparewidth(list, num, rank, sign);
	if (list->minus == 0)
	{
		if (sign && list->zero && (!list->dot || list->prec < 0))
		{
			list->printed += write(1, "-", 1);
			sign = 0;
		}
		printwidth(list);
		printdecimal(list, num, rank, sign);
	}
	else
	{
		printdecimal(list, num, rank, sign);
		printwidth(list);
	}
}
