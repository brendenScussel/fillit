/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bscussel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 16:52:13 by bscussel          #+#    #+#             */
/*   Updated: 2019/07/20 21:37:18 by bscussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUFF_SIZE		666
# define MAX_FD			666

# include "../libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct			s_variables
{
	int					d;
	int					h;
	int					i;
	int					j;
	int					x;
	int					y;
	int					nl;
	int					np;
	int					fd;
	int					rd;
}						t_var;

typedef struct			s_tetris
{
	char				**piece;
	int					wd;
	int					ht;
	char				alph;
	struct s_tetris		*next;
}						t_tet;

void					read_file(char **argv, char **pieces, int *np);
void					valid1(char *p, int rd, int *np);
void					gen_lst(t_tet **teriminos, char *arg, int np);
void					gen_piece(t_tet **teriminos, char *tmp, char alph);
void					ft_pushback(t_tet **begin_list, char **piece, \
		char alph, int *xy);
char					**make_board(int board_size);
void					print_board(char **board, int board_size);
void					free_board(char **board, int board_size);
void					solve(t_tet *list, char **board, int size);

#endif
