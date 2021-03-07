/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracker.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 19:28:47 by gyekim            #+#    #+#             */
/*   Updated: 2021/03/07 23:07:38 by gyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BACKTRACKER_H
# define BACKTRACKER_H

int g_indexlo[4][4];
int g_intarr[4][4];
int g_n;
int g_error_check;
int *g_idt;

int		ft_colcheck(int *idt, int index);
int		ft_rowcheck(int *idt, int index);
void	backtrack(int x, int level);
void	putint(char a);
#endif
