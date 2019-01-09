/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamart <tlamart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 15:16:11 by tlamart           #+#    #+#             */
/*   Updated: 2019/01/09 17:06:06 by tlamart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		backt(char **square, int size, t_list *tetri_lst)
{
	t_list	*tetri;
	char	*sqr;

	if (!tetri_lst)
		return (1);
	sqr = *square;
	tetri = tetri_lst;
	while (*sqr)
	{
		sqr = ft_strchr(sqr, '\n');
		while (tetri && *sqr)
		{
			if (abs_t(*square, tetri->content) && try(sqr, size, tetri->content, 4))
			{
				put_tetri(&sqr, size, tetri->content, 4);
				if (backt(square, size, lst_del(tetri_lst, tetri->content)))
					return (1);
				remove_tetri(&sqr, tetri->content);
			}
			tetri = tetri->next;
		}
		tetri = tetri_lst;
		square++;
	}
	return (0);
}

char	*create_square(int size)
{
	int		i;
	char	*str;
	int		len;
	int		line_size;

	i = 0;
	len = (size) * (size + 1);
	line_size = 0;
	if (!(str = ft_strnew(len)))
		return (NULL);
	while (i < len)
	{
		str[i] = '.';
		if (line_size == size)
		{
			str[i] = '\n';
			line_size = 0;
		}
		else
			line_size++;
		i++;
	}
	return (str);
}

int		optimal_size(int nb)
{
	int		opti;

	opti = 2;
	while ((opti * opti) < (nb * 4))
		opti++;
	return (opti);
}

int		solve(t_list *tetri_lst)
{
	int		square_size;
	char	*square;

	square_size = optimal_size(ft_lstlen(tetri_lst));
	if (!(square = create_square(square_size)))
		return (error());
	while (!backt(&square, square_size, tetri_lst))
	{
		ft_strdel(&square);
		square_size++;
		square = create_square(square_size);
	}
	ft_putstr(square);
	ft_strdel(&square);
	return (0);
}
