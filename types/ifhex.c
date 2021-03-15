/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ifhex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epilar <epilar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 09:33:17 by epilar            #+#    #+#             */
/*   Updated: 2020/12/15 12:23:14 by epilar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void		preparewidth(t_struct *list, int num, int rank)
{
	if (num == 0 && list->dot && !list->prec)
		list->width++;
	list->width = (list->width > rank) ? (list->width - rank) : 0;
}

static int		islower(int c)
{
	return ((c == 'x') ? 1 : 0);
}

static int		toascii(int num, int c)
{
	int		remain;

	if (num > 9)
		remain = (islower(c)) ? (num + 87) : (num + 55);
	else
		remain = num + 48;
	return (remain);
}

static void		printhex(t_struct *list, unsigned long nl, int rank, char c)
{
	char	*s;
	int		i;
	int		remain;

	if (nl == 0 && list->dot && !list->prec)
		return ;
	if (!(s = (char *)malloc(sizeof(char) * rank)))
	{
		list->error = 1;
		return ;
	}
	i = 0;
	while (i <= (rank - 1))
	{
		remain = nl % 16;
		s[i] = toascii(remain, c);
		nl /= 16;
		i++;
	}
	while (--i >= 0)
		list->printed += write(1, &s[i], 1);
	free(s);
}

void			ifhex(t_struct *list, unsigned int num, char c)
{
	unsigned long	nl;
	int				rank;
	int				base;

	base = 16;
	nl = (num < 0) ? (4294967296 + num) : num;
	rank = (num == 0) ? 1 : getrank(num, base);
	rank = (list->prec > rank) ? list->prec : rank;
	preparewidth(list, num, rank);
	if (list->minus == 0)
	{
		printwidth(list);
		printhex(list, nl, rank, c);
	}
	else
	{
		printhex(list, nl, rank, c);
		printwidth(list);
	}
}
