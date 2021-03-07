/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 19:28:47 by gyekim            #+#    #+#             */
/*   Updated: 2021/03/07 23:07:07 by gyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "backtracker.h"

int		ft_colcheck_rev(int index)
{
	int temp;
	int i;
	int sum;

	sum = 1;
	temp = 0;
	i = 4;
	while (g_intarr[index][--i] != 4)
	{
		if (g_intarr[index][i] > temp)
		{
			temp = g_intarr[index][i];
			sum++;
		}
	}
	if (sum != g_idt[index + 4])
		return (0);
	return (1);
}

int		ft_colcheck(int *g_idt, int index)
{
	int temp;
	int i;
	int sum;

	i = 0 - 1;
	sum = 1;
	temp = 0;
	while (g_intarr[index][++i] != 4)
	{
		if (g_intarr[index][i] > temp)
		{
			temp = g_intarr[index][i];
			sum++;
		}
	}
	if (sum != g_idt[index])
		return (0);
	return (ft_colcheck_rev(index));
}

int		ft_rowcheck_rev(int index)
{
	int temp;
	int i;
	int sum;

	sum = 1;
	temp = 0;
	i = 3;
	while (g_intarr[i][index % 8] != 4)
	{
		if (g_intarr[i][index % 8] > temp)
		{
			temp = g_intarr[i][index % 8];
			sum++;
		}
		i--;
	}
	if (sum != g_idt[index + 4])
		return (0);
	return (1);
}

int		ft_rowcheck(int *g_idt, int index)
{
	int temp;
	int i;
	int sum;

	i = 0;
	sum = 1;
	temp = 0;
	while (g_intarr[i][index % 8] != 4)
	{
		if (g_intarr[i][index % 8] > temp)
		{
			temp = g_intarr[i][index % 8];
			sum++;
		}
		i++;
	}
	if (sum != g_idt[index])
		return (0);
	return (ft_rowcheck_rev(index));
}
