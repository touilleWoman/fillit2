/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamart <tlamart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 18:39:43 by tlamart           #+#    #+#             */
/*   Updated: 2019/01/10 12:23:50 by tlamart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		create_square(char **square, int size)
{
	int		i;
	char	*str;
	int		len;
	int		line_size;

	i = 0;
	len = (size) * (size + 1);
	line_size = 0;
	if (!(*square = ft_strnew(len)))
		return (0);
	str = *square;
	while (i < len)
	{
		if ((i + 1) % (size + 1) == 0)
			str[i] = '\n';
		else
			str[i] = '.';
		i++;
	}
	return (1);
}

int		solution(int size, t_list *tetri_lst)
{
	char	*square;
	int		status;

	status = 0;
	if (!(create_square(&square, size)))
		return (-1);
	status = backtracking(&square, size, tetri_lst);
	if (status == 1)
	{
		ft_putstr(square);
		ft_strdel(&square);
		return (0);
	}
	ft_strdel(&square);
	return (1);
}

int		fillit(t_list *tetri_lst, int tetri_nbr)
{
	int		square_size;
	int		status;

	square_size = 2;
	while (square_size * square_size < 4 * tetri_nbr)
		square_size++;
	while ((status = solution(square_size, tetri_lst))\
			&& status != -1)
		square_size++;
	if (status == -1)
		return (0);
	return (1);
}
