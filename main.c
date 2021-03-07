/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 19:28:47 by gyekim            #+#    #+#             */
/*   Updated: 2021/03/08 01:55:02 by gyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "backtracker.h"

void	ft_atoil(char *str)
{
	int i;

	g_idt = malloc(64);
	i = 0;
	while (i < 31)
	{
		g_idt[i / 2] = str[i] - 48;
		i += 2;
	}
	return ;
}

int		main(int argc, char *argv[])
{
	int i;

	g_n = 4;
	g_error_check = 0;
	ft_atoil(argv[argc - 1]);
	i = 0;
	while (i < g_n)
	{
		g_indexlo[0][0] = i;
		backtrack(0, 0);
		i++;
	}
	if (!g_error_check)
	{
		write(1, "Error\n", 6);
	}
	free(g_idt);
}
