/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bscussel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 11:15:59 by bscussel          #+#    #+#             */
/*   Updated: 2019/07/21 15:57:59 by bscussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		*gen_line(char *p_given, int *min_max, int xy)
{
	int		i;
	int		j;
	char	*tmp;

	j = 0;
	i = (min_max[1] * 5) + min_max[0];
	tmp = (char *)malloc(sizeof(char) * xy);
	while (p_given[i] != '#')
	{
		(p_given[i] == '\n') ? min_max[1]++ : 0;
		i++;
	}
	i = (min_max[1] * 5) + min_max[0];
	while (j < xy)
		tmp[j++] = p_given[i++];
	min_max[1]++;
	return (tmp);
}

void		get_mn(char *piece, int *mn_mx)
{
	int		i;
	int		count;

	mn_mx[0] = 0;
	mn_mx[1] = 0;
	i = 0;
	count = 0;
	while (piece[i] != '\0')
	{
		if (count == 0 && piece[i] == '#')
		{
			mn_mx[0] = 0;
			return ;
		}
		if (piece[i] == '#')
		{
			if (mn_mx[0] > count || mn_mx[0] == 0)
				mn_mx[0] = count;
		}
		i++;
		count++;
		(count == 5) ? count = 0 : 0;
	}
}

void		get_ht_wd(char *p, int *xy)
{
	int		i;

	i = 0;
	xy[0] = 0;
	xy[1] = 0;
	while (p[i] != '\0')
	{
		(p[i] == '#' && p[i + 5] != '#') ? xy[0]++ : 0;
		i++;
	}
	i = 0;
	while (i != 20)
	{
		if (p[i] == '#')
		{
			xy[1]++;
			while (p[i] != '\n' && p[i] != '\0')
				i++;
		}
		i++;
	}
}

void		gen_piece(t_tet **tetriminos, char *p_given, char alph)
{
	int		i;
	int		xy[2];
	int		min_max[2];
	char	**piece;

	i = 0;
	get_ht_wd(p_given, xy);
	get_mn(p_given, min_max);
	piece = (char **)malloc(sizeof(char *) * xy[1]);
	while (i < xy[1])
	{
		piece[i] = (char *)malloc(sizeof(char) * xy[0]);
		piece[i] = gen_line(p_given, min_max, xy[0]);
		i++;
	}
	ft_pushback(tetriminos, piece, alph, xy);
}
