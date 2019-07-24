/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bscussel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 17:58:05 by bscussel          #+#    #+#             */
/*   Updated: 2019/07/20 21:19:43 by bscussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		go_back(char **board, t_tet *list, int *xy)
{
	int		x;
	int		y;
	char	**piece;

	y = 0;
	piece = list->piece;
	while (y < list->ht)
	{
		x = 0;
		while (x < list->wd)
		{
			if (piece[y][x] == '#')
				board[xy[1] + y][xy[0] + x] = '.';
			x++;
		}
		y++;
	}
}

void		add_piece(char **board, t_tet *list, int *xy)
{
	int		x;
	int		y;
	char	**piece;
	char	alph;

	x = 0;
	piece = list->piece;
	alph = list->alph;
	while (x < list->wd)
	{
		y = 0;
		while (y < list->ht)
		{
			if (piece[y][x] == '#')
				board[xy[1] + y][xy[0] + x] = alph;
			y++;
		}
		x++;
	}
}

int			safe_check(char **board, t_tet *list, int *xy)
{
	int		x;
	int		y;
	char	**piece;

	x = 0;
	piece = list->piece;
	while (x < list->wd)
	{
		y = 0;
		while (y < list->ht)
		{
			if (piece[y][x] == '#' && board[y + xy[1]][x + xy[0]] != '.')
				return (1);
			y++;
		}
		x++;
	}
	add_piece(board, list, xy);
	return (0);
}

int			free_space_check(char **board, int size, t_tet *list)
{
	int		xy[2];

	if (list == NULL)
		return (0);
	xy[1] = 0;
	while (xy[1] <= (size - list->ht))
	{
		xy[0] = 0;
		while (xy[0] <= (size - list->wd))
		{
			if (safe_check(board, list, xy) == 0)
			{
				if (free_space_check(board, size, list->next) == 0)
					return (0);
				else
					go_back(board, list, xy);
			}
			xy[0]++;
		}
		xy[1]++;
	}
	return (1);
}

void		solve(t_tet *list, char **board, int size)
{
	while (free_space_check(board, size, list) != 0)
	{
		free_board(board, size);
		size++;
		board = make_board(size);
	}
	print_board(board, size);
	free_board(board, size);
	return ;
}
