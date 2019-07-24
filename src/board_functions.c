/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bscussel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 11:08:43 by bscussel          #+#    #+#             */
/*   Updated: 2019/07/20 21:04:33 by bscussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		free_board(char **board, int board_size)
{
	int		i;

	i = 0;
	while (i < board_size)
	{
		free(board[i]);
		i++;
	}
	free(board);
}

void		print_board(char **board, int board_size)
{
	int		i;

	i = 0;
	while (i < board_size)
	{
		ft_putstr(board[i]);
		ft_putchar('\n');
		i++;
	}
}

char		**make_board(int board_size)
{
	int		i;
	int		j;
	char	**board;

	i = 0;
	board = (char **)malloc(sizeof(char *) * board_size);
	while (i < board_size)
	{
		board[i] = (char *)malloc(sizeof(char) * board_size);
		i++;
	}
	i = 0;
	while (i < board_size)
	{
		j = 0;
		while (j < board_size)
			board[i][j++] = '.';
		board[i][j++] = '\0';
		i++;
	}
	return (board);
}
