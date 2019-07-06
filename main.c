/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bscussel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 17:48:19 by bscussel          #+#    #+#             */
/*   Updated: 2019/07/05 18:17:56 by bscussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		gen_lst(t_tet **tetriminos, char *arg, int np)
{
	t_var		g;
	char		*tmp;
	char		alph;

	g.i = 0;
	g.j = 0;
	alph = 'A';
	while (g.i < np)
	{
		tmp = ft_strsub(arg, g.j, 20);
		gen_piece(tetriminos, tmp, alph++);
		ft_strdel(&tmp);
		g.j += 21;
		g.i++;
	}
}

void		read_file(char **argv, char **pieces, int *np)
{
	t_var		c;

	c.fd = open(argv[1], O_RDONLY);
	pieces[0] = ft_strnew(BUFF_SIZE + 1);
	if (c.fd < 0 || pieces == NULL)
		err_prog("", 1, "ERROR");
	c.rd = read(c.fd, pieces[0], BUFF_SIZE);
	pieces[0][c.rd] = '\0';
	(c.rd < 0) ? err_prog("", 1, "ERROR read_file") : 0;
	(c.rd == 0 && pieces == NULL) ? err_prog("", 1, "ERROR read_file") : 0;
	close(c.fd);
	valid1(pieces[0], c.rd, np);
}

int		main(int argc, char **argv)
{
	char		*arg;
	int			np[1];
	t_tet		*tetriminos;
	char		**board;
	int			board_size;

	arg = ft_strnew(BUFF_SIZE);
	tetriminos = NULL;
	(argc != 2) ? err_prog(argv[0], 0, " [input_file]") : 0;
	read_file(argv, &arg, np);
	gen_lst(&tetriminos, arg, np[0]);
	board_size = ft_sqrt(np[0] * 4);
	board = make_board(board_size);
	//solve_print
	
	ft_putstr("\n_______________\nINITIAL BOARD: ");
	ft_putnbr(board_size);
	ft_putchar('\n');
	print_board(board, board_size);
	ft_putstr("\n_______________\nNUM. PIECES: ");
	ft_putnbr(np[0]);
	ft_putstr("\n_______________\n");
	(np[0] > 26) ? err_prog(argv[0], 1, "ERROR too many pieces") : 0;
	ft_putstr(arg);
	
	end_prog("SUCCESSFULL TERMINATION");
	return (0);
}
