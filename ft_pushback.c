/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushback.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bscussel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 17:38:36 by bscussel          #+#    #+#             */
/*   Updated: 2019/07/05 17:40:13 by bscussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tet    *ft_create_elem(char **piece, char alph, int *xy)
{
	t_tet *element;

	if (!(element = malloc(sizeof(t_tet))))
		return (NULL);
	element->piece = piece;
	element->alph = alph;
	element->wd = xy[0];
	element->ht = xy[1];
	element->next = NULL;
	return (element);
}

void    ft_pushback(t_tet **begin_list, char **piece, char alph, int *xy)
{
	t_tet    *tmp;

	if (begin_list && *begin_list)
	{
		tmp = *begin_list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = ft_create_elem(piece, alph, xy);
	}
	else
		*begin_list = ft_create_elem(piece, alph, xy);
}
