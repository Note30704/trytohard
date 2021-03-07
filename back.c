/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 19:28:47 by gyekim            #+#    #+#             */
/*   Updated: 2021/03/08 01:56:27 by gyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "backtracker.h"

void	putint(char a)
{
	write(1, &a, 1);
}

void	printarr(void)
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			putint(g_intarr[j][i] + 48);
			putint(32);
			j++;
		}
		putint('\n');
		i++;
	}
}

int		trackcheck(int x, int level)
{
	int i;

	i = 0;
	while (i < x)
	{
		if (g_indexlo[i][level] == g_indexlo[x][level])
			return (1);
		i++;
	}
	i = 0;
	while (i < level)
	{
		if (g_indexlo[x][level] == g_indexlo[x][i])
			return (1);
		i++;
	}
	g_intarr[x][g_indexlo[x][level]] = 4 - level;
	return (0);
}

void	mergetrack(int level)
{
	int i;

	if (level < 3)
	{
		i = 0 - 1;
		while (++i < g_n)
		{
			g_indexlo[0][level + 1] = i;
			backtrack(0, level + 1);
			if (g_error_check)
			{
				i = g_n;
			}
		}
	}
	else
	{
		i = 0 - 1;
		while (++i < 4)
		{
			if (!ft_colcheck(g_idt, i))
				return ;
			if (!ft_rowcheck(g_idt, i + 8))
				return ;
		}
		printarr();
		g_error_check = 1;
	}
}

void	backtrack(int x, int level)
{
	int i;

	if (trackcheck(x, level))
		return ;
	if (x == g_n - 1)
	{
		mergetrack(level);
		return ;
	}
	i = 0;
	while (i < g_n)
	{
		g_indexlo[x + 1][level] = i;
		backtrack(x + 1, level);
		i++;
	}
}
