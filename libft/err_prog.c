/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_prog.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bscussel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 17:19:55 by bscussel          #+#    #+#             */
/*   Updated: 2019/07/04 17:45:06 by bscussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	err_prog(char *file, int type, char *note)
{
	ft_putstr("\n_______________\n");
	if (type == 0)
	{
		ft_putstr_fd("ussage: ", STDERR_FILENO);
		ft_putstr_fd(file, STDERR_FILENO);
		ft_putstr_fd(note, STDERR_FILENO);
	}
	if (type == 1)
		ft_putstr_fd(note, STDERR_FILENO);
	ft_putstr("\n_______________\n");
	exit(1);
}
