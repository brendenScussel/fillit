/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_prog.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bscussel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 17:19:55 by bscussel          #+#    #+#             */
/*   Updated: 2019/07/23 14:53:27 by bscussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	err_prog(char *file, int type, char *note)
{
	if (type == 0)
	{
		ft_putstr("usage: ");
		ft_putstr(file);
		ft_putstr(note);
	}
	if (type == 1)
		ft_putstr(note);
	ft_putchar('\n');
	exit(1);
}
