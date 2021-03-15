/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ifpointer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epilar <epilar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 15:00:31 by epilar            #+#    #+#             */
/*   Updated: 2020/12/15 12:29:51 by epilar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void		preparewidth(t_struct *list, unsigned long long num, int rank)
{
	if (num == 0 && list->dot && !list->prec)
		list->width++;
	list->width = (list->width > (rank + 2)) ? (list->width - rank - 2) : 0;
}

static int		toascii(int num)
{
	return ((num > 9) ? (num += 87) : (num += 48));
}

static void		printhex(t_struct *list, unsigned long long num, int rank)
{
	char	*s;
	int		i;
	int		remain;

	if (num == 0 && list->dot && !list->prec)
		return ;
	if (!(s = (char *)malloc(sizeof(char) * rank)))
	{
		list->error = 1;
		return ;
	}
	i = 0;
	while (i <= (rank - 1))
	{
		remain = num % 16;
		s[i] = toascii(remain);
		num /= 16;
		i++;
	}
	while (--i >= 0)
		list->printed += write(1, &s[i], 1);
	free(s);
}

void			ifpointer(t_struct *list, unsigned long long num)
{
	int		rank;
	int		base;

	base = 16;
	rank = (num == 0) ? 1 : getrank(num, base);
	preparewidth(list, num, rank);
	if (list->minus == 0)
	{
		printwidth(list);
		list->printed += write(1, "0x", 2);
		printhex(list, num, rank);
	}
	else
	{
		list->printed += write(1, "0x", 2);
		printhex(list, num, rank);
		printwidth(list);
	}
}
